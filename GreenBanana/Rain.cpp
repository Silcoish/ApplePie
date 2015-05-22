#include "Rain.h"
#include "GameManager.h"

Rain::Rain(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth)
{
	SetType(type);
	SetName(name);
	SetPosition(sf::Vector2f(x, y));
	SetStartPosition(sf::Vector2f(x, y));
	SetworldSpace(worldSpace);
	SetIsStatic(isStatic);
	SetDepth(-10);


	SpritesheetLoader loader;

	int i = (std::rand() % 4) + 1;
	std::stringstream ss;
	ss << "Resources/Objects/Rain/Rain_";
	ss << i;
	ss << ".png";

	Animation rain;
	rain.sprites = loader.Load(ss.str(), 180, 220, 1);
	rain.endEvent = Animation::AnimationEndEvent::HoldLastFrame;
	rain.globalSpeed = 0.02;
	rain.nextAnimation = "rain";
	animations.animations["rain"] = rain;

	int j = (std::rand() % 6) + 5;
	ScaleSprites(animations.animations, (((float)j/25)));

	animations.SwitchAnimations("rain");

	collider = new BoxCollider();
	collider->size = sf::Vector2f(0,0);
	collider->isTrigger = true;
}

Rain::~Rain()
{
}

void Rain::Update(float dt)
{
	if (dt < 0.2)
	{
		sf::Vector2f moveDir = GetPosition();
		moveDir += (sf::Vector2f(-100, 250) * (dt * GameManager::shared_instance().globalClockSpeed));
		SetPosition(moveDir);


		//Delete obvject after a while
		if (GetPosition().y > 1000)
		{
			int i = (std::rand() % 20) + 1;
			SetPosition(sf::Vector2f(GameManager::shared_instance().cameraPos.x + (i * 100) - 800, -1000));
		}
	}
}