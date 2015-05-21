#ifndef SPLENDA_H
#define SPLENDA_H
#include <ctime>
#include <specstrings.h>
#include "Gameobject.h"

class Splenda :
	public Gameobject
{
public:
	Splenda(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth);
	~Splenda();

	void Update(float dt);
};

#endif