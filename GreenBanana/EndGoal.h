#pragma once
#include "Gameobject.h"
class EndGoal :
	public Gameobject
{
public:
	EndGoal(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth);
	~EndGoal();


	virtual void Render(sf::RenderWindow* window);
	void Update(float dt);


};

