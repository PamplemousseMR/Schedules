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
	switch (_subject.m_type){
		case Subject::MATHS :
			return Teacher::s_teachers.at(Teacher::MATHS)[globalRandomGenerator->random(0, Teacher::s_teachers.at(Teacher::MATHS).size())];
		break;
		case Subject::PHYSICS :
			return Teacher::s_teachers.at(Teacher::PHYSICS)[globalRandomGenerator->random(0, Teacher::s_teachers.at(Teacher::PHYSICS).size())];
		break;
		case Subject::COMPUTER_SCIENCE :
			return Teacher::s_teachers.at(Teacher::COMPUTER_SCIENCE)[globalRandomGenerator->random(0, Teacher::s_teachers.at(Teacher::COMPUTER_SCIENCE).size())];
		break;
		case Subject::CHEMISTRY :
			return Teacher::s_teachers.at(Teacher::CHEMISTRY)[globalRandomGenerator->random(0, Teacher::s_teachers.at(Teacher::CHEMISTRY).size())];
		break;
		case Subject::ENGLISH :
			return Teacher::s_teachers.at(Teacher::ENGLISH)[globalRandomGenerator->random(0, Teacher::s_teachers.at(Teacher::ENGLISH).size())];
		break;
		case Subject::FRENCH :
			return Teacher::s_teachers.at(Teacher::FRENCH)[globalRandomGenerator->random(0, Teacher::s_teachers.at(Teacher::FRENCH).size())];
		break;
		case Subject::UNDEFINED :
		default :
			Teacher::TEACHERS_TYPE rand = static_cast< Teacher::TEACHERS_TYPE >(globalRandomGenerator->random(0, Teacher::TYPE_SIZE));
			return Teacher::s_teachers.at(rand)[globalRandomGenerator->random(0, Teacher::s_teachers.at(rand).size())];
		break;
	}
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