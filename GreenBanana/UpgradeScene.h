#pragma once
#include "Scene.h"
class UpgradeScene :
	public Scene
{
public:
	UpgradeScene();
	~UpgradeScene();

	void Update(float dt);
	void Render(sf::RenderWindow* window);
	void SceneLogic(float dt);
	
	Gameobject* doubleJumpText = nullptr;
	Gameobject* moveSpeedText = nullptr;
	Gameobject* jumpHeightText = nullptr;
	Gameobject* sugarMagnetText = nullptr;

};

