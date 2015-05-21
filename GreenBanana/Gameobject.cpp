#include "Gameobject.h"
#include "GameManager.h"

Gameobject::~Gameobject()
{

}

std::string Gameobject::Serialize()
{
	std::stringstream ss;
	ss << GetType();
	ss << ",";
	ss << GetName();
	ss << ",";
	ss << GetPosition().x;
	ss << ",";
	ss << GetPosition().y;
	ss << ",";
	ss << GetworldSpace();
	ss << ",";
	ss << GetIsStatic();
	ss << ",";
	ss << GetDepth();
	ss << std::endl;

	return ss.str();
}

sf::Vector2f Gameobject::GetSize()
{
	if (animations.curSprite != nullptr)
	{
		return sf::Vector2f(animations.curSprite->width, animations.curSprite->height);
	}

	return sf::Vector2f(0, 0);
}

void Gameobject::Update(float dt)
{
	
}

void Gameobject::Render(sf::RenderWindow* rw)
{
	collider->center = position + sf::Vector2f(animations.curSprite->width / 2, animations.curSprite->height / 2);

	animations.curSprite->sprite->setPosition(GetPosition());
	rw->draw(*animations.curSprite->sprite);


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