#include "Health.h"

Health::Health(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth)
{
	SetType(type);
	SetName(name);
	SetPosition(sf::Vector2f(x, y));
	SetworldSpace(worldSpace);
	SetIsStatic(isStatic);
	SetDepth(depth);

	Animation idle;
	SpritesheetLoader loader;
	idle.sprites = loader.Load("Resources/Objects/CandyCaneBroke.png", 54, 336, 1);
	idle.endEvent = Animation::AnimationEndEvent::HoldLastFrame;
	idle.sprites[0]->sprite->setScale(sf::Vector2f((60 / 54), (340 / 336)));
	idle.sprites[0]->width = 60;
	idle.sprites[0]->height = 340;
	animations.animations["idle"] = idle;
	animations.SwitchAnimations("idle");

	collider = new BoxCollider();
	collider->size = sf::Vector2f(animations.curSprite->width, animations.curSprite->height);
	collider->isTrigger = false;
}

Health::~Health()
{
}

void Health::Update(float dt)
{

}