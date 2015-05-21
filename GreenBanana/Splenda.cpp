#include "Splenda.h"

Splenda::Splenda(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth)
{
	SetType(type);
	SetName(name);
	SetPosition(sf::Vector2f(x, y));
	SetworldSpace(worldSpace);
	SetIsStatic(isStatic);
	SetDepth(depth);

	Animation walk;
	SpritesheetLoader loader;
	walk.sprites = loader.Load("Resources/Animations/BadSugar/sugar.png", 152, 170, 90);
	walk.endEvent = Animation::AnimationEndEvent::Loop;
	walk.globalSpeed = 0.02;
	animations.animations["walk"] = walk;
	animations.SwitchAnimations("walk");

	startPos = sf::Vector2f(x, y);

	collider = new BoxCollider();
	collider->size = sf::Vector2f(130, 140);
	collider->isTrigger = false;
}

Splenda::~Splenda()
{
}

void Splenda::Update(float dt)
{
	animations.Update(dt);
	collider->center = position + sf::Vector2f(animations.curSprite->width / 2, animations.curSprite->height / 2 + 10);

	if (direction == IDLE)
	{
		counter += dt;

		if (counter >= timer)
		{
			//Falling
			direction = DOWN;
		}
	}

	if (direction == DOWN)
	{
		//Moving Downwards
		std::cout << "down" << std::endl;
		vel.y = 600 * dt;
	}

	if (direction == UP)
	{
		//Moving Downwards
		std::cout << "up" << std::endl;
		vel.y = -600 * dt;
	}


	std::vector<Gameobject*> allCollisions;
	bool collision = GetCurrentScene()->CollisionCheck(GetCollider(), allCollisions, vel);

	if (collision)
	{
		if (direction == DOWN)
			direction = UP;
		else if (direction == UP)
		{
			direction = IDLE;
			counter = 0;
		}
	}
	else
	{
		position += vel;
	}

}
