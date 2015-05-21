#include "MenuScene.h"
#include "GameManager.h"


MenuScene::MenuScene(std::string filepath)
{
	SetFilePath(filepath);
	Parse();
	titleText = new TextObject("text", "Title", -540, -258, 0, 1, 100);
	titleText->text.setString("JUST DESSERTS");
	titleText->text.setScale(sf::Vector2f(5, 5));
	titleText->text.setColor(sf::Color::Blue);
	objectsInScene.push_back(titleText);

	continueText = new TextObject("text", "Title", -330, 0, 0, 1, 100);
	continueText->text.setString("Press Space to Begin");
	continueText->text.setScale(sf::Vector2f(2, 2));
	continueText->text.setColor(sf::Color::Blue);
	objectsInScene.push_back(continueText);
}


MenuScene::~MenuScene()
{
}

void MenuScene::Render(sf::RenderWindow* window)
{
	for (auto it = objectsInScene.begin(); it != objectsInScene.end(); ++it)
	{
		(*it)->Render(window);
	}
}

void MenuScene::SceneLogic(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		GameManager::shared_instance().ChangeScene(GameManager::shared_instance().GAME);
		GameManager::shared_instance().ReloadScene(GameManager::shared_instance().GAME);
		Unload();
	}
}