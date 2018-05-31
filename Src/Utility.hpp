#pragma once

/* ---------------------------------------------------------------------------------
										Include
--------------------------------------------------------------------------------- */

#include <vector>

#include "Subject.hpp"
#include "Teacher.hpp"
#include "Room.hpp"
#include "Lesson.hpp"

/* ---------------------------------------------------------------------------------
										Declaration
--------------------------------------------------------------------------------- */

template<typename T>
std::vector<T> shuffleVector(const std::vector<T>&);

const Teacher& randTeacher();

const Room& randRoom();

int countTeacher(const Teacher&, const std::vector<Lesson>&);

int countRoom(const Room&, const std::vector<Lesson>&);

/* ---------------------------------------------------------------------------------
										Definition
--------------------------------------------------------------------------------- */

template< typename T >
std::vector< T > shuffleVector(const std::vector< T >& _vec)
{
	std::vector< size_t > value;
	for(size_t i=0 ; i<_vec.size() ; ++i)	
	{
		value.push_back(i);
	}

	std::vector< T > result;
	while(!value.empty())
	{
		unsigned rand = globalRandomGenerator->random(0, value.size());
		result.push_back(_vec[value[rand]]);
		value.erase(value.begin()+rand);
	}

	return result;
}


const Teacher& randTeacher()
{
	const Teacher::TEACHERS_TYPE type = static_cast< Teacher::TEACHERS_TYPE >(globalRandomGenerator->random(0, Teacher::TYPE_SIZE));
	return Teacher::s_teachers.at(type)[globalRandomGenerator->random(0, Teacher::s_teachers.at(type).size())];
}

const Room& randRoom()
{
	const Room::ROOM_TYPE type = static_cast< Room::ROOM_TYPE >(globalRandomGenerator->random(0, Room::TYPE_SIZE));
	return Room::s_rooms.at(type)[globalRandomGenerator->random(0, Room::s_rooms.at(type).size())];
}

int countTeacher(const Teacher& _teacher, const std::vector<Lesson>& _liste)
{
	int result = 0; 
	for(const Lesson& lesson : _liste)
	{
		if(lesson.m_teacher == &_teacher)
		{
			++result;
		}	
	}
	return result;
}

int countRoom(const Room& _room, const std::vector<Lesson>& _liste)
{
	int result = 0; 
	for(const Lesson& lesson : _liste)
	{
		if(lesson.m_room == &_room)
		{
			++result;
		}	
	}
	return result;
}

int countClass(const Class& _class, const std::vector<Lesson>& _liste)
{
	int result = 0;
	for(const Lesson& lesson : _liste)
	{
		if(lesson.m_class == &_class)
		{
			++result;
		}
	}
	return result;
}

std::string dayToString(Lesson::LESSON_DAY _day)
{
	switch(_day)
	{
		case Lesson::MONDAY : return "MONDAY";
		case Lesson::TUESDAY : return "TUESDAY";
		case Lesson::WEDNESDAY : return "WEDNESDAY";
		case Lesson::THURSDAY : return "THURSDAY";
		case Lesson::FRIDAY : return "FRIDAY";
		case Lesson::DAY_SIZE : return "";
	}
	return "";
}

std::string slotToString(Lesson::LESSON_SLOT _slot)
{
	switch(_slot)
	{
		case Lesson::SLOT_0 : return "8h30-10h00";
		case Lesson::SLOT_1 : return "10h15-11h45";
		case Lesson::SLOT_2 : return "12h45-14h15";
		case Lesson::SLOT_3 : return "14h30-16h";
		case Lesson::SLOT_SIZE : return "";
	}
	return "";
}