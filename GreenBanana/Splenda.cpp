#include "Splenda.h"

Splenda::Splenda(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth)
{
	SetType(type);
	SetName(name);
	SetPosition(sf::Vector2f(x, y));
	SetworldSpace(worldSpace);
	SetIsStatic(isStatic);
	SetDepth(depth);

	//std::srand(std::rand());

	Animation walk;
	SpritesheetLoader loader;
	walk.sprites = loader.Load("Resources/Animations/BadSugar/sugar.png", 152, 170, 90);
	walk.endEvent = Animation::AnimationEndEvent::Loop;
	walk.globalSpeed = 0.02;
	animations.animations["walk"] = walk;
	animations.SwitchAnimations("walk");

	collider = new BoxCollider();
	collider->size = sf::Vector2f(152, 170);
	collider->isTrigger = false;
}

Splenda::~Splenda()
{
}

void Splenda::Update(float dt)
{
	animations.Update(dt);

	collider->center = position + sf::Vector2f(animations.curSprite->width / 2, animations.curSprite->height / 2);
}
