#ifndef SPIKE_H
#define SPIKE_H
#include "Gameobject.h"
class Spike :
	public Gameobject
{
public:
	Spike(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth);
	~Spike();

	void Update(float dt);
};


#endif