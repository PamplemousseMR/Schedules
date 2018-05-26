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

	const std::string m_name;

public:

	Room(const Room&) = default;

	Room& operator =(const Room&) = delete;

	Room(Room&&) = default;

	Room& operator =(Room&&) = default;
	
	friend std::ostream& operator <<(std::ostream& _o, const Room& _t)
	{
		std::string type; 
		switch(_t.m_type) 
		{ 
			case ROOM: type = "ROOM_"; break; 
			case AMPHI: type = "AMPHI_"; break; 
			case LANGUAGE: type = "LANGUAGE_"; break; 
			case COMPUTER: type = "COMPUTER_"; break; 
			case LABORATORY: type = "LABORATORY_"; break;
		} 
		return _o << "Room_" << type << _t.m_name;
	}

private:

	Room(ROOM_TYPE, const std::string&);

};

/* ---------------------------------------------------------------------------------
										Definition
--------------------------------------------------------------------------------- */

const std::vector<Room> Room::s_rooms
{
	Room(AMPHI, "A"),
	Room(AMPHI, "B"),

	Room(ROOM, "A"),
	Room(ROOM, "B"),
	Room(ROOM, "C"),
	Room(ROOM, "D"),
	Room(ROOM, "E"),

	Room(LANGUAGE, "A"),
	Room(LANGUAGE, "B"),
	Room(LANGUAGE, "C"),
	Room(LANGUAGE, "D"),
	Room(LANGUAGE, "E"),
	Room(LANGUAGE, "F"),
	Room(LANGUAGE, "G"),

	Room(COMPUTER, "A"),
	Room(COMPUTER, "B"),

	Room(LABORATORY, "A"),
	Room(LABORATORY, "B")
};

Room::Room(ROOM_TYPE _type, const std::string& _name)
	:	m_type(_type),
		m_name(_name)
{
}