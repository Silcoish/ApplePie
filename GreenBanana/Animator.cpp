#include "Animator.h"
#include <iostream>

void Animator::NextFrame()
{
	if (curFrame == curAnimation->sprites.size() - 1)
	{
		switch (curAnimation->endEvent)
		{
		case Animation::AnimationEndEvent::HoldLastFrame:
			break;
		case Animation::AnimationEndEvent::Loop:
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

	int count = 0;

	if (curAnimation->globalSpeed == 0)
	{
		NextFrame();
	}
	else
	{
		while (timerFrame > curAnimation->globalSpeed)
		{
			timerFrame -= curAnimation->globalSpeed;
			NextFrame();
			curSprite = curAnimation->sprites[curFrame];

			count++;
			if (count > 10)
			{
				std::cout << "Animation Broken" << std::endl;
				break;
			}
		}
	}

}
void Animator::SwitchAnimations(std::string anim)
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
