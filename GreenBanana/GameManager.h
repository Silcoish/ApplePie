#include "UpgradeData.h"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

class GameManager
{

public:
	static GameManager &shared_instance() { static GameManager game; return game; }
	UpgradeData upgradeData;
	sf::Vector2f cameraPos;
	sf::RenderWindow* rw;

private:
	GameManager()
	{
	
	}
};