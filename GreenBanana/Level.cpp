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
