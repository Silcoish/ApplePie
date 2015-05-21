#ifndef LEVEL_H
#define LEVEL_H
#include "Scene.h"
#include <sstream>

class Level : public Scene
{
public:
	Level();
	Level(std::string filePath);
	~Level();
	void SceneLogic(float dt);
};

#endif