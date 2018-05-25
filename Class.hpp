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

	static const std::vector<Class> s_classes;

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
		SPE_D,
		SPE_ALL
	};

	enum CLASS_GROUP
	{
		A,
		B,
		ALL
	};

public:

	const CLASS_YEAR m_year;

	const CLASS_SPE m_spe;

	const CLASS_GROUP m_group;

public:

	Class(const Class&) = default;

	Class& operator =(const Class&) = delete;

	Class(Class&&) = default;

	Class& operator =(Class&&) = default;

	friend std::ostream& operator <<(std::ostream& _o, const Class& _c)
	{
		std::string year; 
		switch(_c.m_year) 
		{ 
		    case L0: year = "L0"; break; 
		    case L1: year = "L1"; break; 
		} 
		   
		std::string spe; 
		switch(_c.m_spe) 
		{ 
		    case SPE_A: spe = "_SPE_A"; break; 
		    case SPE_B: spe = "_SPE_B"; break; 
		    case SPE_C: spe = "_SPE_C"; break; 
		    case SPE_D: spe = "_SPE_D"; break; 
		    case SPE_ALL: spe = ""; break;
		} 
		   
		std::string group; 
		switch(_c.m_group) 
		{ 
		    case A: group = "_A"; break; 
		    case B: group = "_B"; break; 
		    case ALL: group = ""; break;
		} 
		 
		return _o << "Class_" << year << spe << group;
	}

private:

	Class(CLASS_YEAR, CLASS_SPE, CLASS_GROUP);

};

/* ---------------------------------------------------------------------------------
										Definition
--------------------------------------------------------------------------------- */

const unsigned short Class::s_L0Count = 8;

const unsigned short Class::s_L0Offset = 0;

const unsigned short Class::s_L1Count = 8;

const unsigned short Class::s_L1Offset = Class::s_L0Count + Class::s_L0Offset;
		
const unsigned short Class::s_specialityPerYeer = 4;

const std::vector<Class> Class::s_classes
{
	Class(L0, SPE_ALL, ALL),
	Class(L1, SPE_ALL, ALL),
	
	Class(L0, SPE_A, ALL),
	Class(L0, SPE_B, ALL),
	Class(L0, SPE_C, ALL),
	Class(L0, SPE_D, ALL),
	Class(L1, SPE_A, ALL),
	Class(L1, SPE_B, ALL),
	Class(L1, SPE_C, ALL),
	Class(L1, SPE_D, ALL),
	
	Class(L0, SPE_A, A),
	Class(L0, SPE_A, B),
	Class(L0, SPE_B, A),
	Class(L0, SPE_B, B),
	Class(L0, SPE_C, A),
	Class(L0, SPE_C, B),
	Class(L0, SPE_D, A),
	Class(L0, SPE_D, B),
	Class(L1, SPE_A, A),
	Class(L1, SPE_A, B),
	Class(L1, SPE_B, A),
	Class(L1, SPE_B, B),
	Class(L1, SPE_C, A),
	Class(L1, SPE_C, B),
	Class(L1, SPE_D, A),
	Class(L1, SPE_D, B)
};

Class::Class(CLASS_YEAR _year, CLASS_SPE _spe, CLASS_GROUP _group)
	:	m_year(_year),
		m_spe(_spe),
		m_group(_group)
{
}