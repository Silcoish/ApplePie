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

	startPosition = sf::Vector2f(x, y);

	SpritesheetLoader loader;

	Animation idle;
	idle.name = "idle";
	idle.sprites = loader.Load("Resources/Animations/Player/idle.png", 144, 214, 26);
	idle.endEvent = Animation::AnimationEndEvent::Loop;
	idle.globalSpeed = 0.02;
	animations.animations["idle"] = idle;

	Animation walk;
	walk.name = "walk";
	walk.sprites = loader.Load("Resources/Animations/Player/Walk_cycle.png", 160, 224, 90);
	walk.endEvent = Animation::AnimationEndEvent::Loop;
	walk.globalSpeed = 0.02;
	animations.animations["walk"] = walk;

	Animation sleep;
	sleep.name = "sleep";
	sleep.sprites = loader.Load("Resources/Animations/Player/sleep.png", 232, 224, 36);
	sleep.endEvent = Animation::AnimationEndEvent::Loop;
	sleep.globalSpeed = 0.02;
	animations.animations["sleep"] = sleep;

	Animation death;
	death.name = "death";
	death.sprites = loader.Load("Resources/Animations/Player/death.png", 320, 232, 47);
	death.endEvent = Animation::AnimationEndEvent::HoldLastFrame;
	death.globalSpeed = 0.02;
	animations.animations["death"] = death;

	Animation jump;
	jump.name = "jump";
	jump.sprites = loader.Load("Resources/Animations/Player/jumpShort.png", 160, 224, 11);
	jump.endEvent = Animation::AnimationEndEvent::HoldLastFrame;
	jump.globalSpeed = 0.02;
	animations.animations["jump"] = jump;



	animations.SwitchAnimations("sleep");

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
	invincibleCounter += dt;

	std::string curAnimName = animations.curAnimation->name;

	if (isDead)
	{
		if (curAnimName != "death")
			animations.SwitchAnimations("death");

		timerDeath += dt;

		if (timerDeath > 3)
		{
			GameManager::shared_instance().ChangeScene(GameManager::GameStates::UPGRADE);
		}
	}
	else
	{
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

		//Check if Pickup Coin
		for (auto it = allCollisions.begin(); it != allCollisions.end(); it++)
		{
			if ((*it)->GetName() == "coin" && (*it)->GetCollider()->size.x > 0)
			{
				if (health < 20)
				{
					//Add 1 health
					health++;
					UpdateHealthObjects(health);

				}
				else
				{
					//Add to money for spending
					GameManager::shared_instance().upgradeData.coins++;
					std::cout << GameManager::shared_instance().upgradeData.coins << std::endl;

				}
				(*it)->GetAnimator().SwitchAnimations("healthDestroyed");
				//(*it)->GetCollider()->size = sf::Vector2f(0, 0);
				(*it)->SetPosition(sf::Vector2f(5000 + std::rand() % 1000, 5000 + std::rand() % 1000));
			}
			else if ((*it)->GetType() == "trap" && (*it)->GetCollider()->size.x > 0)
			{
				if (invincibleCounter >= invincibleTimer)
				{
					health -= 4;
					UpdateHealthObjects(health);
					invincibleCounter = 0;
				}
			}
			else if ((*it)->GetType() == "splenda" && (*it)->GetCollider()->size.x > 0)
			{
				if (invincibleCounter >= invincibleTimer)
				{
					health -= 4;
					UpdateHealthObjects(health);
					invincibleCounter = 0;
				}
			}
		}

		//Rotate Sprite
		//if (velocity.x > 0)
		//{

		//	sf::Vector2f curScale = animations.curSprite->sprite->getScale();
		//	curScale.x = abs(curScale.x);
		//	animations.curSprite->sprite->
		//}
		//else if (velocity.x < 0)
		//{
		//	sf::Vector2f curScale = animations.curSprite->sprite->getScale();
		//	curScale.x = abs(curScale.x) * (-1);
		//	animations.curSprite->sprite->setScale(curScale);
		//}





		//Set Anmiations
		if (timerJump < jumpTime && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (curAnimName != "jump")
				animations.SwitchAnimations("jump");
		}
		if (isGrounded)
		{

			if (abs(velocity.x) > 0)
			{
				if (curAnimName != "walk")
					animations.SwitchAnimations("walk");
			}
			else
			{
				if (curAnimName != "idle" && curAnimName != "sleep")
					animations.SwitchAnimations("idle");
			}
		}


		position += velocity;

		//Run CLock
		if (curAnimName != "sleep")
		{
			GameManager::shared_instance().globalClockSpeed = ((6 - (health / 4)) * 2) - 1;
			GameManager::shared_instance().upgradeData.clock -= (dt * GameManager::shared_instance().globalClockSpeed);

			if (GameManager::shared_instance().upgradeData.clock <= 0)
			{
				isDead = true;
			}
		}


		//SetCamPos
		GameManager::shared_instance().cameraPos = (position + sf::Vector2f(300, -100));
	}

}

void Player::Render(sf::RenderWindow* rw)
{
	collider->center = position + sf::Vector2f(75, 100);

	animations.curSprite->sprite->setPosition(GetPosition());


	if (GetworldSpace())
	{
		animations.curSprite->sprite->setPosition(GetPosition());
		rw->draw(*animations.curSprite->sprite);
	}
	else
	{
		collider->center += GameManager::shared_instance().cameraPos;
		animations.curSprite->sprite->setPosition(GetPosition() + GameManager::shared_instance().cameraPos);
		rw->draw(*animations.curSprite->sprite);
	}

	if (GameManager::shared_instance().showBoxColliders)
	{
		sf::Vertex line[] = { sf::Vertex(sf::Vector2f(collider->center.x - collider->size.x / 2, collider->center.y - collider->size.y / 2)),
			sf::Vertex(sf::Vector2f(collider->center.x + collider->size.x / 2, collider->center.y - collider->size.y / 2)),

			sf::Vertex(sf::Vector2f(collider->center.x + collider->size.x / 2, collider->center.y - collider->size.y / 2)),
			sf::Vertex(sf::Vector2f(collider->center.x + collider->size.x / 2, collider->center.y + collider->size.y / 2)),

			sf::Vertex(sf::Vector2f(collider->center.x + collider->size.x / 2, collider->center.y + collider->size.y / 2)),
			sf::Vertex(sf::Vector2f(collider->center.x - collider->size.x / 2, collider->center.y + collider->size.y / 2)),

			sf::Vertex(sf::Vector2f(collider->center.x - collider->size.x / 2, collider->center.y + collider->size.y / 2)),
			sf::Vertex(sf::Vector2f(collider->center.x - collider->size.x / 2, collider->center.y - collider->size.y / 2)) };

		line[0].color = sf::Color(0, 255, 0, 225);
		line[1].color = sf::Color(0, 255, 0, 225);
		line[2].color = sf::Color(0, 255, 0, 225);
		line[3].color = sf::Color(0, 255, 0, 225);
		line[4].color = sf::Color(0, 255, 0, 225);
		line[5].color = sf::Color(0, 255, 0, 225);
		line[6].color = sf::Color(0, 255, 0, 225);
		line[7].color = sf::Color(0, 255, 0, 225);

		rw->draw(line, 8, sf::Lines);
	}
}

void Player::ResetObject()
{
	position = startPosition;
	health = 20;
}