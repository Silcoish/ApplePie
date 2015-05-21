#include "Level.h"
#include "GameManager.h"
#include <sstream>
#include "Rain.h"


Level::Level(std::string filePath)
{
	SetFilePath(filePath);
	Parse();
	SortGameobjects(objectsInScene);
	SortGameobjects(GameManager::shared_instance().healthObjects);


	clockText = new TextObject("text", "Clock_001", 420, -450, 0, 1, 100);
	clockText->text.setScale(sf::Vector2f(1.5, 1.5));
	clockText->text.setColor(sf::Color::Blue);
	objectsInScene.push_back(clockText);


	GameManager::shared_instance().upgradeData.clock = 15 + GameManager::shared_instance().upgradeData.clockSpeed * 15;
	std::stringstream ss;
	ss << GameManager::shared_instance().upgradeData.clock;
	ss.precision(2);
	clockText->text.setString("Clock: " + ss.str());


	//Create Rain
	//Rain
	int count = 0;
	while (count < 50)
	{
		count ++;

		int i = (std::rand() % 10) + 1;

		Rain* temp = new Rain("rain", "rain", GameManager::shared_instance().cameraPos.x + (i * 200) - 100, (-1000 + (count * 40)), 1, 0, -10);

		objectsInScene.push_back(temp);
		SortGameobjects(objectsInScene);
	}
}

Level::~Level()
{
	
}

void Level::SceneLogic(float dt)
{
	std::stringstream ss;
	ss << GameManager::shared_instance().upgradeData.clock;
	ss.precision(2);

	clockText->text.setString("Clock: " + ss.str());
}
