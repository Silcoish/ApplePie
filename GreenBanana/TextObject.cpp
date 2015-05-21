#include "TextObject.h"

TextObject::TextObject(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth)
{
	if (!font.loadFromFile("Resources/Fonts/Bubblegum.ttf"))
	{
		std::cout << "Error: Failed to load font" << std::endl;
		//Failed to load font	
	}
	text.setFont(font);

	SetType(type);
	SetName(name);
	SetPosition(sf::Vector2f(x, y));
	SetworldSpace(false);
	SetIsStatic(isStatic);
	SetDepth(depth);

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
}

void TextObject::Update(float dt)
{
	
}
