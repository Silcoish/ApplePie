#include "Sprite.h"
#include <iostream>


void Sprite::Load(std::string& fileLocation)
{
	if (!sprite->loadFromFile(fileLocation))
	{
		//Error
		std::cout << "File Not Found: " << fileLocation << std::endl;

		sprite = new sf::Texture();
		sprite->create(32, 32);
		sf::Uint8* pixels = new sf::Uint8[32 * 32 * 4];

		for (size_t i = 0; i < 4096; i += 4)
		{
			pixels[i] = 0;
			pixels[i+1] = 255;
			pixels[i+2] = 140;
			pixels[i+3] = 255;
		}
		sprite->update(pixels);
	}

	width = sprite->getSize().x;
	height = sprite->getSize().y;

}