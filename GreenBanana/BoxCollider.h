#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H
#include <SFML/System/Vector2.hpp>
class BoxCollider
{
public:
	BoxCollider();
	~BoxCollider();

	sf::Vector2f center;
	sf::Vector2f size;
	bool isTrigger;
	
};

#endif

