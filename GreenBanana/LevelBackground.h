#ifndef LEVELBACKGROUND_H
#define LEVELBACKGROUND_H
#include "Gameobject.h"

class LevelBackground : public Gameobject
{
public:
	LevelBackground(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth);
	~LevelBackground();

	virtual void Update(float dt);
};


#endif