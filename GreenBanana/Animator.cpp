#include "Animator.h"

void Animator::NextFrame()
{
	if (currentFrame == animations[currentAnimation].sprites.size())
	{
		switch (animations[currentAnimation].endEvent)


	}

}

void Animator::Update(float dt)
{
	timerFrame += dt;

	if (timerFrame < animations[currentAnimation].sprites[currentFrame].animTime)
	{
		curSprite = &animations[currentAnimation];
	}
	else
	{
		NextFrame(this);

	}

}
void Animator::SwitchAnimations(std::string& anim)
{
	currentAnimation = anim;
	currentFrame = 0;
	timerFrame = 0;
}
