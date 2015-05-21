#pragma once
#include "Scene.h"
#include "GameManager.h"
class UpgradeScene :
	public Scene
{
public:
	UpgradeScene(std::string filpath);
	~UpgradeScene();

	void Render(sf::RenderWindow* window);
	virtual void SceneLogic(float dt);
	
	TextObject* clockSpeed = nullptr;
	TextObject* moveSpeedText = nullptr;
	TextObject* jumpHeightText = nullptr;
	TextObject* sugarMagnetText = nullptr;

};

