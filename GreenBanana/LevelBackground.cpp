#include "LevelBackground.h"

LevelBackground::LevelBackground(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth)
{
	SetType(type);
	SetName(name);
	SetPosition(sf::Vector2f(x, y));
	SetworldSpace(worldSpace);
	SetIsStatic(isStatic);
	SetDepth(depth);

	// set the floor sprite
	Animation idle;
	SpritesheetLoader loader;
	idle.sprites = loader.Load("Resources/Backgrounds/BG_w_cloud.png", 2048, 2048, 1);
	idle.endEvent = Animation::AnimationEndEvent::HoldLastFrame;
	animations.animations["idle"] = idle;
	animations.SwitchAnimations("idle");

	ScaleSprites(animations.animations, sf::Vector2f(720 * 2, 480 * 2));

	collider = new BoxCollider();
	collider->size = sf::Vector2f(3.0f, 3.0f);
	collider->isTrigger = true;
}

LevelBackground::~LevelBackground()
{
	
}

void LevelBackground::Update(float dt)
{
	
}

