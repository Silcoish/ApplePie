#include "Floor.h"

Floor::Floor(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic)
{
	SetType(type);
	SetName(name);
	SetPosition(sf::Vector2f(x, y));
	SetworldSpace(worldSpace);
	SetIsStatic(isStatic);

	// set the floor sprite
	animations;
	Animation idle;
	Sprite* s = new Sprite();
	s->LoadTexture("Resources/Objects/Environment/ChocBlockSmall.png");
	idle.endEvent = Animation::AnimationEndEvent::HoldLastFrame;
	animations.animations["idle"] = idle;
	animations.SwitchAnimations("idle");

	collider->size = sf::Vector2f(160, 224);
}

Floor::~Floor()
{
}

void Floor::Update(float dt)
{

}

void Floor::Render(sf::RenderWindow* window)
{
	window->draw(*animations.curSprite->sprite);
}