#include "Gameobject.h"

void Gameobject::Render(sf::RenderWindow* window)
{
	window->draw(*animations.curSprite->sprite);
}

