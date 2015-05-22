#include <iostream>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
#include <math.h>
#include "GameManager.h"
#include "Level.h"
#include "UpgradeScene.h"
#include "InputManager.h"
#include "LoadingScreen.h"

using namespace std::chrono;

const float targetTime = 1.0f/60.0f;

void Update(float dt)
{
	GameManager::shared_instance().curScene->Update(dt);
}

void Render(sf::RenderWindow* rw)
{
	GameManager::shared_instance().curScene->Render(rw);
}

int main()
{
	std::srand(std::time(0));

    sf::RenderWindow window(sf::VideoMode(720, 480), "Green Banana!");
	GameManager::shared_instance().rw = &window;

	LoadingScreen* loadingScreen = new LoadingScreen();
	GameManager::shared_instance().curScene = loadingScreen;
	Render(&window);
	window.display();


	sf::View camera;

	//Set Up Camera
	camera.setSize(sf::Vector2f(720, 480));
	camera.setCenter(sf::Vector2f(0, 0));
	camera.zoom(2);

	//Set Camera to Window
	window.setView(camera);


	std::chrono::high_resolution_clock::time_point lastTime = std::chrono::high_resolution_clock::now();
	std::chrono::high_resolution_clock::time_point curTime = std::chrono::high_resolution_clock::now();
	

	GameManager::shared_instance().CreateScenes();
	GameManager::shared_instance().ChangeScene(GameManager::shared_instance().MENU);

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
			InputMapper::shared_instance().curState["Tab"] =			sf::Keyboard::isKeyPressed(sf::Keyboard::Tab);
			InputMapper::shared_instance().curState["Equal"] =			sf::Keyboard::isKeyPressed(sf::Keyboard::Equal);
			InputMapper::shared_instance().curState["Dash"] =			sf::Keyboard::isKeyPressed(sf::Keyboard::Dash);
			InputMapper::shared_instance().curState["MouseLeft"] =		sf::Mouse::isButtonPressed(sf::Mouse::Left);
			InputMapper::shared_instance().curState["S"] =				sf::Keyboard::isKeyPressed(sf::Keyboard::S);
			InputMapper::shared_instance().curState["LControl"] =		sf::Keyboard::isKeyPressed(sf::Keyboard::LControl);
			InputMapper::shared_instance().curState["P"] = sf::Keyboard::isKeyPressed(sf::Keyboard::P);
			InputMapper::shared_instance().curState["O"] = sf::Keyboard::isKeyPressed(sf::Keyboard::O);

			InputMapper::shared_instance().curState["P"] = sf::Keyboard::isKeyPressed(sf::Keyboard::P);
			InputMapper::shared_instance().curState["L"] = sf::Keyboard::isKeyPressed(sf::Keyboard::L);
			InputMapper::shared_instance().curState["O"] = sf::Keyboard::isKeyPressed(sf::Keyboard::O);
			InputMapper::shared_instance().curState["K"] = sf::Keyboard::isKeyPressed(sf::Keyboard::K);
			InputMapper::shared_instance().curState["1"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Num1);
			InputMapper::shared_instance().curState["2"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Num2);
			InputMapper::shared_instance().curState["3"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Num3);
			InputMapper::shared_instance().curState["4"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Num4);


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