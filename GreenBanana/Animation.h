#include <vector>
#include "Sprite.h"

class Animation
{
public:
	std::vector<Sprite*> sprites;
	enum AnimationEndEvent
	{
		HoldLastFrame,
		Loop
	};
	AnimationEndEvent endEvent;

	std::string nextAnimation;
	float globalSpeed;
};