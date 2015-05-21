#ifndef TRAP_H
#define TRAP_H
#include "Gameobject.h"
#include "SpritesheetLoader.h"
class Trap :
	public Gameobject
{
public:
	Trap(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth);
	~Trap();

	void Update(float dt);
	void Render(sf::RenderWindow* window);
	
};
#endif
