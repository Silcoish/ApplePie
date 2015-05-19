#include "SpritesheetLoader.h"

std::vector<Sprite*> SpritesheetLoad::Load(std::string filename, int spriteWidth, int spriteHeight)
{
	std::vector<Sprite*> sprites;

	Sprite* spritesheet = new Sprite();
	spritesheet->LoadTexture(filename);

	for (int y = 0; y < (int)spritesheet->height/ spriteHeight; y++)
	{
		for (int x = 0; x < (int)spritesheet->width / spriteWidth; x++)
		{
			sprites.push_back(new Sprite(spritesheet->texture, sf::Rect<int>(x * spriteWidth, y * spriteHeight, spriteWidth, spriteHeight)));
		}
	}

	return sprites;
}