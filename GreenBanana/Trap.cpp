#include "Trap.h"


Trap::Trap(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth)
{
	SetType(type);
	SetName(name);
	SetPosition(sf::Vector2f(x, y));
	SetworldSpace(worldSpace);
	SetIsStatic(isStatic);
	SetDepth(depth);

	Animation idle;
	SpritesheetLoader loader;
	idle.sprites = loader.Load("Resources/Animations/Choc/choc.png", 388, 100, 65);
	idle.endEvent = Animation::AnimationEndEvent::Loop;
	//idle.sprites[0]->sprite->setScale(sf::Vector2f((380 / 384), (100 / 98)));
	//idle.sprites[0]->width = 380;
	//idle.sprites[0]->height = 100;
	idle.globalSpeed = 0.02;
	animations.animations["idle"] = idle;
	animations.SwitchAnimations("idle");

	collider = new BoxCollider();
	collider->size = sf::Vector2f(animations.curSprite->width, animations.curSprite->height);
	collider->isTrigger = false;
}

Trap::~Trap()
{
}

void Trap::Update(float dt)
{
	animations.Update(dt);

	collider->center = position + sf::Vector2f(animations.curSprite->width / 2, animations.curSprite->height / 2);
}
