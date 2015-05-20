#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "UpgradeData.h"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

class GameManager
{

public:
	static GameManager &shared_instance() { static GameManager game; return game; }
	UpgradeData upgradeData;
	bool editor = true;
	float cameraMoveSpeed = 200.0f;
	sf::Vector2f cameraPos;
	sf::RenderWindow* rw;

private:
	GameManager()
	{
	
	}
};

#endif