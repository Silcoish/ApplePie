#ifndef ANIMATOR_H
#define ANIMATOR_H
#include <map>
#include "Animation.h"

class Animator
{
public:
	Sprite* curSprite = NULL;
	Animation* curAnimation = NULL;
	std::map<std::string, Animation> animations;
	int curFrame;
	float timerFrame;

	void Update(float dt);
	void NextFrame();
	void SwitchAnimations(std::string anim);
};

#endif