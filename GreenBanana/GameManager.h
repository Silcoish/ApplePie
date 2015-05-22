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
private:
	std::map<std::string, sf::Texture*> textures;
public:
	static GameManager &shared_instance() { static GameManager game; return game; }
	UpgradeData upgradeData;
	bool editor = false;
	bool showBoxColliders = false;
	float cameraMoveSpeed = 1000.0f;
	sf::Vector2f cameraPos;
	sf::RenderWindow* rw;

	int globalClockSpeed = 1;
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

	sf::Texture* GetTexture(std::string filePath)
	{
		auto it = textures.find(filePath);

		if (it != textures.end())
		{
			return textures[filePath];
		}
		else
		{

			sf::Texture* tex = new sf::Texture();

			if (!tex->loadFromFile(filePath))
			{
				//Error
				std::cout << "File Not Found: " << filePath << std::endl;
				//texture = new sf::Texture();
				//texture->create(32, 32);
				//sf::Uint8* pixels = new sf::Uint8[32 * 32 * 4];

				//for (size_t i = 0; i < 4096; i += 4)
				//{
				//	pixels[i] = 0;
				//	pixels[i + 1] = 255;
				//	pixels[i + 2] = 140;
				//	pixels[i + 3] = 255;
				//}
				//texture->update(pixels);
			}
			textures[filePath] = tex;
			
			return tex;




		}

		

	}

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
			curScene->ResetScene();
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