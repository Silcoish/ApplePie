#include "Level.h"

Level::Level(std::string filePath)
{
	SetFilePath(filePath);
	Parse();
}

Level::~Level()
{
	
}

void Level::Update(float dt)
{
	//editor shit
	if (editor)
	{
		std::cout << "Mouse X Y: " << sf::Mouse::getPosition().x << ", " << sf::Mouse::getPosition().y << std::endl;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			Player* player = new Player("player", "player", sf::Mouse::getPosition().x, sf::Mouse::getPosition().y, 1, 0);
			ObjectsInScene.push_back(player);
		}
	}
	
	//Update all the objects in the scene
	for (auto it = ObjectsInScene.begin(); it != ObjectsInScene.end(); ++it)
	{
		(*it)->Update(dt);
	}

}
