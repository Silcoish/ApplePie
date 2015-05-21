#ifndef ANIMATION_H
#define ANIMATION_H
#include <vector>
#include "Sprite.h"

class Animation
{
public:
	std::string name;
	std::vector<Sprite*> sprites;
	enum AnimationEndEvent
	{
		HoldLastFrame,
		Loop
	};
	AnimationEndEvent endEvent;

	std::string nextAnimation;
	float globalSpeed = 0;
};

#endif