#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>

enum GameStates
{
    MENU,
    GAME,
    UPGRADE
};

GameStates currentState = MENU;
std::map<GameStates, Scene*> scenes;
Scene* currentScene;

int main()
{
    sf::RenderWindow window(sf::VideoMode(720, 480), "Green Banana!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        
        window.display();
    }

    return 0;
}

void ChangeScene(GameStates newState)
{
	
}

void Update()
{

}

void Render(sf::RenderWindow* rw)
{
	currentScene->Render(rw);
}