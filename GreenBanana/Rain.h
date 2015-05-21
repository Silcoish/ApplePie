#ifndef RAIN_H
#define RAIN_H
#include "Gameobject.h"
class Rain :
	public Gameobject
{
public:
	Rain(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth);
	~Rain();

	void Update(float dt);
};


#endif