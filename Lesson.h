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

	static const unsigned short DAY_SIZE;

	static const float SLOT_INTERVAL;

	static const unsigned short SLOT_SIZE;

public:

	enum LESSON_DAY
	{
		MONDAY,
		TUESDAY,
		WEDNESDAY,
		THURSDAY,
		FRIDAY
	};

	enum LESSON_SLOT
	{
		SLOT_0,
		SLOT_1,
		SLOT_2,
		SLOT_3
	};

public:

	Lesson(const std::string&, const Teacher&, const Room&, std::initializer_list<Class>);

	Lesson(const Lesson&) = default;

	Lesson& operator =(const Lesson&) = default;

	Lesson(Lesson&&) = default;

	Lesson& operator =(Lesson&&) = default;

public:

	const std::string m_UEname;

	const Teacher& m_teacher;

	const Room& m_room;
	
	const std::vector<Class> m_class;

};

/* ---------------------------------------------------------------------------------
										Definition
--------------------------------------------------------------------------------- */

const unsigned short Lesson::DAY_SIZE = 5;

const float Lesson::SLOT_INTERVAL = 1.5f;

const unsigned short Lesson::SLOT_SIZE = 4;

Lesson::Lesson(const std::string& _ueName, const Teacher& _teacher, const Room& _room,
								std::initializer_list<Class> _classList)
	: 	m_UEname(_ueName),
		m_teacher(_teacher),
		m_room(_room),
		m_class(_classList.begin(), _classList.end())
{
}