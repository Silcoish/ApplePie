#include "UpgradeScene.h"


UpgradeScene::UpgradeScene()
{
	Parse();
	
	//for (auto it = objectsInScene.begin(); it != objectsInScene.end(); ++it)
	//{
	//	if ((*it)->GetName() == "DoubleJumpText");
	//	{
	//		doubleJumpText = (*it);
	//		break;
	//	}
	//}
}

UpgradeScene::~UpgradeScene()
{
}

void UpgradeScene::Render(sf::RenderWindow* rw)
{
	for (auto it = objectsInScene.begin(); it != objectsInScene.end(); ++it)
	{
		(*it)->Render(rw);
	}
}

void UpgradeScene::Update(float dt)
{
	SceneLogic(dt);
	for (auto it = objectsInScene.begin(); it != objectsInScene.end(); ++it)
	{
		(*it)->Update(dt);
	}
}

void UpgradeScene::SceneLogic(float dt)
{

}
