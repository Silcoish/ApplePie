#ifndef HILL_H
#define HILL_H
#include "Gameobject.h"
class Hill :
	public Gameobject
{
public:
	Hill(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth);
	~Hill();

	void Update(float dt);
};


#endif