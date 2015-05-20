#include <iostream>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
#include <math.h>
#include "GameManager.h"
#include "Level.h"
#include "InputManager.h"

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
	GameManager::shared_instance().rw = &window;

	sf::View camera;

	//Set Up Camera
	camera.setSize(sf::Vector2f(720, 480));
	camera.setCenter(sf::Vector2f(0, 0));
	camera.zoom(2);

	//Set Camera to Window
	window.setView(camera);




	std::chrono::high_resolution_clock::time_point lastTime = std::chrono::high_resolution_clock::now();
	std::chrono::high_resolution_clock::time_point curTime = std::chrono::high_resolution_clock::now();

	Scene* newScene = new Level("Resources/SceneData/testgame.txt");
	scenes[GAME] = newScene;

	ChangeScene(GAME);

	float timer = 0;

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

			//InputManager Set Previous and Current
			InputMapper::shared_instance().prevState = InputMapper::shared_instance().curState;
			//Set Each KeyPress
			InputMapper::shared_instance().curState["LShift"] =			sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);
			InputMapper::shared_instance().curState["MouseLeft"] =		sf::Mouse::isButtonPressed(sf::Mouse::Left);
			InputMapper::shared_instance().curState["S"] =				sf::Keyboard::isKeyPressed(sf::Keyboard::S);
			InputMapper::shared_instance().curState["LControl"] =		sf::Keyboard::isKeyPressed(sf::Keyboard::LControl);


			//Update
			Update((float)dt.count());
			
			//std::cout << dt.count();
			lastTime = std::chrono::high_resolution_clock::now();
		}
						
		camera.setCenter(GameManager::shared_instance().cameraPos);

		window.setView(camera);
		
        window.clear();
     
		Render(&window);
		
        window.display();


		
    }

    return 0;
}