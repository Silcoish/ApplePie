#ifndef PLAYER_H
#define PLAYER_H
#include "Gameobject.h"
#include "SpritesheetLoader.h"
class Player : public Gameobject
{
public:
	Player(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic , int depth);
	~Player();

	void Update(float dt);

private:
	//Player Variables
	sf::Vector2f velocity = sf::Vector2f(0,0);

	float walkSpeed = 400;
	float jumpTime = 0.3;

	bool isGrounded;
	bool isFalling;

	float timerJump = 0;
};

#endif