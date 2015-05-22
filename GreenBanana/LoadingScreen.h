#pragma once
#include "Scene.h"
class LoadingScreen :
	public Scene
{
public:
	LoadingScreen();
	~LoadingScreen();


	void Render(sf::RenderWindow* window);
	virtual void SceneLogic(float dt);

	TextObject* titleText = NULL;

};

