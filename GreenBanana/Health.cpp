#include "Health.h"


Health::Health(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic)
{
	SetType(type);
	SetName(name);
	SetPosition(sf::Vector2f(x, y));
	SetworldSpace(worldSpace);
	SetIsStatic(isStatic);

	// set the trap sprite
}

Health::~Health()
{
}

void Health::Update(float dt)
{

}

void Health::Render(sf::RenderWindow* window)
{
	
}