#ifndef LEVEL_H
#define LEVEL_H
#include "Scene.h"
#include "GameManager.h"

class Level : public Scene
{
private:
	bool editor = true;
	Gameobject* currentObject;

public:
	Level();
	Level(std::string filePath);
	~Level();
	void Update(float dt);
	void Render(sf::RenderWindow* rw);
};

#endif