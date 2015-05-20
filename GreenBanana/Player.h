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

private:
	//Player Variables
	sf::Vector2f velocity;

	float walkSpeed = 100;

	bool isJump = false;
};

#endif