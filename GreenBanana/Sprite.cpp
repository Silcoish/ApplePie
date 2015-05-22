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

void Sprite::LoadTexture(sf::Texture * txtxtx)
{
	
	texture = txtxtx;

	sprite->setTexture(*txtxtx);

	width = texture->getSize().x;
	height = texture->getSize().y;
}

