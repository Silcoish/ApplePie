#ifndef LEVEL_H
#define LEVEL_H
#include <sstream>
#include "Scene.h"

class Level : public Scene
{
public:
	Level();
	Level(std::string filePath);
	~Level();
	void SceneLogic(float dt);
};

#endif