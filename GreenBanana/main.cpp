#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>

#include "Scene.h"

const float targetTime = 1.0f/60.0f;

enum GameStates
{
    MENU,
    GAME,
    UPGRADE
};

GameStates currentState = MENU;
std::map<GameStates, Scene*> scenes;
Scene* curScene;

int main()
{
    sf::RenderWindow window(sf::VideoMode(720, 480), "Green Banana!");

	long lastFrame = time(0);
	long curFrame = time(0);
    while (window.isOpen())
    {
		if (curFrame - lastFrame >= targetTime)
		{
			//Poll Events
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			//Update
			Update((float)curFrame - lastFrame);
			std::cout << (float)curFrame - lastFrame;
		}
		
		lastFrame = time(0);
		Render(&window);
     
        window.clear();
		
        window.display();
    }

    return 0;
}

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