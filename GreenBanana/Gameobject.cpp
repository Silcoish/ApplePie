#include "Gameobject.h"

Gameobject::Gameobject()
{
}

Gameobject::Gameobject(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic)
{
	SetType(type);
	SetName(name);
	SetPosition(sf::Vector2f(x,y));
	SetworldSpace(worldSpace);
	SetIsStatic(isStatic);
}

Gameobject::~Gameobject()
{
}

void Gameobject::Update(float dt)
{

}

void Gameobject::Render(sf::RenderWindow* window)
{

}

