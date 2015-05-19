#ifndef LEVEL_H
#define LEVEL_H
#include "Scene.h"

class Level : public Scene
{
public:
	Level();
	Level(std::string filePath);
	~Level();
};

#endif