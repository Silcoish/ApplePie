#include "Animator.h"
#include <iostream>

void Animator::NextFrame()
{
	if (curFrame == curAnimation->sprites.size() - 1)
	{
		switch (curAnimation->endEvent)
		{
		case AnimationEndEvent::HoldLastFrame:
			break;
		case AnimationEndEvent::Loop:
			curFrame = 0;
			break;
		}
	}
	else
	{
		curFrame ++;
	}

}

void Animator::Update(float dt)
{
	timerFrame += dt;

	if (timerFrame > curSprite->animTime )
	{
		NextFrame();
		curSprite = curAnimation->sprites[curFrame];
	}

}
void Animator::SwitchAnimations(std::string& anim)
{
	auto loc = animations.find(anim);
	if (loc != animations.end())
	{
		curAnimation = &loc->second;
	}
	else
	{
		std::cout << "Animation Not Found: " << anim << std::endl;
	}

	curFrame = 0;
	timerFrame = 0;
	curSprite = curAnimation->sprites[curFrame];
}
