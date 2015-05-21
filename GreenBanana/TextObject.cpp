#include "TextObject.h"


TextObject::TextObject(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth)
{
	SetType(type);
	SetName(name);
	SetPosition(sf::Vector2f(x, y));
	SetworldSpace(false);
	SetIsStatic(isStatic);
	SetDepth(depth);

	if (!font.loadFromFile("Resources/Fonts/Bubblegum.ttf"))
	{
		std::cout << "Error: Failed to load font" << std::endl;
		//Failed to load font	
	}
	text.setFont(font);

	collider = new BoxCollider();
	collider->size = sf::Vector2f(100, 100);
}


TextObject::~TextObject()
{
}

void TextObject::Render(sf::RenderWindow* window)
{
	collider->center = position + sf::Vector2f(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
	text.setPosition(GetPosition());
	window->draw(text);
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

	window->draw(line, 8, sf::Lines);
}

void TextObject::Update(float dt)
{
	
}
