#include "Trap.h"


Trap::Trap(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth)
{
	SetType(type);
	SetName(name);
	SetPosition(sf::Vector2f(x, y));
	SetworldSpace(worldSpace);
	SetIsStatic(isStatic);
	SetDepth(depth);

	// set the trap sprite
	animations;
	Animation idle;
	SpritesheetLoader loader;
	idle.sprites = loader.Load("Resources/Animations/Choc/choc.png", 385, 98);
	idle.endEvent = Animation::AnimationEndEvent::Loop;
	animations.animations["idle"] = idle;
	animations.SwitchAnimations("idle");
}

Trap::~Trap()
{
}

void Trap::Update(float dt)
{

}

void Trap::Render(sf::RenderWindow* window)
{
	animations.curSprite->sprite->setPosition(GetPosition());
	window->draw(*animations.curSprite->sprite);
}