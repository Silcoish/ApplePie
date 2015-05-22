#include "Bag.h"
#include "GameManager.h"

Bag::Bag(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth)
{
	SetType(type);
	SetName(name);
	SetPosition(sf::Vector2f(x, y));
	SetStartPosition(sf::Vector2f(x, y));
	SetworldSpace(worldSpace);
	SetIsStatic(isStatic);
	SetDepth(depth);


	SpritesheetLoader loader;

	Animation bag;
	bag.sprites = loader.Load("Resources/Objects/SugerBag.png", 480, 510, 1);
	bag.endEvent = Animation::AnimationEndEvent::HoldLastFrame;
	bag.globalSpeed = 0.02;
	bag.nextAnimation = "bag";
	animations.animations["bag"] = bag;

	ScaleSprites(animations.animations, sf::Vector2f(70, 60));

	animations.SwitchAnimations("bag");

	collider = new BoxCollider();
	collider->size = sf::Vector2f(animations.curSprite->width, animations.curSprite->height);
	collider->isTrigger = true;

	//Add to health objects
	GameManager::shared_instance().healthObjects.push_back(this);

}

Bag::~Bag()
{
}

void Bag::Update(float dt)
{
	//animations.Update(dt);
}