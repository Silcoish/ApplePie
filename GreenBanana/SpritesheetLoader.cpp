#include "SpritesheetLoader.h"
#include <iostream>

std::vector<Sprite*> SpritesheetLoader::Load(std::string filePath, int spriteWidth, int spriteHeight)
{
	std::vector<Sprite*> sprites;

	Sprite* spritesheet = new Sprite();
	spritesheet->LoadTexture(filePath);

	for (int y = 0; y < (int)spritesheet->height/ spriteHeight; y++)
	{
		for (int x = 0; x < (int)spritesheet->width / spriteWidth; x++)
		{
			Sprite* temp = new Sprite(spritesheet->texture, sf::Rect<int>(x * spriteWidth, y * spriteHeight, spriteWidth, spriteHeight));
			sprites.push_back(temp);
		}
	}

	return sprites;
}