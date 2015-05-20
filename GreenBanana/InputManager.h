#ifndef IPUTMANAGER_H
#define IPUTMANAGER_H
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <map>



class InputMapper
{

public:
	static InputMapper &shared_instance() { static InputMapper game; return game; }

	std::map<std::string, bool> curState;
	std::map<std::string, bool> prevState;

private:
	InputMapper()
	{

	}
};

#endif