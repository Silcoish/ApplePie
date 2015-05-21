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
	void Render(sf::RenderWindow* rw);

private:
	//Player Variables
	sf::Vector2f velocity = sf::Vector2f(0,0);

	int health;

	float walkSpeed;
	float jumpTime;

	bool isGrounded;
	bool isFalling;

	float timerJump;

	bool isDead = false;
	float timerDeath = 0;
};

#endif