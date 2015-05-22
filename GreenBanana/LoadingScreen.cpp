#include "LoadingScreen.h"


LoadingScreen::LoadingScreen()
{
	titleText = new TextObject("text", "Title", 70, 140, 0, 1, 100);
	titleText->text.setString("LOADING");
	titleText->text.setScale(sf::Vector2f(5, 5));
	objectsInScene.push_back(titleText);
}


LoadingScreen::~LoadingScreen()
{
}


void LoadingScreen::Render(sf::RenderWindow* window)
{
	for (auto it = objectsInScene.begin(); it != objectsInScene.end(); ++it)
	{
		(*it)->Render(window);
	}
}

void LoadingScreen::SceneLogic(float dt)
{
}