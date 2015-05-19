#include <iostream>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>

#include "Level.h"

using namespace std::chrono;

const float targetTime = 1.0f/60.0f;

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

void Update(float dt)
{
	curScene->Update(dt);
}

void Render(sf::RenderWindow* rw)
{
	curScene->Render(rw);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(720, 480), "Green Banana!");

	std::chrono::high_resolution_clock::time_point lastTime = std::chrono::high_resolution_clock::now();
	std::chrono::high_resolution_clock::time_point curTime = std::chrono::high_resolution_clock::now();

	Scene* newScene = new Level("Resources/SceneData/testgame.txt");
	scenes[GAME] = newScene;

	ChangeScene(GAME);

    while (window.isOpen())
    {
		curTime = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> dt = std::chrono::duration_cast<std::chrono::duration<double>>(curTime - lastTime);
		if (dt.count() >= targetTime)
		{
			//Poll Events
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			//Update
			Update((float)dt.count());
			
			//std::cout << dt.count();
			lastTime = std::chrono::high_resolution_clock::now();
		}
		
        window.clear();
     
		Render(&window);
		
        window.display();
    }

    return 0;
}