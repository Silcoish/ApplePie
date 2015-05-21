#include "Level.h"


Level::Level(std::string filePath)
{
	SetFilePath(filePath);
	Parse();
	SetBackground("Resources/Backgrounds/BG_Large.png");
	background->sprite->setPosition(0,0);
}

Level::~Level()
{
	
}

void Level::SceneLogic(float dt)
{


}
