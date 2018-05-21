#pragma once

/* ---------------------------------------------------------------------------------
										Include
--------------------------------------------------------------------------------- */

#include <vector>
#include <string>

/* ---------------------------------------------------------------------------------
										Declaration
--------------------------------------------------------------------------------- */

class Subject
{

public:
	
	static const std::vector<Subject> s_subjects;

public:
	
	enum SUBJECT_SPECIALITY
	{
		COMMUN,
		CHEMICAL,
		COMPUTER,
		GEOPHYSICAL,
		OILNGAS
	};

	enum SUBJECT_SEMESTER
	{
		S1,
		S2,
		S3,
		S4
	};

public:

	void display() const;

private:

	Subject(const std::string&, SUBJECT_SEMESTER, SUBJECT_SPECIALITY, unsigned short, unsigned short, unsigned short, unsigned short);
	
private:
	
	const std::string m_name;

	const SUBJECT_SEMESTER m_semester;

	const SUBJECT_SPECIALITY m_speciality;

	const unsigned short m_nbHoursCM;

	const unsigned short m_nbHoursCI;

	const unsigned short m_nbHoursTD;

	const unsigned short m_nbHoursTP;

};

/* ---------------------------------------------------------------------------------
										Definition
--------------------------------------------------------------------------------- */

const std::vector<Subject> Subject::s_subjects
{
	Subject("UE101", S1, COMMUN, 0, 42, 0, 0),
	Subject("UE102", S1, COMMUN, 0, 42, 0, 0),
	Subject("UE103", S1, COMMUN, 0, 42, 0, 0),
	Subject("UE104", S1, COMMUN, 0, 56, 0, 0),
	Subject("UE105", S1, COMMUN, 0, 42, 0, 42),
	Subject("UE106", S1, COMMUN, 0, 70, 0, 42),
	Subject("UE107", S1, COMMUN, 0, 0, 0, 14),

	Subject("UE201_An", S2, COMMUN, 10, 32, 0, 0),
	Subject("UE201_Al", S2, COMMUN, 10, 32, 0, 0),
	Subject("UE202", S2, COMMUN, 14, 28, 0, 21),
	Subject("UE203", S2, COMMUN, 10, 32, 0, 21),
	Subject("UE204", S2, COMMUN, 14, 28, 0, 21),
	Subject("UE205", S2, COMMUN, 0, 42, 0, 0),
	Subject("UE206", S2, COMMUN, 0, 42, 0, 0),
	Subject("UE207", S2, COMMUN, 0, 0, 8, 28),

	Subject("UE301", S3, COMMUN, 30, 0, 42, 0),
	Subject("UE302_M", S3, COMMUN, 21, 0, 21, 0),
	Subject("UE302_T", S3, COMMUN, 18, 0, 18, 0),
	Subject("UE302_F", S3, COMMUN, 9, 0, 9, 0),
	Subject("UE303", S3, COMMUN, 12, 0, 12, 12),
	Subject("UE304_F", S3, COMMUN, 0, 36, 0, 0),
	Subject("UE304_E", S3, COMMUN, 0, 36, 0, 0),

	Subject("UE305a", S3, CHEMICAL, 30, 0, 21, 21),
	Subject("UE306", S3, CHEMICAL, 15, 0, 15, 15),

	Subject("UE307", S3, COMPUTER, 21, 0, 21, 12),
	Subject("UE308", S3, COMPUTER, 15, 0, 0, 21),

	Subject("UE305b", S3, GEOPHYSICAL, 30, 0, 21, 21),
	Subject("UE309", S3, GEOPHYSICAL, 0, 30, 0, 0),

	Subject("UE305c", S3, OILNGAS, 30, 0, 21, 21),
	Subject("UE310", S3, OILNGAS, 15, 0, 9, 6),

	Subject("UE401", S4, COMMUN, 30, 0, 42, 0),
	Subject("UE402", S4, COMMUN, 36, 0, 36, 0),
	Subject("UE403", S4, COMMUN, 12, 0, 12, 12),
	Subject("UE404_F", S4, COMMUN, 0, 36, 0, 36),
	Subject("UE404_E", S4, COMMUN, 0, 36, 0, 36),
	Subject("UE405", S4, COMMUN, 6, 6, 0, 6),

	Subject("UE406a", S4, CHEMICAL, 30, 0, 30, 21),
	Subject("UE407", S4, CHEMICAL, 15, 0, 15, 15),

	Subject("UE408", S4, COMPUTER, 21, 0, 21, 12),
	Subject("UE409", S4, COMPUTER, 18, 0, 18, 12),

	Subject("UE4062", S4, GEOPHYSICAL, 30, 0, 30, 21),
	Subject("UE410", S4, GEOPHYSICAL, 0, 30, 0, 0),

	Subject("UE406c", S4, OILNGAS, 30, 0, 30, 21),
	Subject("UE411", S4, OILNGAS, 15, 0, 6, 9)
};

Subject::Subject(const std::string& _name, SUBJECT_SEMESTER _semester, SUBJECT_SPECIALITY _speciality, unsigned short _cm,
				 unsigned short _ci, unsigned short _td, unsigned short _tp)
	:	m_name(_name),
		m_semester(_semester),
		m_speciality(_speciality),
		m_nbHoursCM(_cm),
		m_nbHoursCI(_ci),
		m_nbHoursTD(_td),
		m_nbHoursTP(_tp)
{
}
 
void Subject::display() const
{
	std::string semester;
	switch(m_semester)
	{
		case S1: semester = "S1"; break;
		case S2: semester = "S2"; break;
		case S3: semester = "S3"; break;
		case S4: semester = "S4"; break;
	}
	
	std::string speciality;
	switch(m_speciality)
	{
		case COMMUN: speciality = "COMMUN"; break;
		case CHEMICAL: speciality = "CHEMICAL"; break;
		case COMPUTER: speciality = "COMPUTER"; break;
		case GEOPHYSICAL: speciality = "GEOPHYSICAL"; break;
		case OILNGAS: speciality = "OILNGAS"; break;
	}
	
	std::cout << "Subject {" << m_name << "  " << semester << " " << speciality << "} =>" ;
	std::cout << "\n\tCM : " << m_nbHoursCM << "H";
	std::cout << "\n\tCI : " << m_nbHoursCI << "H";
	std::cout << "\n\tTD : " << m_nbHoursTD << "H";
	std::cout << "\n\tTP : " << m_nbHoursTP << "H" << std::endl;
} 