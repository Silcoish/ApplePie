#ifndef BAG_H
#define BAG_H
#include "Gameobject.h"
class Bag :
	public Gameobject
{
public:
	Bag(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth);
	~Bag();

	void Update(float dt);
};


#endif