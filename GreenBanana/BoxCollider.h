#pragma once
#include <SFML/System/Vector2.hpp>
class BoxCollider
{
public:
	BoxCollider();
	~BoxCollider();

	sf::Vector2f size;
	bool isTrigger;
	
};

