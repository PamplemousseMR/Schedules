#pragma once

/* ---------------------------------------------------------------------------------
										Include
--------------------------------------------------------------------------------- */

#include <vector>

/* ---------------------------------------------------------------------------------
										Declaration
--------------------------------------------------------------------------------- */

class Class
{

public:

	static const std::vector<Class> s_class;

public:

	enum CLASS_YEAR
	{
		L0,
		L1
	};

	enum CLASS_SPE
	{
		SPE_A,
		SPE_B,
		SPE_C,
		SPE_D
	};

	enum CLASS_GROUP
	{
		A,
		B
	};

public:

	const CLASS_YEAR m_year;

	const CLASS_SPE m_spe;

	const CLASS_GROUP m_group;

	const short m_students;

public:

	void display() const;

private:

	Class(CLASS_YEAR, CLASS_SPE, CLASS_GROUP, short);

};

/* ---------------------------------------------------------------------------------
										Definition
--------------------------------------------------------------------------------- */

const std::vector<Class> Class::s_class
{
	Class(L0, SPE_A, A, 20),
	Class(L0, SPE_A, B, 20),
	Class(L0, SPE_B, A, 20),
	Class(L0, SPE_B, B, 20),
	Class(L0, SPE_C, A, 20),
	Class(L0, SPE_C, B, 20),
	Class(L0, SPE_D, A, 20),
	Class(L0, SPE_D, B, 20),
	Class(L1, SPE_A, A, 20),
	Class(L1, SPE_A, B, 20),
	Class(L1, SPE_B, A, 20),
	Class(L1, SPE_B, B, 20),
	Class(L1, SPE_C, A, 20),
	Class(L1, SPE_C, B, 20),
	Class(L1, SPE_D, A, 20),
	Class(L1, SPE_D, B, 20)
};

Class::Class(CLASS_YEAR _year, CLASS_SPE _spe, CLASS_GROUP _group, short _students)
	:	m_year(_year),
		m_spe(_spe),
		m_group(_group),
		m_students(_students)
{
}

void Class::display() const
{
	std::string year;
	switch(m_year)
	{
		case L0: year = "L0"; break;
		case L1: year = "L1"; break;
	}
	
	std::string spe;
	switch(m_spe)
	{
		case SPE_A: spe = "SPE_A"; break;
		case SPE_B: spe = "SPE_B"; break;
		case SPE_C: spe = "SPE_C"; break;
		case SPE_D: spe = "SPE_D"; break;
	}
	
	std::string group;
	switch(m_group)
	{
		case A: group = "A"; break;
		case B: group = "B"; break;
	}

	std::cout << "Class {";
	std::cout << "\n\tYear : " << year;
	std::cout << "\n\tSpe : " << spe;
	std::cout << "\n\tGroup : " << group;
	std::cout << "\n\tStudents : " << m_students;
	std::cout << "}" << std::endl;
} 