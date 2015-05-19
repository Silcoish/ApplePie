#include "Animator.h"

void Animator::Update(float dt)
{
	timerFrame += dt;

	if (timerFrame < animations[currentAnimation].sprites[currentFrame].animTime)
	{
		curSprite = &animations[currentAnimation];
	}
	else
	{
		//if ()

	}

}
void Animator::SwitchAnimations(std::string& anim)
{
	currentAnimation = anim;
	currentFrame = 0;
	timerFrame = 0;
}
