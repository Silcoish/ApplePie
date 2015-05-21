#pragma once
#include "Scene.h"

class UpgradeScene :
	public Scene
{
public:
	UpgradeScene(std::string filepath);
	~UpgradeScene();

	void Render(sf::RenderWindow* window);
	virtual void SceneLogic(float dt);
	
	TextObject* continueText = NULL;
	TextObject* titleText = NULL;
	TextObject* clockSpeedText = NULL;
	TextObject* moveSpeedText = NULL;
	TextObject* jumpHeightText = NULL;
	TextObject* sugarMagnetText = NULL;

private:
	//InputMapper* inputManager = &InputMapper::shared_instance();

};

