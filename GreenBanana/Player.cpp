#include "Player.h"
#include "Scene.h"
#include "GameManager.h"
#include "InputManager.h"


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
	walk.sprites = loader.Load("Resources/Animations/Player/Idle/Walk_cycle.png", 160, 224, 90);
	walk.endEvent = Animation::AnimationEndEvent::Loop;
	walk.globalSpeed = 0.02;
	animations.animations["walk"] = walk;
	animations.SwitchAnimations("walk");

	collider = new BoxCollider();
	collider->size = sf::Vector2f(100,200);

	health = 20;
	walkSpeed = 400;
	jumpTime = 0.3;
	isGrounded = true;
	isFalling = false;
	timerJump = 0;
}

Player::~Player()
{

}

void UpdateHealthObjects(int health)
{

	std::vector<Gameobject*> healthObjs = GameManager::shared_instance().healthObjects;

	for (size_t i = 0; i < healthObjs.size(); i++)
	{
		if (i < health)
		{
			GameManager::shared_instance().healthObjects[i]->GetAnimator().SwitchAnimations("healthFull");
		}
		else
		{
			GameManager::shared_instance().healthObjects[i]->GetAnimator().SwitchAnimations("healthEmpty");
		}
	}
}

void Player::Update(float dt)
{
	if (dt > 0.2)
		return;
	animations.Update(dt);

	InputMapper input = InputMapper::shared_instance();

	if (input.curState["P"] && !input.prevState["P"])
	{
		health -= 4;
		std::cout << "Health Down: " << health << std::endl;

		//Update Health Display
		UpdateHealthObjects(health);

	}
	if (input.curState["O"] && !input.prevState["O"])
	{
		health += 1;
		std::cout << "Health Up: " << health << std::endl;

		//Update Health Display
		UpdateHealthObjects(health);
	}

	




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