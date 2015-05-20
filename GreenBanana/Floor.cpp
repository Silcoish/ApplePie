#include "Floor.h"
#include "SpritesheetLoader.h"

Floor::Floor(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic)
{
	SetType(type);
	SetName(name);
	SetPosition(sf::Vector2f(x, y));
	SetworldSpace(worldSpace);
	SetIsStatic(isStatic);

	// set the floor sprite
	Animation idle;
	SpritesheetLoader loader;
	idle.sprites = loader.Load("Resources/Objects/Environment/ChocBlockSmall.png", 133, 122);
	idle.endEvent = Animation::AnimationEndEvent::HoldLastFrame;
	animations.animations["idle"] = idle;
	animations.SwitchAnimations("idle");

	collider.size = sf::Vector2f(160, 224);
}

Floor::~Floor()
{
}

void Floor::Update(float dt)
{

}

void Floor::Render(sf::RenderWindow* window)
{
	animations.curSprite->sprite->setPosition(GetPosition());
	window->draw(*animations.curSprite->sprite);
}