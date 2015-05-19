#include <vector>
#include "Sprite.h"

enum AnimationEndEvent
{
	HoldLastFrame,
	Loop
};

class Animation
{
public:
	std::vector<Sprite> sprites;
	AnimationEndEvent endEvent;

	std::string nextAnimation;
	float globalSpeed;
};