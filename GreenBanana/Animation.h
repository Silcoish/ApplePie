#include <vector>

enum AnimationEndEvent
{
	HoldLastFrame,
	Loop
};

class Animation
{
	std::vector<Sprite> sprites;
	AnimationEndEvent endEvent;

	std::string nextAnimation;
	float globalSpeed;
};