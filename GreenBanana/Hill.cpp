#include "Hill.h"
#include "GameManager.h"

Hill::Hill(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth)
{
	SetType(type);
	SetName(name);
	SetPosition(sf::Vector2f(x, y));
	SetStartPosition(sf::Vector2f(x, y));
	SetworldSpace(worldSpace);
	SetIsStatic(isStatic);


	SpritesheetLoader loader;

	Animation idle;
	idle.sprites = loader.Load("Resources/Objects/Environment/Hill.png", 1080, 281, 1);
	idle.endEvent = Animation::AnimationEndEvent::HoldLastFrame;
	idle.globalSpeed = 0.02;
	idle.nextAnimation = "idle";
	animations.animations["idle"] = idle;

	int j = (std::rand() % 6) + 5;
	ScaleSprites(animations.animations, (((float)j / 25)));

	animations.SwitchAnimations("idle");

	collider = new BoxCollider();
	collider->size = sf::Vector2f(0, 0);
	collider->isTrigger = true;
}

Hill::~Hill()
{
}

void Hill::Update(float dt)
{

}