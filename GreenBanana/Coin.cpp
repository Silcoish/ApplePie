#include "Coin.h"


Coin::Coin(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth)
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
	healthFull.globalSpeed = 0.02;
	healthFull.nextAnimation = "healthFull";
	animations.animations["healthFull"] = healthFull;

	Animation healthDestroyed;
	healthDestroyed.sprites = loader.Load("Resources/Objects/HealthObjects/sugar_Destroyed.png", 144, 124, 1);
	healthDestroyed.endEvent = Animation::AnimationEndEvent::HoldLastFrame;
	healthDestroyed.globalSpeed = 0.02;
	healthDestroyed.nextAnimation = "healthDestroyed";
	animations.animations["healthDestroyed"] = healthDestroyed;

	ScaleSprites(animations.animations, sf::Vector2f(140, 120));

	animations.SwitchAnimations("healthFull");

	collider = new BoxCollider();
	collider->size = sf::Vector2f(animations.curSprite->width, animations.curSprite->height);
	collider->isTrigger = true;
}


Coin::~Coin()
{
}

void Coin::Update(float dt)
{
	animations.Update(dt);
}