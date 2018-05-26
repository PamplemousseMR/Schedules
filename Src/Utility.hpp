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

const Teacher& randTeacher(const Subject&);

const Room& randRoom(const Subject&, Subject::SUBJECT_MODALITY);

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


const Teacher& randTeacher(const Subject& _subject)
{
	int min = 0, max = Teacher::s_teachers.size();
	switch (_subject.m_type){
		case Subject::MATHS :
			max = 3;
		break;
		case Subject::PHYSICS :
			min = 3;
			max = 7;
		break;
		case Subject::COMPUTER_SCIENCE :
			min = 7;
			max = 11;
		break;
		case Subject::CHEMISTRY :
			min = 11;
			max = 15;
		break;
		case Subject::ENGLISH :
			min = 15;
			max = 19;
		break;
		case Subject::FRENCH :
			min = 19;
		break;
		case Subject::UNDEFINED :
		break;
	}
	return Teacher::s_teachers[globalRandomGenerator->random(min, max)];
}

const Room& randRoom(const Subject& _subject, Subject::SUBJECT_MODALITY _subMod)
{
	int min = 0, max = Room::s_rooms.size();
	switch(_subMod) 
	{
		case Subject::TP :
			switch(_subject.m_type)
			{
				case Subject::COMPUTER_SCIENCE :
					min = 14;
					max = 16;
				break;
				case Subject::PHYSICS :
				case Subject::CHEMISTRY :
					min = 16;
					max = 18;
				break;
				case Subject::ENGLISH :
				case Subject::FRENCH :
					min = 7;
					max = 14;
				break;
				case Subject::MATHS :
				case Subject::UNDEFINED :
				break;
			}
		break;
		case Subject::TD :
			max = 7;
		break;
		case Subject::CI :
		case Subject::CM :
			if(_subject.m_speciality == Subject::COMMUN)
			{
				max = 2;
			}
			else
			{
				max = 7;
			}
		break;
		case Subject::MODALITY_SIZE :
		break;
	}
	return Room::s_rooms[globalRandomGenerator->random(min, max)];
}

int countTeacher(const Teacher& _teacher, const std::vector<Lesson>& _liste)
{
	int result = 0; 
	for(const Lesson& lesson : _liste)
	{
		if(&lesson.m_teacher == &_teacher)
		{
			result += 1;
		}	
	}
	return result;
}

int countRoom(const Room& _room, const std::vector<Lesson>& _liste)
{
	int result = 0; 
	for(const Lesson& lesson : _liste)
	{
		if(&lesson.m_room == &_room)
		{
			result += 1;
		}	
	}
	return result;
}