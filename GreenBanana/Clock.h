#ifndef CLOCK_H
#define CLOCK_H

#include <SFML/Graphics.hpp>
#include "TextObject.h"
#include "GameManager.h"


class Clock
{
public:
	TextObject* text = NULL;
	float time = 0;

public:
	Clock();
	~Clock();

	void Update(float dt);
	void Render(sf::RenderWindow* rw);

};

#endif