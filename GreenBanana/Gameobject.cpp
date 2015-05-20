#include "Gameobject.h"

std::string Gameobject::Serialize()
{
	std::stringstream ss;
	ss << GetType();
	ss << ",";
	ss << GetName();
	ss << ",";
	ss << GetPosition().x;
	ss << ",";
	ss << GetPosition().y;
	ss << ",";
	ss << GetworldSpace();
	ss << ",";
	ss << GetIsStatic();
	ss << std::endl;

	return ss.str();
}