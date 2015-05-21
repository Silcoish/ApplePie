#include "Level.h"
#include "GameManager.h"


Level::Level(std::string filePath)
{
	SetFilePath(filePath);
	Parse();
	SortGameobjects(GameManager::shared_instance().healthObjects);
}

Level::~Level()
{
	
}

void Level::SceneLogic(float dt)
{


}


//void Level::Render(sf::RenderWindow* rw)
//{
//	for (auto it = objectsInScene.begin(); it != objectsInScene.end(); ++it)
//	{
//		(*it)->Render(rw);
//	}
//
//}
