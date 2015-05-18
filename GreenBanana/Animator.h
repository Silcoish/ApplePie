#include <map>
class Animator
{
	std::map<std::string, Animation> animations;
	int currentFrame;
	std::string currentAnimation;
	float timerFrame;

	void Update();
	void SwitchAnimations(std::string& anim);
};