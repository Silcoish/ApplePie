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
	clockText->text.setScale(sf::Vector2f(2, 1.5));
	clockText->text.setColor(sf::Color::Blue);
	objectsInScene.push_back(clockText);

	bagText = new TextObject("text", "bagText", -450, -300, 0, 1, 100);
	bagText->text.setScale(sf::Vector2f(3, 3));
	bagText->text.setColor(sf::Color::Blue);
	objectsInScene.push_back(bagText);

	GameManager::shared_instance().upgradeData.clock = 10 + GameManager::shared_instance().upgradeData.clockSpeed * 5;
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



	bagText->text.setString(std::to_string(GameManager::shared_instance().upgradeData.coins));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		GameManager::shared_instance().upgradeData.coins += 10000;

}

void Level::ResetScene()
{
	//Reset CLock
	GameManager::shared_instance().upgradeData.clock = 10 + GameManager::shared_instance().upgradeData.clockSpeed * 5;
	std::stringstream ss;
	ss << GameManager::shared_instance().upgradeData.clock;
	ss.precision(2);
	clockText->text.setString("Clock: " + ss.str());


	for (size_t i = 0; i < objectsInScene.size(); i++)
	{
		objectsInScene[i]->ResetObject();
	}
}
