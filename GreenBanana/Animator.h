#include <map>
#include "Animation.h"

class Animator
{
public:
	Sprite* curSprite;
	Animation* curAnimation;
	std::map<std::string, Animation> animations;
	int curFrame;
	float timerFrame;

	void Update(float dt);
	void NextFrame();
	void SwitchAnimations(std::string& anim);
};