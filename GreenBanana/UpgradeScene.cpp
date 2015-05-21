#include "UpgradeScene.h"
#include <iostream>

UpgradeScene::UpgradeScene(std::string filepath)
{
	SetFilePath(filepath);
	Parse();
	jumpHeightText = new TextObject("text","JumpHeight",100,100,0,1,100);
	jumpHeightText->text.setString("Increase Jump Height \n                0/10");
	objectsInScene.push_back(jumpHeightText);
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


void UpgradeScene::SceneLogic(float dt)
{
	std::stringstream ss;
	ss << "Increase Jump Height" << std::endl << "                " << GameManager::shared_instance().upgradeData.jumpHeight << "/5";
	jumpHeightText->text.setString(ss.str());	
}
