#include "Lollipop.h"

Lollipop::Lollipop(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth)
{	
	SetType(type);
	SetName(name);
	SetPosition(sf::Vector2f(x, y));
	SetworldSpace(worldSpace);
	SetIsStatic(isStatic);
	SetDepth(depth);

	int i = (std::rand() % 8) + 1;
	std::stringstream ss;
	ss << "Resources/Objects/Environment/Lollypop";
	ss << i;
	ss << ".png";

	//std::srand(std::rand());

	Animation walk;
	SpritesheetLoader loader;
	walk.sprites = loader.Load(ss.str(), 225, 439, 1);
	walk.endEvent = Animation::AnimationEndEvent::HoldLastFrame;
	walk.globalSpeed = 0.02;
	animations.animations["walk"] = walk;
	animations.SwitchAnimations("walk");


	collider = new BoxCollider();
	collider->size = sf::Vector2f(230, 443);
	collider->isTrigger = true;
}

Lollipop::~Lollipop()
{
}

void Lollipop::Update(float dt)
{
	animations.Update(dt);

	collider->center = position + sf::Vector2f(animations.curSprite->width / 2, animations.curSprite->height / 2);
}
