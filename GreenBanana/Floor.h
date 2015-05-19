#pragma once
#include "Gameobject.h"
class Floor :
	public Gameobject
{
public:
	Floor(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic);
	~Floor();

	void Update(float dt);
	void Render(sf::RenderWindow* window);
};

