#pragma once
#include <string>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class TextObject
{
public:
	TextObject();
	~TextObject();

	std::string GetName() { return name; };
	sf::Text GetString() { return text.getString; };
	sf::Vector2f GetPosition() { return text.getPosition(); };
	
	void SetPosition(sf::Vector2f newPos) { text.setPosition(newPos); };
	//void SetScale(float newScale) { text.setScale(newScale); };

protected:
	std::string name;
	sf::Text text;

};

