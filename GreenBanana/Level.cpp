#include "Level.h"
#include "Player.h"
#include "Floor.h"
#include "TextObject.h"

Level::Level(std::string filePath)
{
	SetFilePath(filePath);
	Parse();
}

Level::~Level()
{
	
}

void Level::Update(float dt)
{
	//editor shit
	if (GameManager::shared_instance().editor)
	{
		sf::Vector2f pos = GameManager::shared_instance().rw->mapPixelToCoords(sf::Mouse::getPosition(*GameManager::shared_instance().rw));
		if (currentObject != nullptr) currentObject->SetPosition(sf::Vector2f(pos.x - currentObject->GetSize().x / 2, pos.y - currentObject->GetSize().y / 2));
		
		//Key pressed, make new objects
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			if (currentObject == nullptr)
			{
				Player* player = new Player("player", "player", pos.x - 80, pos.y - 112, 1, 0);
				player->SetCurrentScene(this);
				currentObject = player;
				objectsInScene.push_back(player);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			if (currentObject == nullptr)
			{
				Floor* floor = new Floor("floor", "floor", pos.x, pos.y, 1, 1);
				floor->SetCurrentScene(this);
				currentObject = floor;
				objectsInScene.push_back(floor);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			if (currentObject == nullptr)
			{
				TextObject* text = new TextObject("text", "text", pos.x, pos.y, 1, 1);
				text->SetCurrentScene(this);
				text->text.setString("working");
				currentObject = text;
				objectsInScene.push_back(text);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			GameManager::shared_instance().cameraPos.x -= GameManager::shared_instance().cameraMoveSpeed * dt;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			GameManager::shared_instance().cameraPos.x += GameManager::shared_instance().cameraMoveSpeed * dt;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			GameManager::shared_instance().cameraPos.y -= GameManager::shared_instance().cameraMoveSpeed * dt;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			GameManager::shared_instance().cameraPos.y += GameManager::shared_instance().cameraMoveSpeed * dt;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
			GameManager::shared_instance().cameraMoveSpeed += 50.0f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
			GameManager::shared_instance().cameraMoveSpeed -= 50.0f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
			GameManager::shared_instance().cameraPos = sf::Vector2f(0.0f,0.0f);
		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete))
		{
			if (currentObject != nullptr)
			{
				auto it = std::find(objectsInScene.begin(), objectsInScene.end(), currentObject);
				if (it == objectsInScene.end())
				{
					// name not in vector
					std::cout << "ERROR: cannot delete object as it doesn't exist!" << std::endl;
				}
				else
				{
					auto index = std::distance(objectsInScene.begin(), it);
					objectsInScene.erase(objectsInScene.begin() + index);
					currentObject = nullptr;
				}
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			std::fstream out("Resources/SceneData/testgame.txt", std::ios::out);
			for (auto it = objectsInScene.begin(); it != objectsInScene.end(); ++it)
			{
				out << (*it)->Serialize();
				std::cout << "Save complete" << std::endl;
			}
		}
		
		//Mouse release, place object
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (currentObject != nullptr)
				currentObject = NULL;
			else
			{
				std::vector<Gameobject*> allCollisions;
				BoxCollider* mouseBox = new BoxCollider();
				mouseBox->center = sf::Vector2f(pos.x, pos.y);
				mouseBox->size = sf::Vector2f(10.0f, 10.0f);
				bool temp = CollisionCheck(mouseBox, allCollisions);

				if (temp)
				{
					currentObject = *allCollisions.begin();
				}
			}
		}
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		GameManager::shared_instance().editor = !GameManager::shared_instance().editor;
	}

	//Update all the objects in the scene
	for (auto it = objectsInScene.begin(); it != objectsInScene.end(); ++it)
	{
		(*it)->Update(dt);
	}
}

void Level::Render(sf::RenderWindow* rw)
{
	for (auto it = objectsInScene.begin(); it != objectsInScene.end(); ++it)
	{
		(*it)->Render(rw);
	}

}
