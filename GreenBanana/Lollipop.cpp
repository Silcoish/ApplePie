#include "Lollipop.h"

Lollipop::Lollipop(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth)
{
	SetType(type);
	SetName(name);
	SetPosition(sf::Vector2f(x, y));
	SetworldSpace(worldSpace);
	SetIsStatic(isStatic);
	SetDepth(depth);

	// set the floor sprite
	Animation idle;
	SpritesheetLoader loader;
	idle.sprites = loader.Load("Resources/Objects/Environment/Lollipop1.png", 230, 443, 1);
	idle.endEvent = Animation::AnimationEndEvent::HoldLastFrame;

	animations.animations["idle"] = idle;
	animations.SwitchAnimations("idle");

	collider = new BoxCollider();
	collider->size = sf::Vector2f(animations.curSprite->width, animations.curSprite->height);
	collider->isTrigger = false;
}

Lollipop::~Lollipop()
{
}

void Lollipop::Update(float dt)
{
	animations.Update(dt);

	collider->center = position + sf::Vector2f(animations.curSprite->width / 2, animations.curSprite->height / 2);
}
