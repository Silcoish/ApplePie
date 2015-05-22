#include "SpritesheetLoader.h"
#include <iostream>
#include "GameManager.h"

std::vector<Sprite*> SpritesheetLoader::Load(std::string filePath, int spriteWidth, int spriteHeight, int frames)
{
	std::vector<Sprite*> sprites;

	Sprite* spritesheet = new Sprite();

	spritesheet->LoadTexture(GameManager::shared_instance().GetTexture(filePath));

	float f = 0;

	for (int y = 0; y < (int)spritesheet->height/ spriteHeight; y++)
	{
		for (int x = 0; x < (int)spritesheet->width / spriteWidth; x++)
		{
			Sprite* temp = new Sprite(spritesheet->texture, sf::Rect<int>(x * spriteWidth, y * spriteHeight, spriteWidth, spriteHeight));
			sprites.push_back(temp);
			f++;
			if (f >= frames)
				return sprites;
		}
	}

	return sprites;
}