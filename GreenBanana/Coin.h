#pragma once
#include "Gameobject.h"
class Coin :
	public Gameobject
{
public:
	Coin(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic);
	~Coin();

	void Update(float dt);
	void Render(sf::RenderWindow* window);
};

