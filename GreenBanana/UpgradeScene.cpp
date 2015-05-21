#include "UpgradeScene.h"
#include "GameManager.h"
#include "InputManager.h"
#include <iostream>

UpgradeScene::UpgradeScene(std::string filepath)
{
	SetFilePath(filepath);
	Parse();

	coinsText = new TextObject("text", "Coins", -120, -340, 0, 1, 100);
	coinsText->text.setScale(sf::Vector2f(2, 2));
	coinsText->text.setColor(sf::Color::Blue);
	objectsInScene.push_back(coinsText);

	// Upgrade Texts
	continueText = new TextObject("text", "continue", -390, 320, 0, 1, 100);
	continueText->text.setString("PRESS SPACE TO CONTINUE");
	continueText->text.setScale(sf::Vector2f(2, 2));
	continueText->text.setColor(sf::Color::Blue);
	objectsInScene.push_back(continueText);

	jumpHeightText = new TextObject("text","JumpHeight",-540,40,0,1,100);
	jumpHeightText->text.setScale(sf::Vector2f(1.5, 1.5));
	jumpHeightText->text.setColor(sf::Color::Blue);
	objectsInScene.push_back(jumpHeightText);

	titleText = new TextObject("text", "Title", -350, -400, 0, 1, 100);
	titleText->text.setString("UPGRADE YOUR ABILITIES!");
	titleText->text.setScale(sf::Vector2f(2, 2));
	titleText->text.setColor(sf::Color::Blue);
	objectsInScene.push_back(titleText);
	
	clockSpeedText = new TextObject("text", "ClockSpeed", 60, -200, 0, 1, 100);
	clockSpeedText->text.setScale(sf::Vector2f(1.5, 1.5));
	clockSpeedText->text.setColor(sf::Color::Blue);
	objectsInScene.push_back(clockSpeedText);

	moveSpeedText = new TextObject("text", "MoveSpeed", -540, -200, 0, 1, 100);
	moveSpeedText->text.setScale(sf::Vector2f(1.5, 1.5));
	moveSpeedText->text.setColor(sf::Color::Blue);
	objectsInScene.push_back(moveSpeedText);

	sugarMagnetText = new TextObject("text", "SugarMagnet", 40, 40, 0, 1, 100);
	sugarMagnetText->text.setScale(sf::Vector2f(1.5, 1.5));
	sugarMagnetText->text.setColor(sf::Color::Blue);
	objectsInScene.push_back(sugarMagnetText);
	

	// Buy Texts
	buyClockText = new TextObject("text", "BuyClock", -410, -230, 0, 1, 100);
	buyClockText->text.setString("Press O to buy");
	buyClockText->text.setScale(sf::Vector2f(1, 1));
	buyClockText->text.setColor(sf::Color::Blue);
	objectsInScene.push_back(buyClockText);

	buyMoveText = new TextObject("text", "BuyMove", 180, -230, 0, 1, 100);
	buyMoveText->text.setString("Press P to buy");
	buyMoveText->text.setScale(sf::Vector2f(1, 1));
	buyMoveText->text.setColor(sf::Color::Blue);
	objectsInScene.push_back(buyMoveText);

	buyJumpText = new TextObject("text", "BuyJump", -410, 10, 0, 1, 100);
	buyJumpText->text.setString("Press K to buy");
	buyJumpText->text.setScale(sf::Vector2f(1, 1));
	buyJumpText->text.setColor(sf::Color::Blue);
	objectsInScene.push_back(buyJumpText);

	buyMagnetText = new TextObject("text", "Magnet", 190, 10, 0, 1, 100);
	buyMagnetText->text.setString("Press L to buy");
	buyMagnetText->text.setScale(sf::Vector2f(1, 1));
	buyMagnetText->text.setColor(sf::Color::Blue);
	objectsInScene.push_back(buyMagnetText);
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
	//Update Coins
	ss << "Sugar: " << GameManager::shared_instance().upgradeData.coins;
	coinsText->text.setString(ss.str());
	ss.str("");

	// update Jump Height text
	ss << "Increase Jump Height" << std::endl;
	ss << "            " << "(" << GameManager::shared_instance().upgradeData.jumpHeightCost << " sugar)" << std::endl;
	ss << "                 " << GameManager::shared_instance().upgradeData.jumpHeight << "/5";
	jumpHeightText->text.setString(ss.str());
	ss.str("");

	// Update Move Speed text
	ss << "Increase Move Speed" << std::endl;
	ss << "           " << "(" << GameManager::shared_instance().upgradeData.moveSpeedCost << " sugar)" << std::endl;
	ss << "                " << GameManager::shared_instance().upgradeData.moveSpeed << "/10";
	moveSpeedText->text.setString(ss.str());
	ss.str("");
	
	// Update clock speed text
	ss << "Increase Clock Time" << std::endl;
	ss << "           " << "(" << GameManager::shared_instance().upgradeData.clockSpeedCost << " sugar)" << std::endl;
	ss << "                " << GameManager::shared_instance().upgradeData.clockSpeed<< "/10";
	clockSpeedText->text.setString(ss.str());
	ss.str("");

	// Update Magnet text
	ss << "Increase Pickup Range" << std::endl;
	ss << "            " << "(" << GameManager::shared_instance().upgradeData.CollectionAreaCost << " sugar)" << std::endl;
	ss << "                  " << GameManager::shared_instance().upgradeData.CollectionArea << "/3";
	sugarMagnetText->text.setString(ss.str());
	ss.str("");

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		GameManager::shared_instance().ChangeScene(GameManager::shared_instance().GAME);
		GameManager::shared_instance().ReloadScene(GameManager::shared_instance().GAME);
		Unload();
	}
	if (!inputManager->curState["P"] && inputManager->prevState["P"])
	{
		if (GameManager::shared_instance().upgradeData.coins >= GameManager::shared_instance().upgradeData.clockSpeedCost)
		{
			if (GameManager::shared_instance().upgradeData.clockSpeed < 10)
			{
				GameManager::shared_instance().upgradeData.clockSpeed += 1;
				GameManager::shared_instance().upgradeData.coins -= GameManager::shared_instance().upgradeData.clockSpeedCost;
			}
		}
	}
	if (!inputManager->curState["L"] && inputManager->prevState["L"])
	{
		if (GameManager::shared_instance().upgradeData.coins >= GameManager::shared_instance().upgradeData.CollectionAreaCost)
		{
			if (GameManager::shared_instance().upgradeData.CollectionArea < 3)
			{
				GameManager::shared_instance().upgradeData.CollectionArea += 1;
				GameManager::shared_instance().upgradeData.coins -= GameManager::shared_instance().upgradeData.CollectionAreaCost;
			}
		}
	}
	if (!inputManager->curState["O"] && inputManager->prevState["O"])
	{
		if (GameManager::shared_instance().upgradeData.coins >= GameManager::shared_instance().upgradeData.moveSpeedCost)
		{
			if (GameManager::shared_instance().upgradeData.moveSpeed < 10)
			{
				GameManager::shared_instance().upgradeData.moveSpeed += 1;
				GameManager::shared_instance().upgradeData.coins -= GameManager::shared_instance().upgradeData.moveSpeedCost;
			}
		}
	}
	if (!inputManager->curState["K"] && inputManager->prevState["K"])
	{
		if (GameManager::shared_instance().upgradeData.coins >= GameManager::shared_instance().upgradeData.jumpHeightCost)
		{
			if (GameManager::shared_instance().upgradeData.jumpHeight < 5)
			{
				GameManager::shared_instance().upgradeData.jumpHeight += 1;
				GameManager::shared_instance().upgradeData.coins -= GameManager::shared_instance().upgradeData.jumpHeightCost;
			}
		}
	}
}
