#pragma once
#include "Gameobject.h"
class Trap :
	public Gameobject
{
public:
	Trap(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic);
	~Trap();

	void Update(float dt);
	void Render(sf::RenderWindow* window);
	
};

