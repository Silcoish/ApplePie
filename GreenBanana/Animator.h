#include <map>
#include "Animation.h"

class Animator
{
	Sprite* curSprite;
	std::map<std::string, Animation> animations;
	int currentFrame;
	std::string currentAnimation;
	float timerFrame;

	void Update(float dt);
	void SwitchAnimations(std::string& anim);
};