#include "Clock.h"

Clock::Clock()
{
	text = new TextObject("text", "clock", 10, 10, 0, 0, 100);
	text->text.setString("Clock");
}

void Clock::Update(float dt)
{
	text->Update(dt);

	time += dt;

	std::cout << "Clock time: " << time << " / " << GameManager::shared_instance().upgradeData.clock << std::endl;

	if (time >= GameManager::shared_instance().upgradeData.clock)
	{
		//GameManager::shared_instance().ReloadScene(GameManager::shared_instance().GAME);
		//GameManager::shared_instance().ChangeScene(GameManager::shared_instance().GAME);
	}
}

void Clock::Render(sf::RenderWindow* rw)
{
	text->Render(rw);
}