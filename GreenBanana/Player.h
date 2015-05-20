#ifndef PLAYER_H
#define PLAYER_H
#include "Gameobject.h"
#include "SpritesheetLoader.h"
class Player : public Gameobject
{
public:
	Player(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic);
	~Player();

	void Update(float dt);
	void Render(sf::RenderWindow* window);

};

#endif