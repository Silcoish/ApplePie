#ifndef SPLENDA_H
#define SPLENDA_H
#include <ctime>
#include <specstrings.h>
#include "Gameobject.h"
#include "Scene.h"

class Splenda :
	public Gameobject
{
private:
	sf::Vector2f startPos;
	float timer = 3;
	float counter = 0;

	sf::Vector2f vel = sf::Vector2f(0,0);

	enum Direction
	{
		DOWN,
		UP,
		IDLE
	};
	Direction direction = IDLE;

public:
	Splenda(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth);
	~Splenda();

	void Update(float dt);
};

#endif