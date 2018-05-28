#pragma once

/* ---------------------------------------------------------------------------------
										Include
--------------------------------------------------------------------------------- */

#include <vector>
#include <map>

/* ---------------------------------------------------------------------------------
										Declaration
--------------------------------------------------------------------------------- */

template < typename T, typename F, typename G >
static void variadic_map_emplace(std::map< T,std::map< F,G > >&);

template < typename T, typename F, typename G, typename First, typename Second, typename... Args >
static void variadic_map_emplace(std::map< T,std::map< F,G > >&, First&&, Second&&, Args&&...);

class Teacher
{

public:

	enum TEACHERS_TYPE
	{
		MATHS,
		PHYSICS,
		COMPUTER_SCIENCE,
		CHEMISTRY,
		ENGLISH,
		FRENCH,
		TYPE_SIZE
	};

	enum TEACHERS_TIME
	{
		FULL,
		HALF,
		HOUR
	};

	enum TEACHERS_DAY
	{
		MONDAY,
		TUESDAY,
		WEDNESDAY,
		THURSDAY,
		FRIDAY
	};


	enum TEACHERS_SLOT
	{
		SLOT_0,
		SLOT_1,
		SLOT_2,
		SLOT_3
	};

public:

	static const std::map< const TEACHERS_TYPE, const std::vector< Teacher > > s_teachers;
	
	static const short s_totalTeachers;
	
	static const float s_nbHoursFull;
	
	static const float s_nbHoursHalf;

public:

	const TEACHERS_TYPE m_type;

	const TEACHERS_TIME m_time;

	const std::string m_name;

	const std::map< TEACHERS_DAY, std::map< TEACHERS_SLOT, bool > > m_availability;

public:

	Teacher(const Teacher&) = default;

	Teacher& operator =(const Teacher&) = delete;

	Teacher(Teacher&&) = default;

	Teacher& operator =(Teacher&&) = default;

	friend std::ostream& operator <<(std::ostream& _o, const Teacher& _t)
	{
		std::string type; 
		switch(_t.m_type) 
		{ 
			case MATHS: type = "MATHS_"; break; 
			case PHYSICS: type = "PHYSICS_"; break; 
			case COMPUTER_SCIENCE: type = "COMPUTER_SCIENCE_"; break; 
			case CHEMISTRY: type = "CHEMISTRY_"; break; 
			case ENGLISH: type = "ENGLISH_"; break; 
			case FRENCH: type = "FRENCH_"; break; 
			case TYPE_SIZE: type = ""; break;
		} 
		return _o << "Teacher_" << type << _t.m_name;
	}

private:

	template < typename... Args >
	Teacher(TEACHERS_TYPE, TEACHERS_TIME, const std::string&, Args&&...);

};

/* ---------------------------------------------------------------------------------
										Definition
--------------------------------------------------------------------------------- */

template < typename T, typename F, typename G >
void variadic_map_emplace(std::map< T,std::map< F,G > >&) {}

template < typename T, typename F, typename G, typename First, typename Second, typename... Args >
void variadic_map_emplace(std::map< T,std::map< F,G > >& v, First&& first, Second&& second, Args&&... args)
{
	v[std::forward< First >(first)][std::forward< Second >(second)] = false;
	variadic_map_emplace(v, std::forward< Args >(args)...);
}

const std::map< const Teacher::TEACHERS_TYPE, const std::vector< Teacher > > Teacher::s_teachers
{
	{ MATHS,
		{	
			Teacher(MATHS, FULL, "A", MONDAY, SLOT_0, TUESDAY, SLOT_0, WEDNESDAY, SLOT_0, THURSDAY, SLOT_0, FRIDAY, SLOT_0), 
	    	Teacher(MATHS, FULL, "B", MONDAY, SLOT_2, MONDAY, SLOT_3, TUESDAY, SLOT_2, TUESDAY, SLOT_3, FRIDAY, SLOT_2, FRIDAY, SLOT_3), 
	    	Teacher(MATHS, FULL, "C", FRIDAY, SLOT_2)
	    }
    },
    { PHYSICS,
		{	
			Teacher(PHYSICS, FULL, "A", MONDAY, SLOT_0, TUESDAY, SLOT_0, WEDNESDAY, SLOT_0, THURSDAY, SLOT_0, FRIDAY, SLOT_0), 
		    Teacher(PHYSICS, FULL, "B", MONDAY, SLOT_2, MONDAY, SLOT_3, TUESDAY, SLOT_2, TUESDAY, SLOT_3, WEDNESDAY, SLOT_2, WEDNESDAY, SLOT_3, THURSDAY, SLOT_2, THURSDAY, SLOT_3, FRIDAY, SLOT_2, FRIDAY, SLOT_3), 
		    Teacher(PHYSICS, HALF, "C", MONDAY, SLOT_0, MONDAY, SLOT_1, MONDAY, SLOT_2, MONDAY, SLOT_3, TUESDAY, SLOT_0, TUESDAY, SLOT_1, TUESDAY, SLOT_2, TUESDAY, SLOT_3, WEDNESDAY, SLOT_0, WEDNESDAY, SLOT_1, WEDNESDAY, SLOT_2, WEDNESDAY, SLOT_3, THURSDAY, SLOT_2, THURSDAY, SLOT_3, FRIDAY, SLOT_0, FRIDAY, SLOT_1), 
		    Teacher(PHYSICS, HOUR, "D")
	    }
    } ,
    { COMPUTER_SCIENCE,
		{	
			Teacher(COMPUTER_SCIENCE, FULL, "A"),  
		    Teacher(COMPUTER_SCIENCE, FULL, "B"),  
		    Teacher(COMPUTER_SCIENCE, HALF, "C"),  
		    Teacher(COMPUTER_SCIENCE, HOUR, "D", MONDAY, SLOT_0, MONDAY, SLOT_1, MONDAY, SLOT_2, MONDAY, SLOT_3, FRIDAY, SLOT_0, FRIDAY, SLOT_1, FRIDAY, SLOT_2, FRIDAY, SLOT_3),  
	    }
    } ,
 
    { CHEMISTRY,
		{	
			Teacher(CHEMISTRY, FULL, "A", MONDAY, SLOT_0, TUESDAY, SLOT_0, WEDNESDAY, SLOT_0, THURSDAY, SLOT_0, FRIDAY, SLOT_0), 
		    Teacher(CHEMISTRY, FULL, "B"), 
		    Teacher(CHEMISTRY, HALF, "C"), 
		    Teacher(CHEMISTRY, HALF, "D", MONDAY, SLOT_0, TUESDAY, SLOT_0, WEDNESDAY, SLOT_0, THURSDAY, SLOT_0, FRIDAY, SLOT_0)
	    }
    },
    { ENGLISH,
		{	
			Teacher(ENGLISH, FULL, "A"), 
		    Teacher(ENGLISH, FULL, "B"), 
		    Teacher(ENGLISH, HALF, "C"), 
		    Teacher(ENGLISH, FULL, "D")
	    }
    },
    { FRENCH,
		{	
			Teacher(FRENCH, FULL, "A"), 
		    Teacher(FRENCH, FULL, "B"), 
		    Teacher(FRENCH, HALF, "C"), 
		    Teacher(FRENCH, HALF, "D"), 
		    Teacher(FRENCH, HOUR, "E")
	    }
    }
};

const short Teacher::s_totalTeachers = 24; 
 
const float Teacher::s_nbHoursFull = 384.f; 

const float Teacher::s_nbHoursHalf = 192.f; 

template < typename... Args >
Teacher::Teacher(TEACHERS_TYPE _type, TEACHERS_TIME _time, const std::string& _name, Args&&... _notAvailable)
	: 	m_type(_type),
		m_time(_time),
		m_name(_name)
{
	auto& availability = const_cast< std::map<TEACHERS_DAY, std::map<TEACHERS_SLOT, bool> >& >(m_availability);
	for(int i=0 ; i<5 ; ++i)
	{
		for(int j=0 ; j<4 ; ++j)
		{
			availability[(TEACHERS_DAY)i][(TEACHERS_SLOT)j] = true;
		}
	}
	variadic_map_emplace(availability, std::forward<Args>(_notAvailable)...);
}