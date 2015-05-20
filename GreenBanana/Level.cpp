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
		//sf::Vector2f pos = GameManager::shared_instance().rw->mapPixelToCoords(sf::Mouse::getPosition(*GameManager::shared_instance().rw) - GameManager::shared_instance().rw->getPosition());
		sf::Vector2f pos = GameManager::shared_instance().rw->mapPixelToCoords(sf::Mouse::getPosition(*GameManager::shared_instance().rw));
		if(currentObject != nullptr) currentObject->SetPosition(pos);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			Player* player = new Player("player", "player", pos.x-80, pos.y-112, 1, 0);
			currentObject = player;
			ObjectsInScene.push_back(player);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			currentObject = NULL;
	}
	
	//Update all the objects in the scene
	for (auto it = ObjectsInScene.begin(); it != ObjectsInScene.end(); ++it)
	{
		(*it)->Update(dt);
	}

}

void Level::Render(sf::RenderWindow* rw)
{
	for (auto it = ObjectsInScene.begin(); it != ObjectsInScene.end(); ++it)
	{
		(*it)->Render(rw);
	}

}
