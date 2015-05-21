#ifndef LOLLIPOP_H
#define LOLLIPOP_H
#include <ctime>
#include <specstrings.h>
#include "Gameobject.h"

class Lollipop :
	public Gameobject
{
public:
	Lollipop(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth);
	~Lollipop();

	void Update(float dt);
};

#endif