#ifndef HEALTH_H
#define HEALTH_H
#include "Gameobject.h"
class Health :
	public Gameobject
{
public:
	Health(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth);
	~Health();

	void Update(float dt);
};


#endif