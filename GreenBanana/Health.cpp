#include "Health.h"

Health::Health(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth)
{
	SetType(type);
	SetName(name);
	SetPosition(sf::Vector2f(x, y));
	SetworldSpace(worldSpace);
	SetIsStatic(isStatic);
	SetDepth(depth);
	

	SpritesheetLoader loader;

	Animation healthFull;
	healthFull.sprites = loader.Load("Resources/Objects/HealthObjects/sugar.png", 144, 124, 89);
	healthFull.endEvent = Animation::AnimationEndEvent::Loop;
	//healthFull.sprites[0]->sprite->setScale(sf::Vector2f((60 / 54), (340 / 336)));
	healthFull.sprites[0]->width = 144;
	healthFull.sprites[0]->height = 124;
	healthFull.globalSpeed = 0.02;
	animations.animations["healthFull"] = healthFull;

	Animation healthEmpty;
	healthEmpty.sprites = loader.Load("Resources/Objects/HealthObjects/sugar_Empty.png", 144, 124, 1);
	healthEmpty.endEvent = Animation::AnimationEndEvent::HoldLastFrame;
	//healthEmpty.sprites[0]->sprite->setScale(sf::Vector2f((60 / 54), (340 / 336)));
	healthEmpty.sprites[0]->width = 144;
	healthEmpty.sprites[0]->height = 124;
	healthEmpty.globalSpeed = 0.02;
	animations.animations["healthEmpty"] = healthEmpty;


	animations.SwitchAnimations("healthFull");

	collider = new BoxCollider();
	collider->size = sf::Vector2f(animations.curSprite->width, animations.curSprite->height);
	collider->isTrigger = false;
}

Health::~Health()
{
}

void Health::Update(float dt)
{
	animations.Update(dt);
}