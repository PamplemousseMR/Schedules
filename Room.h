#pragma once

/* ---------------------------------------------------------------------------------
										Include
--------------------------------------------------------------------------------- */

#include <vector>

/* ---------------------------------------------------------------------------------
										Declaration
--------------------------------------------------------------------------------- */

class Room
{

public:

	static const std::vector<Room> s_rooms;

public:

	enum ROOM_TYPE
	{
		ROOM,
		AMPHI,
		LANGUAGE,
		COMPUTER,
		LABORATORY
	};

public:

	const ROOM_TYPE m_type;

	const unsigned short m_capacity;

public:

	Room(const Room&) = default;

	Room& operator =(const Room&) = default;

	Room(Room&&) = default;

	Room& operator =(Room&&) = default;

private:

	Room(ROOM_TYPE, unsigned short);

};

/* ---------------------------------------------------------------------------------
										Definition
--------------------------------------------------------------------------------- */

const std::vector<Room> Room::s_rooms
{
	Room(AMPHI, 160),
	Room(AMPHI, 160),

	Room(ROOM, 40),
	Room(ROOM, 40),
	Room(ROOM, 40),
	Room(ROOM, 40),
	Room(ROOM, 40),

	Room(LANGUAGE, 20),
	Room(LANGUAGE, 20),
	Room(LANGUAGE, 20),
	Room(LANGUAGE, 20),
	Room(LANGUAGE, 20),
	Room(LANGUAGE, 20),
	Room(LANGUAGE, 20),

	Room(COMPUTER, 20),
	Room(COMPUTER, 20),

	Room(LABORATORY, 20),
	Room(LABORATORY, 20)
};

Room::Room(ROOM_TYPE _type, unsigned short _capacity)
	:	m_type(_type),
		m_capacity(_capacity)
{
}