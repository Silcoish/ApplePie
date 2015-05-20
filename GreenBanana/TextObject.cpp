#include "TextObject.h"


TextObject::TextObject(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic)
{
	SetType(type);
	SetName(name);
	SetPosition(sf::Vector2f(x, y));
	SetworldSpace(worldSpace);
	SetIsStatic(isStatic);

	if (!font.loadFromFile("Resources/Fonts/Bubblegum.ttf"))
	{
		//Failed to load font	
	}
	text.setFont(font);
	text.setString("Press 1 to Jason");
}


TextObject::~TextObject()
{
}

void TextObject::Render(sf::RenderWindow* window)
{
	window->draw(text);
}

void TextObject::Update(float dt)
{

}
