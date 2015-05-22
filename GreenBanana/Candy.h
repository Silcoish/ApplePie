#ifndef CANDY_H
#define CANDY_H
#include <ctime>
#include <specstrings.h>
#include "Gameobject.h"

class Candy :
	public Gameobject
{
public:
	Candy(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth);
	~Candy();

	void Update(float dt);
};

#endif