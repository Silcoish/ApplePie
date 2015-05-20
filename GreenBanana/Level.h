#ifndef LEVEL_H
#define LEVEL_H
#include "Scene.h"
#include "GameManager.h"
#include <sstream>

class Level : public Scene
{
private:
	Gameobject* currentObject;

public:
	Level();
	Level(std::string filePath);
	~Level();
	void Update(float dt);
	void Render(sf::RenderWindow* rw);
};

#endif