#include "Player.h"
#include "Scene.h"


Player::Player(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic)
{
	SetType(type);
	SetName(name);
	SetPosition(sf::Vector2f(x, y));
	SetworldSpace(worldSpace);
	SetIsStatic(isStatic);

	Animation walk;
	SpritesheetLoader loader;
	walk.sprites = loader.Load("Resources/Animations/Player/Idle/Walk_cycle.png", 160, 224);
	walk.endEvent = Animation::AnimationEndEvent::Loop;
	animations.animations["walk"] = walk;
	animations.SwitchAnimations("walk");

	collider = new BoxCollider();
	collider->size = sf::Vector2f(160,224);
}

Player::~Player()
{

}

void Player::Update(float dt)
{
	animations.Update(dt);
	collider->center = position + sf::Vector2f(animations.curSprite->width / 2, animations.curSprite->height / 2);
	
	//Input
	//Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x = -walkSpeed * dt;

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x = walkSpeed * dt;
	}
	//Jump
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{


	}

	
	//Collision Check
	std::vector<Gameobject*> allCollisions;
	bool hitVertical = GetCurrentScene()->CollisionCheck(GetCollider(), allCollisions, sf::Vector2f(0, velocity.y));
	bool hitHorzontal = GetCurrentScene()->CollisionCheck(GetCollider(), allCollisions, sf::Vector2f(0, velocity.y));


	

}