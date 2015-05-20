#ifndef LEVEL_H
#define LEVEL_H
#include "Scene.h"

class Level : public Scene
{
private:
	bool editor = true;

public:
	Level();
	Level(std::string filePath);
	~Level();
	void Update(float dt);
};

#endif