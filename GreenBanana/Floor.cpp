#include "Floor.h"

Floor::Floor(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic)
{
	SetType(type);
	SetName(name);
	SetPosition(sf::Vector2f(x, y));
	SetworldSpace(worldSpace);
	SetIsStatic(isStatic);

	// set the floor sprite
}

Floor::~Floor()
{
}

void Floor::Update(float dt)
{

}

void Floor::Render(sf::RenderWindow* window)
{
	
}