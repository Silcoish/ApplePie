#include "Level.h"


Level::Level(std::string filePath)
{
	SetFilePath(filePath);
	Parse();
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
