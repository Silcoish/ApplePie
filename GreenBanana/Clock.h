//#ifndef CLOCK_H
//#define CLOCK_H
//
//#include <SFML/Graphics.hpp>
//#include "TextObject.h"
//#include "GameManager.h"
//
//
//class Clock
//{
//public:
//	TextObject(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth);
//	virtual ~TextObject();
//
//	//std::string GetName() { return name; };
//	//sf::Text GetString() { return text.getString; };
//	//sf::Vector2f GetPosition() { return text.getPosition(); };
//
//	sf::Text text;
//	void SetPosition(sf::Vector2f newPos) { position = newPos; };
//	sf::Vector2f GetPosition() { return position; }
//	virtual void Render(sf::RenderWindow* window);
//	void Update(float dt);
//
//protected:
//	std::string name;
//
//	sf::Font font;
//
//};
//
//#endif