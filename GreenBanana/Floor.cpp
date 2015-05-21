#include "Floor.h"

Floor::Floor(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth)
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
	idle.sprites = loader.Load("Resources/Objects/Environment/ChocBlockSmall.png", 133, 122, 1);
	idle.endEvent = Animation::AnimationEndEvent::HoldLastFrame;
	idle.sprites[0]->sprite->setScale(sf::Vector2f((130.0 / 133.0), (120.0 / 122.0)));
	idle.sprites[0]->width = 130;
	idle.sprites[0]->height = 120;
	animations.animations["idle"] = idle;
	animations.SwitchAnimations("idle");

	collider = new BoxCollider();
	collider->size = sf::Vector2f(animations.curSprite->width, animations.curSprite->height);
	collider->isTrigger = false;
}

Floor::~Floor()
{
}

void Floor::Update(float dt)
{
	animations.Update(dt);

	collider->center = position + sf::Vector2f(animations.curSprite->width / 2, animations.curSprite->height / 2);
}
