#ifndef FLOOR_H
#define FLOOR_H
#include "Gameobject.h"
class Floor :
	public Gameobject
{
public:
	Floor(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic);
	~Floor();

	void Update(float dt);
};

#endif