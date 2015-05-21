#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "UpgradeData.h"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "Scene.h"
#include "Level.h"

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

	enum GameStates
	{
		MENU,
		GAME,
		UPGRADE
	};
	GameStates currentState = GAME;
	std::map<GameStates, Scene*> scenes;
	Scene* curScene;

	void ChangeScene(GameStates newState)
	{
		auto loc = scenes.find(newState);
		if (loc != scenes.end())
		{
			curScene = loc->second;
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
	}

private:
	GameManager()
	{

	}
};

#endif