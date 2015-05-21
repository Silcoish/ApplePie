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
	
	TextObject* coinsText = NULL;

	TextObject* continueText = NULL;
	TextObject* titleText = NULL;
	TextObject* clockSpeedText = NULL;
	TextObject* moveSpeedText = NULL;
	TextObject* jumpHeightText = NULL;
	TextObject* sugarMagnetText = NULL;

	TextObject* buyClockText = NULL;
	TextObject* buyMoveText = NULL;
	TextObject* buyJumpText = NULL;
	TextObject* buyMagnetText = NULL;

private:
	InputMapper* inputManager = &InputMapper::shared_instance();

};

