#include "TextObject.h"


TextObject::TextObject(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth)
{
	SetType(type);
	SetName(name);
	SetPosition(sf::Vector2f(x, y));
	SetworldSpace(worldSpace);
	SetIsStatic(isStatic);
	SetDepth(depth);

	if (!font.loadFromFile("Resources/Fonts/Bubblegum.ttf"))
	{
		std::cout << "Error: Failed to load font" << std::endl;
		//Failed to load font	
	}
	text.setFont(font);
	text.setString("Press 1 to Jason");

	collider = new BoxCollider();
	collider->size = sf::Vector2f(0,0);
}


TextObject::~TextObject()
{
}

void TextObject::Render(sf::RenderWindow* window)
{
	text.setPosition(GetPosition());
	window->draw(text);
}

void TextObject::Update(float dt)
{
	
}
