#include "Sprite.h"
#include <iostream>

Sprite::Sprite()
{
	texture = new sf::Texture();
	sprite = new sf::Sprite();
}

Sprite::Sprite(sf::Texture* txtr, sf::Rect<int> rect)
{
	texture = new sf::Texture();
	sprite = new sf::Sprite();

	sprite->setTexture(*txtr);
	sprite->setTextureRect(rect);

	width = rect.width;
	height = rect.height;
}

Sprite::~Sprite()
{
	delete sprite;
	delete texture;
}

void Sprite::LoadTexture(std::string fileLocation)
{
	if (!texture->loadFromFile(fileLocation))
	{
		//Error
		std::cout << "File Not Found: " << fileLocation << std::endl;

		texture = new sf::Texture();
		texture->create(32, 32);
		sf::Uint8* pixels = new sf::Uint8[32 * 32 * 4];

		for (size_t i = 0; i < 4096; i += 4)
		{
			pixels[i] = 0;
			pixels[i + 1] = 255;
			pixels[i + 2] = 140;
			pixels[i + 3] = 255;
		}
		texture->update(pixels);
	}

	sprite->setTexture(*texture);

	width = texture->getSize().x;
	height = texture->getSize().y;
}

