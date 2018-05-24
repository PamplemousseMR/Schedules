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

	static const float SLOT_INTERVAL;

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

	Lesson(const Subject&, const Teacher&, const Room&, std::initializer_list<Class>);

	Lesson(const Lesson&) = default;

	Lesson& operator =(const Lesson&) = default;

	Lesson(Lesson&&) = default;

	Lesson& operator =(Lesson&&) = default;

public:

	const Subject& m_subject;

	const Teacher& m_teacher;

	const Room& m_room;
	
	const std::vector<Class> m_class;

};

/* ---------------------------------------------------------------------------------
										Definition
--------------------------------------------------------------------------------- */

const float Lesson::SLOT_INTERVAL = 1.5f;

Lesson::Lesson(const Subject& _subject, const Teacher& _teacher, const Room& _room,
								std::initializer_list<Class> _classList)
	: 	m_subject(_subject),
		m_teacher(_teacher),
		m_room(_room),
		m_class(_classList.begin(), _classList.end())
{
}