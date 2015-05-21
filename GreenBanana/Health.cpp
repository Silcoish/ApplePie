#include "Health.h"
#include "GameManager.h"

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
	healthFull.globalSpeed = 0.02;
	healthFull.nextAnimation = "healthFull";
	animations.animations["healthFull"] = healthFull;

	Animation healthEmpty;
	healthEmpty.sprites = loader.Load("Resources/Objects/HealthObjects/sugar_Empty.png", 144, 124, 1);
	healthEmpty.endEvent = Animation::AnimationEndEvent::HoldLastFrame;
	healthEmpty.globalSpeed = 0.02;
	healthEmpty.nextAnimation = "healthEmpty";
	animations.animations["healthEmpty"] = healthEmpty;

	ScaleSprites(animations.animations, sf::Vector2f(70,60));

	animations.SwitchAnimations("healthEmpty");
	//animations.SwitchAnimations("healthFull");

	collider = new BoxCollider();
	collider->size = sf::Vector2f(animations.curSprite->width, animations.curSprite->height);
	collider->isTrigger = false;

	//Add to health objects
	GameManager::shared_instance().healthObjects.push_back(this);
	
}

Health::~Health()
{
}

void Health::Update(float dt)
{
	animations.Update(dt);
}