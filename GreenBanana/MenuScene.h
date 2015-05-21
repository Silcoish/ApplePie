#pragma once
#include "Scene.h"

class MenuScene :
	public Scene
{
public:
	MenuScene(std::string filepath);
	~MenuScene();

	void Render(sf::RenderWindow* window);
	virtual void SceneLogic(float dt);

	TextObject* titleText = NULL;
	TextObject* continueText = NULL;
	

private:
	InputMapper* inputManager = &InputMapper::shared_instance();

};

