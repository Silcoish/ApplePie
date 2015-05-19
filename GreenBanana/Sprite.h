#ifndef SPRITE_H
#define SPRITE_H
#include <SFML/Graphics.hpp>
#include  <SFML/Graphics/Rect.hpp>

class Sprite
{
	public:
		int width, height, depth;
		sf::Texture* texture;
		sf::Sprite* sprite;
		float animTime;
	public:
		Sprite();
		Sprite(sf::Texture* texture, sf::Rect<int> rect);
		~Sprite();
		void LoadTexture(std::string& fileLocation);
};

#endif