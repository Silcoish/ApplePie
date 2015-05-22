#include "Spike.h"
#include "GameManager.h"

Spike::Spike(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth)
{
	SetType(type);
	SetName(name);
	SetPosition(sf::Vector2f(x, y));
	SetStartPosition(sf::Vector2f(x, y));
	SetworldSpace(worldSpace);
	SetIsStatic(isStatic);


	SpritesheetLoader loader;

	Animation idle;
	idle.sprites = loader.Load("Resources/Objects/Environment/Spike.png", 219, 190, 1);
	idle.endEvent = Animation::AnimationEndEvent::HoldLastFrame;
	idle.globalSpeed = 0.02;
	idle.nextAnimation = "idle";
	animations.animations["idle"] = idle;

	ScaleSprites(animations.animations, sf::Vector2f(130,130));

	animations.SwitchAnimations("idle");

	collider = new BoxCollider();
	collider->size = sf::Vector2f(130, 130);
	collider->isTrigger = false;
}

Spike::~Spike()
{
}

void Spike::Update(float dt)
{

}