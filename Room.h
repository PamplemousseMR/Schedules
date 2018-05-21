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

	void display() const;

private:

	Room(ROOM_TYPE, unsigned short);

private:

	const ROOM_TYPE m_type;

	const unsigned short m_capacity;

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

void Room::display() const
{
	std::string type;
	switch(m_type)
	{
		case ROOM: type = "ROOM"; break;
		case AMPHI: type = "AMPHI"; break;
		case LANGUAGE: type = "LANGUAGE"; break;
		case COMPUTER: type = "COMPUTER"; break;
		case LABORATORY: type = "LABORATORY"; break;
	}
	std::cout << "Room {" << type << "} : " << m_capacity << std::endl;
}
