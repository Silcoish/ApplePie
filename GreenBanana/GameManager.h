#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "UpgradeData.h"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "Scene.h"
#include "Level.h"
#include "UpgradeScene.h"
#include "MenuScene.h"

class GameManager
{

public:
	static GameManager &shared_instance() { static GameManager game; return game; }
	UpgradeData upgradeData;
	bool editor = false;
	bool showBoxColliders = false;
	float cameraMoveSpeed = 1000.0f;
	sf::Vector2f cameraPos;
	sf::RenderWindow* rw;

	std::vector<Gameobject*> healthObjects;

	enum GameStates
	{
		MENU,
		GAME,
		UPGRADE
	};
	GameStates currentState = GAME;
	std::map<GameStates, Scene*> scenes;
	Scene* curScene;

	void ReloadScene(GameStates state)
	{
		switch (state)
		{
		case GAME:
			delete scenes[state];
			Scene* gameScene = new Level("Resources/SceneData/testgame.txt");
			scenes[GAME] = gameScene;
			break;
		}
	}

	void ChangeScene(GameStates newState)
	{
		auto loc = scenes.find(newState);
		if (loc != scenes.end())
		{
			curScene = loc->second; 
			std::cout << "Changed scene" << std::endl;
		}
		else
		{
			std::cout << "Error: Invalid GameState" << std::endl;
		}

	}

	void CreateScenes()
	{
		Scene* gameScene = new Level("Resources/SceneData/testgame.txt");
		scenes[GAME] = gameScene;

		Scene* upgradeScene = new UpgradeScene("Resources/SceneData/upgrade.txt");
		scenes[UPGRADE] = upgradeScene;

		Scene* menuScene = new MenuScene("Resources/SceneData/menu.txt");
		scenes[MENU] = menuScene;
	}

private:
	GameManager()
	{

	}
};

#endif