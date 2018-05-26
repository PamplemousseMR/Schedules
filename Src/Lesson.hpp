#pragma once

/* ---------------------------------------------------------------------------------
										Include
--------------------------------------------------------------------------------- */

#include <vector>
#include <string>

/* ---------------------------------------------------------------------------------
										Declaration
--------------------------------------------------------------------------------- */

class Lesson
{

public:

	enum LESSON_DAY
	{
		MONDAY,
		TUESDAY,
		WEDNESDAY,
		THURSDAY,
		FRIDAY,
		DAY_SIZE
	};

	enum LESSON_SLOT
	{
		SLOT_0,
		SLOT_1,
		SLOT_2,
		SLOT_3,
		SLOT_SIZE
	};


public:

	static const float SLOT_INTERVAL;

public:

	const Subject& m_subject;

	const Teacher& m_teacher;

	const Room& m_room;
	
	const Class& m_class;
	
	const Subject::SUBJECT_MODALITY m_modality;

public:

	Lesson(const Subject&, const Teacher&, const Room&, const Class&, Subject::SUBJECT_MODALITY);

	Lesson(const Lesson&) = default;

	Lesson& operator =(const Lesson&) = default;

	Lesson(Lesson&&) = default;

	Lesson& operator =(Lesson&&) = default;

	friend std::ostream& operator <<(std::ostream& _o, const Lesson& _l)
	{
		std::string mod;
		switch (_l.m_modality)
		{ 
			case Subject::CM: mod = "CM"; break; 
			case Subject::CI: mod = "CI"; break; 
			case Subject::TD: mod = "TD"; break; 
			case Subject::TP: mod = "TP"; break; 
			case Subject::MODALITY_SIZE: mod = ""; break; 
		} 
		return _o << "{ " << "[" << mod << "] " << _l.m_subject << " " << _l.m_room << " " << _l.m_teacher << " " << _l.m_class << " }";
	}

};

/* ---------------------------------------------------------------------------------
										Definition
--------------------------------------------------------------------------------- */

const float Lesson::SLOT_INTERVAL = 1.5f;

Lesson::Lesson(const Subject& _subject, const Teacher& _teacher, const Room& _room,
								const Class& _classList, Subject::SUBJECT_MODALITY _modality)
	: 	m_subject(_subject),
		m_teacher(_teacher),
		m_room(_room),
		m_class(_classList),
		m_modality(_modality)
{
}