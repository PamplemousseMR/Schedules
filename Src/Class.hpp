#pragma once

/* ---------------------------------------------------------------------------------
										Include
--------------------------------------------------------------------------------- */

#include <vector>
#include <map>
#include <tuple>

/* ---------------------------------------------------------------------------------
										Declaration
--------------------------------------------------------------------------------- */

class Class
{

public:

	enum CLASS_YEAR
	{
		L0,
		L1,
		YEAR_SIZE
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

	typedef std::tuple< const std::map< const Class::CLASS_YEAR, const Class >, const std::map< const Class::CLASS_YEAR, const std::map< const Class::CLASS_SPE, Class > >, const std::map< const  Class::CLASS_YEAR, const std::map< const  Class::CLASS_SPE, std::map< const Class::CLASS_GROUP, const Class > > > > ContainerType;

public:

	static const ContainerType s_classes;

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
		    case YEAR_SIZE: year = ""; break; 
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

const Class::ContainerType Class::s_classes
{
	{ 
		{L0, Class(L0, SPE_ALL, ALL)},
		{L1, Class(L1, SPE_ALL, ALL)}
	},
	{
		{ L0,
			{
				{SPE_A, Class(L0, SPE_A, ALL)},
				{SPE_B, Class(L0, SPE_B, ALL)},
				{SPE_C, Class(L0, SPE_C, ALL)},
				{SPE_D, Class(L0, SPE_D, ALL)}
			}
		},
		{ L1,
			{
				{SPE_A, Class(L1, SPE_A, ALL)},
				{SPE_B, Class(L1, SPE_B, ALL)},
				{SPE_C, Class(L1, SPE_C, ALL)},
				{SPE_D, Class(L1, SPE_D, ALL)}
			}
		}
	},
	{
		{ L0,
			{
				{ SPE_A, 
					{
						{A, Class(L0, SPE_A, A)},
						{B, Class(L0, SPE_A, B)}
					}
				},
				{ SPE_B, 
					{
						{A, Class(L0, SPE_B, A)},
						{B, Class(L0, SPE_B, B)}
					}
				},
				{ SPE_C, 
					{
						{A, Class(L0, SPE_C, A)},
						{B, Class(L0, SPE_C, B)}
					}
				},
				{ SPE_D, 
					{
						{A, Class(L0, SPE_D, A)},
						{B, Class(L0, SPE_D, B)}
					}
				}
			}
		},
		{ L1,
			{
				{ SPE_A, 
					{
						{A, Class(L1, SPE_A, A)},
						{B, Class(L1, SPE_A, B)}
					}
				},
				{ SPE_B, 
					{
						{A, Class(L1, SPE_B, A)},
						{B, Class(L1, SPE_B, B)}
					}
				},
				{ SPE_C, 
					{
						{A, Class(L1, SPE_C, A)},
						{B, Class(L1, SPE_C, B)}
					}
				},
				{ SPE_D, 
					{
						{A, Class(L1, SPE_D, A)},
						{B, Class(L1, SPE_D, B)}
					}
				}
			}
		}
	}
};

Class::Class(CLASS_YEAR _year, CLASS_SPE _spe, CLASS_GROUP _group)
	:	m_year(_year),
		m_spe(_spe),
		m_group(_group)
{
}