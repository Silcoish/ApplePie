#include "Player.h"
#include "Scene.h"
#include "GameManager.h"


Player::Player(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic , int depth)
{
	SetType(type);
	SetName(name);
	SetPosition(sf::Vector2f(x, y));
	SetworldSpace(worldSpace);
	SetIsStatic(isStatic);
	SetDepth(depth);

	Animation walk;
	SpritesheetLoader loader;
	walk.sprites = loader.Load("Resources/Animations/Player/Idle/Walk_cycle.png", 160, 224);
	walk.endEvent = Animation::AnimationEndEvent::Loop;
	walk.globalSpeed = 0.02;
	animations.animations["walk"] = walk;
	animations.SwitchAnimations("walk");

	collider = new BoxCollider();
	collider->size = sf::Vector2f(100,200);
}

Player::~Player()
{

}

void Player::Update(float dt)
{
	animations.Update(dt);

	
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
	else
	{
		velocity.x = 0;
	}
	//Jump
	if (timerJump < jumpTime && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		velocity.y = -1500 * dt;
		isFalling = false;
		isGrounded = false;
	}
	else
	{
		isFalling = true;
		velocity.y = 1500 * dt;
	}

	if (!isGrounded)
	{
		
		timerJump += dt;
	}

	

	//Collision Check
	std::vector<Gameobject*> allCollisions;
	bool collision = GetCurrentScene()->CollisionCheck(GetCollider(), allCollisions, velocity);

	if (velocity.y == 0 && isFalling)
	{
		timerJump = 0;
		isGrounded = true;
	}


	position += velocity;


	//SetCamPos
	GameManager::shared_instance().cameraPos = (position + sf::Vector2f(300,-100));


}