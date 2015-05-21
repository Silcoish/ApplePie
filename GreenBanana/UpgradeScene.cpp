#include "UpgradeScene.h"
#include "GameManager.h"
#include "InputManager.h"
#include <iostream>

UpgradeScene::UpgradeScene(std::string filepath)
{
	SetFilePath(filepath);
	Parse();
	continueText = new TextObject("text", "continue", -380, 230, 0, 1, 100);
	jumpHeightText = new TextObject("text","JumpHeight",-520,0,0,1,100);
	titleText = new TextObject("text", "Title", -280, -320, 0, 1, 100);
	clockSpeedText = new TextObject("text", "ClockSpeed", 50, -140, 0, 1, 100);
	moveSpeedText = new TextObject("text", "MoveSpeed", -520, -130, 0, 1, 100);
	sugarMagnetText = new TextObject("text", "SugarMagnet", 50, 0, 0, 1, 100);
	
	titleText->text.setString("UPGRADE YOUR SHIT");
	titleText->text.setScale(sf::Vector2f(2, 2));
	continueText->text.setString("PRESS SPACE TO CONTINUE");
	continueText->text.setScale(sf::Vector2f(2,2));

	jumpHeightText->text.setScale(sf::Vector2f(1.5, 1.5));
	clockSpeedText->text.setScale(sf::Vector2f(1.5, 1.5));
	moveSpeedText->text.setScale(sf::Vector2f(1.5, 1.5));
	sugarMagnetText->text.setScale(sf::Vector2f(1.5, 1.5));

	objectsInScene.push_back(continueText);
	objectsInScene.push_back(jumpHeightText);
	objectsInScene.push_back(titleText);
	objectsInScene.push_back(clockSpeedText);
	objectsInScene.push_back(moveSpeedText);
	objectsInScene.push_back(sugarMagnetText);
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
	// update Jump Height text
	ss << "Increase Jump Height" << std::endl << "                " << GameManager::shared_instance().upgradeData.jumpHeight << "/5";
	jumpHeightText->text.setString(ss.str());
	ss.str("");

	// Update Move Speed text
	ss << "Increase Move Speed" << std::endl << "                " << GameManager::shared_instance().upgradeData.moveSpeed << "/10";
	moveSpeedText->text.setString(ss.str());
	ss.str("");
	
	// Update clock speed text
	ss << "Increase Clock Time" << std::endl << "                " << GameManager::shared_instance().upgradeData.clockSpeed << "/10";
	clockSpeedText->text.setString(ss.str());
	ss.str("");

	// Update Magnet text
	ss << "Increase Pickup Range" << std::endl << "                  " << GameManager::shared_instance().upgradeData.CollectionArea << "/3";
	sugarMagnetText->text.setString(ss.str());
	ss.str("");

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		GameManager::shared_instance().ChangeScene(GameManager::shared_instance().GAME);
		GameManager::shared_instance().ReloadScene(GameManager::shared_instance().GAME);
		Unload();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		GameManager::shared_instance().upgradeData.clockSpeed += 1;
	}

}
