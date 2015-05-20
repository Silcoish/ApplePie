#include "Player.h"

Player::Player(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic)
{
	SetType(type);
	SetName(name);
	SetPosition(sf::Vector2f(x, y));
	SetworldSpace(worldSpace);
	SetIsStatic(isStatic);

	animations;
	Animation walk;
	SpritesheetLoader loader;
	walk.sprites = loader.Load("Resources/Animations/Player/Idle/Walk_cycle.png", 160, 224);
	walk.endEvent = Animation::AnimationEndEvent::Loop;
	animations.animations["walk"] = walk;
	animations.SwitchAnimations("walk");

	collider.size = sf::Vector2f(160,224);
}

Player::~Player()
{

}

void Player::Update(float dt)
{
	//std::cout << "Update" << std::endl;
	animations.Update(dt);

	collider.center = position + sf::Vector2f(animations.curSprite->width / 2, animations.curSprite->height / 2);


}

void Player::Render(sf::RenderWindow* window)
{
	animations.curSprite->sprite->setPosition (GetPosition());
	window->draw(*animations.curSprite->sprite);

	sf::Vertex line[] = {	sf::Vertex(sf::Vector2f(collider.center.x - collider.size.x / 2, collider.center.y - collider.size.y / 2)), 
							sf::Vertex(sf::Vector2f(collider.center.x + collider.size.x / 2, collider.center.y - collider.size.y / 2)), 

							sf::Vertex(sf::Vector2f(collider.center.x + collider.size.x / 2, collider.center.y - collider.size.y / 2)),
							sf::Vertex(sf::Vector2f(collider.center.x + collider.size.x / 2, collider.center.y + collider.size.y / 2)), 

							sf::Vertex(sf::Vector2f(collider.center.x + collider.size.x / 2, collider.center.y + collider.size.y / 2)),
							sf::Vertex(sf::Vector2f(collider.center.x - collider.size.x / 2, collider.center.y + collider.size.y / 2)), 

							sf::Vertex(sf::Vector2f(collider.center.x - collider.size.x / 2, collider.center.y + collider.size.y / 2)),
							sf::Vertex(sf::Vector2f(collider.center.x - collider.size.x / 2, collider.center.y - collider.size.y / 2)) };

	line[0].color = sf::Color(0, 255, 0, 225);
	line[1].color = sf::Color(0, 255, 0, 225);
	line[2].color = sf::Color(0, 255, 0, 225);
	line[3].color = sf::Color(0, 255, 0, 225);
	line[4].color = sf::Color(0, 255, 0, 225);
	line[5].color = sf::Color(0, 255, 0, 225);
	line[6].color = sf::Color(0, 255, 0, 225);
	line[7].color = sf::Color(0, 255, 0, 225);

	window->draw(line, 8, sf::Lines);
}
