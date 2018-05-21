#pragma once

/* ---------------------------------------------------------------------------------
										Include
--------------------------------------------------------------------------------- */

#include <vector>
#include <map>

/* ---------------------------------------------------------------------------------
										Declaration
--------------------------------------------------------------------------------- */

template <typename T, typename F, typename G>
void variadic_map_emplace(std::map<T,std::map<F,G>>&);

template <typename T, typename F, typename G, typename First, typename Second, typename... Args>
void variadic_map_emplace(std::map<T,std::map<F,G>>&, First&&, Second&&, Args&&...);

class Teacher
{

public:

	static const std::vector<Teacher> s_teachers;

public:

	enum TEACHERS_TYPE
	{
		MATHS,
		PHYSICS,
		COMPUTER,
		CHEMISTRY,
		ENGLISH,
		FRENCH
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

	const TEACHERS_TYPE m_type;

	const TEACHERS_TIME m_time;

	const std::string m_name;

	std::map<TEACHERS_DAY, std::map<TEACHERS_SLOT, bool>> m_availability;

public:

	void display() const;

private:

	template <typename... Args>
	Teacher(TEACHERS_TYPE, TEACHERS_TIME, const std::string&, Args&&...);

};

/* ---------------------------------------------------------------------------------
										Definition
--------------------------------------------------------------------------------- */

template <typename T, typename F, typename G>
void variadic_map_emplace(std::map<T,std::map<F,G>>&) {}

template <typename T, typename F, typename G, typename First, typename Second, typename... Args>
void variadic_map_emplace(std::map<T,std::map<F,G>>& v, First&& first, Second&& second, Args&&... args)
{
	v[std::forward<First>(first)][std::forward<Second>(second)] = false;
	variadic_map_emplace(v, std::forward<Args>(args)...);
}

const std::vector<Teacher> Teacher::s_teachers
{
	Teacher(MATHS, FULL, "A", MONDAY, SLOT_0, TUESDAY, SLOT_0, WEDNESDAY, SLOT_0, THURSDAY, SLOT_0, FRIDAY, SLOT_0), 
    Teacher(MATHS, FULL, "B", MONDAY, SLOT_2, MONDAY, SLOT_3, TUESDAY, SLOT_2, TUESDAY, SLOT_3, FRIDAY, SLOT_2, FRIDAY, SLOT_3), 
    Teacher(MATHS, FULL, "C", FRIDAY, SLOT_2), 
 
    Teacher(PHYSICS, FULL, "A", MONDAY, SLOT_0, TUESDAY, SLOT_0, WEDNESDAY, SLOT_0, THURSDAY, SLOT_0, FRIDAY, SLOT_0), 
    Teacher(PHYSICS, FULL, "B", MONDAY, SLOT_2, MONDAY, SLOT_3, TUESDAY, SLOT_2, TUESDAY, SLOT_3, WEDNESDAY, SLOT_2, WEDNESDAY, SLOT_3, THURSDAY, SLOT_2, THURSDAY, SLOT_3, FRIDAY, SLOT_2, FRIDAY, SLOT_3), 
    Teacher(PHYSICS, HALF, "C", MONDAY, SLOT_0, MONDAY, SLOT_1, MONDAY, SLOT_2, MONDAY, SLOT_3, TUESDAY, SLOT_0, TUESDAY, SLOT_1, TUESDAY, SLOT_2, TUESDAY, SLOT_3, WEDNESDAY, SLOT_0, WEDNESDAY, SLOT_1, WEDNESDAY, SLOT_2, WEDNESDAY, SLOT_3, THURSDAY, SLOT_2, THURSDAY, SLOT_3, FRIDAY, SLOT_0, FRIDAY, SLOT_1), 
    Teacher(PHYSICS, HOUR, "D"), 
 
    Teacher(COMPUTER, FULL, "A"), 
    Teacher(COMPUTER, FULL, "B"), 
    Teacher(COMPUTER, HALF, "C"), 
    Teacher(COMPUTER, HOUR, "D", MONDAY, SLOT_0, MONDAY, SLOT_1, MONDAY, SLOT_2, MONDAY, SLOT_3, FRIDAY, SLOT_0, FRIDAY, SLOT_1, FRIDAY, SLOT_2, FRIDAY, SLOT_3), 
 
    Teacher(CHEMISTRY, FULL, "A", MONDAY, SLOT_0, TUESDAY, SLOT_0, WEDNESDAY, SLOT_0, THURSDAY, SLOT_0, FRIDAY, SLOT_0), 
    Teacher(CHEMISTRY, FULL, "B"), 
    Teacher(CHEMISTRY, HALF, "C"), 
    Teacher(CHEMISTRY, HALF, "D", MONDAY, SLOT_0, TUESDAY, SLOT_0, WEDNESDAY, SLOT_0, THURSDAY, SLOT_0, FRIDAY, SLOT_0), 
 
    Teacher(ENGLISH, FULL, "A"), 
    Teacher(ENGLISH, FULL, "B"), 
    Teacher(ENGLISH, HALF, "C"), 
    Teacher(ENGLISH, FULL, "D"), 
 
    Teacher(FRENCH, FULL, "A"), 
    Teacher(FRENCH, FULL, "B"), 
    Teacher(FRENCH, HALF, "C"), 
    Teacher(FRENCH, HALF, "D"), 
    Teacher(FRENCH, HOUR, "E")
};

template <typename... Args>
Teacher::Teacher(TEACHERS_TYPE _type, TEACHERS_TIME _time, const std::string& _name, Args&&... _notAvailable)
	: 	m_type(_type),
		m_time(_time),
		m_name(_name)
{
	for(int i=0 ; i<5 ; ++i)
	{
		for(int j=0 ; j<4 ; ++j)
		{
			m_availability[(TEACHERS_DAY)i][(TEACHERS_SLOT)j] = true;
		}
	}
	variadic_map_emplace(m_availability, std::forward<Args>(_notAvailable)...);
}

void Teacher::display() const
{
	std::string type;
	switch(m_type)
	{
		case MATHS: type = "MATHS"; break;
		case PHYSICS: type = "PHYSICS"; break;
		case COMPUTER: type = "COMPUTER"; break;
		case CHEMISTRY: type = "CHEMISTRY"; break;
		case ENGLISH: type = "ENGLISH"; break;
		case FRENCH: type = "FRENCH"; break;
	}
	std::string time;
	switch(m_time)
	{
		case FULL: time = "FULL"; break;
		case HALF: time = "HALF"; break;
		case HOUR: time = "HOUR"; break;
	}
	std::cout << "Teacher {" << type << "} : " << m_name << " " << time << " => \n";
	for(int i=0 ; i<5 ; ++i)
	{
		std::string day;
		switch((TEACHERS_DAY)i)
		{
			case MONDAY: day = "MONDAY"; break;
			case TUESDAY: day = "TUESDAY"; break;
			case WEDNESDAY: day = "WEDNESDAY"; break;
			case THURSDAY: day = "THURSDAY"; break;
			case FRIDAY: day = "FRIDAY"; break;
		}
		std::cout << "\t" << day << " :";
		for(int j=0 ; j<4 ; ++j)
		{
			std::string slot;
			switch((TEACHERS_SLOT)j)
			{
				case SLOT_0: slot = "8h30-10h00"; break;
				case SLOT_1: slot = "10h15-11h45"; break;
				case SLOT_2: slot = "12h45-14h15"; break;
				case SLOT_3: slot = "14h30-16h00"; break;
			}
			if(!m_availability.at((TEACHERS_DAY)i).at((TEACHERS_SLOT)j))
			{
				std::cout << " " << slot << "(false),";
			}
		}
		std::cout << std::endl;;
	}
} 