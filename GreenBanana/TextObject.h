#pragma once
#include "Gameobject.h"
#include <string>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class TextObject : public Gameobject
{
public:
	TextObject(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic);
	~TextObject();

	//std::string GetName() { return name; };
	//sf::Text GetString() { return text.getString; };
	//sf::Vector2f GetPosition() { return text.getPosition(); };
	
	void SetPosition(sf::Vector2f newPos) { text.setPosition(newPos); };
	void Render(sf::RenderWindow* window);
	void Update(float dt);
	sf::Text text;

protected:
	std::string name;

	sf::Font font;

};

