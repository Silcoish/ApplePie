#ifndef LEVEL_H
#define LEVEL_H
#include <sstream>
#include "Scene.h"
#include "TextObject.h"

class Level : public Scene
{
public:
	Level();
	Level(std::string filePath);
	~Level();
	void SceneLogic(float dt);
	void ResetScene();

	TextObject* clockText;

	std::vector<Gameobject*> rainObjects;
	float timerRain = 0;

};

#endif