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

	static const unsigned short s_L0Count;

	static const unsigned short s_L0Offset;

	static const unsigned short s_L1Count;

	static const unsigned short s_L1Offset;
						
	static const unsigned short s_specialityPerYeer;

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

	Class(const Class&) = default;

	Class& operator =(const Class&) = default;

	Class(Class&&) = default;

	Class& operator =(Class&&) = default;

private:

	Class(CLASS_YEAR, CLASS_SPE, CLASS_GROUP, short);

};

/* ---------------------------------------------------------------------------------
										Definition
--------------------------------------------------------------------------------- */

const unsigned short Class::s_L0Count = 8;

const unsigned short Class::s_L0Offset = 0;

const unsigned short Class::s_L1Count = 8;

const unsigned short Class::s_L1Offset = Class::s_L0Count + Class::s_L0Offset;
		
const unsigned short Class::s_specialityPerYeer = 4;

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