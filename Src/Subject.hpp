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
	
	static const std::vector< Subject > s_subjects;

public:
	
	enum SUBJECT_SPECIALITY
	{
		CHEMICAL,
		COMPUTER,
		GEOPHYSICAL,
		OILNGAS ,
		COMMUN
	};

	enum SUBJECT_SEMESTER
	{
		S1,
		S2,
		S3,
		S4
	};

	enum SUBJECT_TYPE
	{
		MATHS,
		PHYSICS,
		COMPUTER_SCIENCE,
		CHEMISTRY,
		ENGLISH,
		FRENCH,
		UNDEFINED
	};

	enum SUBJECT_MODALITY
	{
		CM,
		CI,
		TD,
		TP,
		MODALITY_SIZE
	};

public:
	
	const std::string m_name;

	const SUBJECT_SEMESTER m_semester;

	const SUBJECT_SPECIALITY m_speciality;

	const SUBJECT_TYPE m_type;

	const std::map<SUBJECT_MODALITY, unsigned short> m_modality;

public:

	Subject(const Subject&) = default;

	Subject& operator =(const Subject&) = delete;

	Subject(Subject&&) = default;

	Subject& operator =(Subject&&) = default;
	
	friend std::ostream& operator <<(std::ostream& _o, const Subject& _t)
	{
		std::string spe; 
		switch(_t.m_speciality) 
		{ 
			case CHEMICAL: spe = "_CHEMICAL"; break; 
			case COMPUTER: spe = "_COMPUTER"; break; 
			case GEOPHYSICAL: spe = "_GEOPHYSICAL"; break; 
			case OILNGAS: spe = "_OILNGAS"; break; 
			case COMMUN: spe = "_COMMUN"; break; 
		} 
		return _o << _t.m_name << spe;
	}

private:

	Subject(const std::string&, SUBJECT_SEMESTER, SUBJECT_SPECIALITY, SUBJECT_TYPE, unsigned short, unsigned short, unsigned short, unsigned short);

};

/* ---------------------------------------------------------------------------------
										Definition
--------------------------------------------------------------------------------- */

const std::vector<Subject> Subject::s_subjects
{
	Subject("UE101", S1, COMMUN, MATHS, 0, 42, 0, 0),
	Subject("UE102", S1, COMMUN, PHYSICS, 0, 42, 0, 0),
	Subject("UE103", S1, COMMUN, CHEMISTRY, 0, 42, 0, 0),
	Subject("UE104", S1, COMMUN, COMPUTER_SCIENCE, 0, 56, 0, 0),
	Subject("UE105", S1, COMMUN, FRENCH, 0, 42, 0, 42),
	Subject("UE106", S1, COMMUN, ENGLISH, 0, 70, 0, 42),
	Subject("UE107", S1, COMMUN, UNDEFINED, 0, 0, 0, 14),

	Subject("UE201_An", S2, COMMUN, MATHS, 10, 32, 0, 0),
	Subject("UE201_Al", S2, COMMUN, MATHS, 10, 32, 0, 0),
	Subject("UE202", S2, COMMUN, PHYSICS, 14, 28, 0, 21),
	Subject("UE203", S2, COMMUN, COMPUTER_SCIENCE, 10, 32, 0, 21),
	Subject("UE204", S2, COMMUN, CHEMISTRY, 14, 28, 0, 21),
	Subject("UE205", S2, COMMUN, FRENCH, 0, 42, 0, 0),
	Subject("UE206", S2, COMMUN, ENGLISH, 0, 42, 0, 0),
	Subject("UE207", S2, COMMUN, UNDEFINED, 0, 0, 8, 28),

	Subject("UE301", S3, COMMUN, MATHS, 30, 0, 42, 0),
	Subject("UE302_M", S3, COMMUN, PHYSICS, 21, 0, 21, 0),
	Subject("UE302_T", S3, COMMUN, PHYSICS, 18, 0, 18, 0),
	Subject("UE302_F", S3, COMMUN, PHYSICS, 9, 0, 9, 0),
	Subject("UE303", S3, COMMUN, COMPUTER_SCIENCE, 12, 0, 12, 12),
	Subject("UE304_F", S3, COMMUN, FRENCH, 0, 36, 0, 0),
	Subject("UE304_E", S3, COMMUN, ENGLISH, 0, 36, 0, 0),

	Subject("UE305a", S3, CHEMICAL, CHEMISTRY, 30, 0, 21, 21),
	Subject("UE306", S3, CHEMICAL, CHEMISTRY, 15, 0, 15, 15),

	Subject("UE307", S3, COMPUTER, COMPUTER_SCIENCE, 21, 0, 21, 12),
	Subject("UE308", S3, COMPUTER, COMPUTER_SCIENCE, 15, 0, 0, 21),

	Subject("UE305b", S3, GEOPHYSICAL, CHEMISTRY, 30, 0, 21, 21),
	Subject("UE309", S3, GEOPHYSICAL, PHYSICS, 0, 30, 0, 0),

	Subject("UE305c", S3, OILNGAS, CHEMISTRY, 30, 0, 21, 21),
	Subject("UE310", S3, OILNGAS, PHYSICS, 15, 0, 9, 6),

	Subject("UE401", S4, COMMUN, MATHS, 30, 0, 42, 0),
	Subject("UE402", S4, COMMUN, PHYSICS, 36, 0, 36, 0),
	Subject("UE403", S4, COMMUN, COMPUTER_SCIENCE, 12, 0, 12, 12),
	Subject("UE404_F", S4, COMMUN, FRENCH, 0, 36, 0, 36),
	Subject("UE404_E", S4, COMMUN, ENGLISH, 0, 36, 0, 36),
	Subject("UE405", S4, COMMUN, UNDEFINED,6, 6, 0, 6),

	Subject("UE406a", S4, CHEMICAL, CHEMISTRY, 30, 0, 30, 21),
	Subject("UE407", S4, CHEMICAL, CHEMISTRY, 15, 0, 15, 15),

	Subject("UE408", S4, COMPUTER, COMPUTER_SCIENCE, 21, 0, 21, 12),
	Subject("UE409", S4, COMPUTER, COMPUTER_SCIENCE, 18, 0, 18, 12),

	Subject("UE4062", S4, GEOPHYSICAL, CHEMISTRY, 30, 0, 30, 21),
	Subject("UE410", S4, GEOPHYSICAL, PHYSICS, 0, 30, 0, 0),

	Subject("UE406c", S4, OILNGAS, CHEMISTRY, 30, 0, 30, 21),
	Subject("UE411", S4, OILNGAS, PHYSICS, 15, 0, 6, 9)
};

Subject::Subject(const std::string& _name, SUBJECT_SEMESTER _semester, SUBJECT_SPECIALITY _speciality, SUBJECT_TYPE _type, 
		unsigned short _cm, unsigned short _ci, unsigned short _td, unsigned short _tp)
	:	m_name(_name),
		m_semester(_semester),
		m_speciality(_speciality),
		m_type(_type)
{
	auto& mod = const_cast< std::map<SUBJECT_MODALITY, unsigned short>& >(m_modality);
	mod[CM] = _cm;
	mod[CI] = _ci;
	mod[TD] = _td;
	mod[TP] = _tp;
}