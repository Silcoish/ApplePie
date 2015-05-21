#include "Scene.h"
#include "GameManager.h"
#include "Player.h"
#include "Floor.h"
#include "Coin.h"
#include "Trap.h"
#include "Health.h"
#include "Lollipop.h"
#include "Splenda.h"
#include "LevelBackground.h"

void Scene::Update(float dt)
{
	//editor shit
	if (GameManager::shared_instance().editor)
	{
		sf::Vector2f pos = GameManager::shared_instance().rw->mapPixelToCoords(sf::Mouse::getPosition(*GameManager::shared_instance().rw));

		//Set Snap


		if (currentObject != nullptr)
		{
			sf::Vector2f newPos = sf::Vector2f(pos.x - currentObject->GetSize().x / 2, pos.y - currentObject->GetSize().y / 2);

			if (!currentObject->GetworldSpace())
			{
				newPos -= GameManager::shared_instance().cameraPos;
			}

			//newPos.x -= modff(1, &newPos.x);
			newPos.x = (float)((int)(newPos.x / 10)) * 10;
			newPos.y = (float)((int)(newPos.y / 10)) * 10;


			currentObject->SetPosition(newPos);
		}

		//Key pressed, make new objects
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			if (currentObject == nullptr)
			{
				Player* player = new Player("player", "player", pos.x - 80, pos.y - 112, 1, 0, 0);
				player->SetCurrentScene(this);
				currentObject = player;
				objectsInScene.push_back(player);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			if (currentObject == nullptr)
			{
				Floor* floor = new Floor("floor", "floor", pos.x, pos.y, 1, 1, 0);
				floor->SetCurrentScene(this);
				currentObject = floor;
				objectsInScene.push_back(floor);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			if (currentObject == nullptr)
			{
				LevelBackground* bg = new LevelBackground("levelBackground", "levelBackground", pos.x, pos.y, 0, 1, -1);
				bg->SetCurrentScene(this);
				currentObject = bg;
				objectsInScene.push_back(bg);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		{
			if (currentObject == nullptr)
			{
				Health* health = new Health("health", "health", pos.x, pos.y, 0, 1, 0);
				health->SetCurrentScene(this);
				currentObject = health;
				objectsInScene.push_back(health);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
		{
			if (currentObject == nullptr)
			{
				Trap* trap = new Trap("trap", "trap", pos.x, pos.y, 1, 1, 0);
				trap->SetCurrentScene(this);
				currentObject = trap;
				objectsInScene.push_back(trap);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
		{
			if (currentObject == nullptr)
			{
				Coin* coin = new Coin("coin", "coin", pos.x, pos.y, 1, 1, 0);
				coin->SetCurrentScene(this);
				currentObject = coin;
				objectsInScene.push_back(coin);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
		{
			if (currentObject == nullptr)
			{
				Lollipop* lollipop = new Lollipop("lollipop", "lollipop", pos.x, pos.y, 1, 1, 0);
				lollipop->SetCurrentScene(this);
				currentObject = lollipop;
				objectsInScene.push_back(lollipop);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
		{
			if (currentObject == nullptr)
			{
				Splenda* splenda = new Splenda("splenda", "splenda", pos.x, pos.y, 1, 1, 0);
				splenda->SetCurrentScene(this);
				currentObject = splenda;
				objectsInScene.push_back(splenda);
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
			GameManager::shared_instance().cameraPos = sf::Vector2f(0.0f, 0.0f);

		if (!inputManager->curState["Equal"] && inputManager->prevState["Equal"])
		{
			if (currentObject != nullptr)
			{
				currentObject->SetDepth(currentObject->GetDepth() + 1);
				SortGameobjects(objectsInScene);
				std::cout << "New Depth: " << currentObject->GetDepth() << std::endl;
			}
		}

		if (!inputManager->curState["Dash"] && inputManager->prevState["Dash"])
		{
			if (currentObject != nullptr)
			{
				currentObject->SetDepth(currentObject->GetDepth() - 1);
				SortGameobjects(objectsInScene);
				std::cout << "New Depth: " << currentObject->GetDepth() << std::endl;
			}
		}

		if (!inputManager->curState["Tab"] && inputManager->prevState["Tab"])
			GameManager::shared_instance().showBoxColliders = !GameManager::shared_instance().showBoxColliders;
		

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
					delete currentObject;
					currentObject = nullptr;
				}
			}
		}

		if (inputManager->curState["LControl"] && inputManager->curState["S"] && !inputManager->prevState["S"])
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			std::fstream out("Resources/SceneData/testgame.txt", std::ios::out);
			for (auto it = objectsInScene.begin(); it != objectsInScene.end(); ++it)
			{
				out << (*it)->Serialize();
			}
			std::cout << "Save complete" << std::endl;
		}

		//Mouse Down to pick up objects
		if (inputManager->curState["MouseLeft"] && !inputManager->prevState["MouseLeft"])//Mouse Button Down
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
	else
	{
		//Update all the objects in the scene
		for (auto it = objectsInScene.begin(); it != objectsInScene.end(); ++it)
		{
			(*it)->Update(dt);
		}

		//Run Scene Logic
		SceneLogic(dt);
	}


	//Editor Toggle Button
	if (inputManager->curState["LShift"] && !inputManager->prevState["LShift"])
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		std::cout << "Pressed" << std::endl;
		GameManager::shared_instance().editor = !GameManager::shared_instance().editor;
	}



}

void Scene::Render(sf::RenderWindow* window)
{

	for (auto it = objectsInScene.begin(); it != objectsInScene.end(); ++it)
	{
		(*it)->Render(window);
	}
}

void Scene::Unload()
{
	for (auto it = objectsInScene.begin(); it != objectsInScene.end(); ++it)
	{
		delete (*it);
	}
}

void Scene::Parse()
{
	std::string loadData = "";
	std::string type, name = "";
	int depth = 0;
	float x, y = 0;
	bool worldspace, isStatic;
	std::fstream in(filePath, std::ios::in);
	std::cout << in.is_open();
	
	int commaCount = 0;
	while (std::getline(in, loadData, '\n'))
	{
		std::istringstream objectLine(loadData);
		std::string objectValue;
		while (std::getline(objectLine, objectValue, ','))
		{
			if (commaCount == 0)
				type = objectValue;
			
			if (commaCount == 1)
				name = objectValue;
			
			if (commaCount == 2)
				x = std::stof(objectValue);

			if (commaCount == 3)
				y = std::stof(objectValue);

			//worldspace?
			if (commaCount == 4)
				if (std::stoi(objectValue) == 1)
					worldspace = true;
				else
					worldspace = false;
			// is Static?
			if (commaCount == 5)
				if (std::stoi(objectValue) == 1)
					isStatic = true;
				else
					isStatic = false;

			if (commaCount == 6)
				depth = std::stoi(objectValue);

			commaCount++;
		}
		commaCount = 0;
		CreateObject(type, name, x, y, worldspace, isStatic, depth);
	}

}

void Scene::CreateObject(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth)
{
	if (type == "Player" || type == "player")
	{
		Player* newObject = new Player(type ,name, x, y, worldSpace, isStatic, depth);
		newObject->SetCurrentScene(this);
		objectsInScene.push_back(newObject);
	}
	else if (type == "Floor" || type == "floor")
	{
		Floor* newObject = new Floor(type, name, x, y, worldSpace, isStatic, depth);
		newObject->SetCurrentScene(this);
		objectsInScene.push_back(newObject);
	}
	else if (type == "Coin" || type == "coin")
	{
		Coin* newObject = new Coin(type, name, x, y, worldSpace, isStatic, depth);
		newObject->SetCurrentScene(this);
		objectsInScene.push_back(newObject);
	}
	else if (type == "Trap" || type == "Trap")
	{
		Trap* newObject = new Trap(type, name, x, y, worldSpace, isStatic, depth);
		newObject->SetCurrentScene(this);
		objectsInScene.push_back(newObject);
	}
	else if (type == "Health" || type == "health")
	{
		Health* newObject = new Health(type, name, x, y, worldSpace, isStatic, depth);
		newObject->SetCurrentScene(this);
		objectsInScene.push_back(newObject);
	}
	else if (type == "Lollipop" || type == "lollipop")
	{
		Lollipop* lollipop = new Lollipop(type, name, x, y, worldSpace, isStatic, depth);
		lollipop->SetCurrentScene(this);
		objectsInScene.push_back(lollipop);
	}
	else if (type == "LevelBackground" || type == "levelBackground")
	{
		LevelBackground* levelBackground = new LevelBackground(type, name, x, y, worldSpace, isStatic, depth);
		levelBackground->SetCurrentScene(this);
		objectsInScene.push_back(levelBackground);
	}
	else if (type == "Splenda" || type == "splenda")
	{
		Splenda* splenda = new Splenda(type, name, x, y, worldSpace, isStatic, depth);
		splenda->SetCurrentScene(this);
		objectsInScene.push_back(splenda);
	}

}

bool Scene::CollisionCheck(BoxCollider* cola, std::vector<Gameobject*>& out_allCollisions)
{
	BoxCollider* colb;
	bool hitSomething = false;

	for (size_t i = 0; i < objectsInScene.size(); i++)
	{
		colb = objectsInScene[i]->GetCollider();
		if (cola != colb)
		{
			float distx = abs(colb->center.x - cola->center.x);
			float disty = abs(colb->center.y - cola->center.y);

			if (distx < (cola->size.x / 2 + colb->size.x / 2) && disty < (cola->size.y / 2 + colb->size.y / 2))
			{
				out_allCollisions.push_back(objectsInScene[i]);
				if (!colb->isTrigger)
				{
					hitSomething = true;
				}
			}
		}
	}

	return out_allCollisions.size() != 0;
}

bool Scene::CollisionCheck(BoxCollider* cola, std::vector<Gameobject*>& out_allCollisions, sf::Vector2f& velocity)
{
	BoxCollider* colb;
	bool hitSomething = false;

	for (size_t i = 0; i < objectsInScene.size(); i++)
	{
		colb = objectsInScene[i]->GetCollider();
		if (cola != colb)
		{
			float distx = colb->center.x - cola->center.x;
			float disty = colb->center.y - cola->center.y;

			bool colDiagonal = abs(distx - velocity.x) < (cola->size.x / 2 + colb->size.x / 2) && abs(disty - velocity.y) < (cola->size.y / 2 + colb->size.y / 2); //true if Collision when moved diagonal
			bool colVertical = abs(distx) < (cola->size.x / 2 + colb->size.x / 2) && abs(disty - velocity.y) < (cola->size.y / 2 + colb->size.y / 2); //true if Collision when moved Vertcally only
			bool colHorizontal = abs(distx - velocity.x) < (cola->size.x / 2 + colb->size.x / 2) && abs(disty) < (cola->size.y / 2 + colb->size.y / 2); //true if Collision when moved Horizontal only

			//std::cout << "colDiagonal: " << colDiagonal << std::endl;
			//std::cout << "colVertical: " << colVertical << std::endl;
			//std::cout << "colHorizontal: " << colHorizontal << std::endl;

			//Check Diagonal
			if (colDiagonal)
			{
				out_allCollisions.push_back(objectsInScene[i]);
				if (!colb->isTrigger)
				{
					//std::cout << "colHorizontal: " << colHorizontal << std::endl;
					//Check to see if hit directly on the corner
					//if (!colHorizontal && !colVertical)//Direct hit on corner
					//{
					//	//Move Vertically Only
					//	velocity.x = colb->center.x - cola->center.x;
					//	if (velocity.x > 0)
					//	{
					//		velocity.x -= ((cola->size.x / 2) + (colb->size.x / 2));
					//	}
					//	else
					//	{
					//		velocity.x += ((cola->size.x / 2) + (colb->size.x / 2));
					//	}
					//	std::cout << "both: " << std::endl;
					//}
					//else 
					if (colVertical)
					{
						
						//Move Horizontal Only
						velocity.y = colb->center.y - cola->center.y;
						if (velocity.y > 0)
						{
							velocity.y -= ((cola->size.y / 2) + (colb->size.y / 2));
						}
						else
						{
							velocity.y += ((cola->size.y / 2) + (colb->size.y / 2));
						}

					}
					else if (colHorizontal)
					{
						//Move Vertically Only
						velocity.x = colb->center.x - cola->center.x;
						if (velocity.x > 0)
						{
							velocity.x -= ((cola->size.x / 2) + (colb->size.x / 2));
						}
						else
						{
							velocity.x += ((cola->size.x / 2) + (colb->size.x / 2));
						}

					}
					hitSomething = true;
				}
			}
			
		}
	}

	return hitSomething;
}

void Scene::SceneLogic(float dt)
{

}

void Scene::SortGameobjects(std::vector<Gameobject*>& gameObjects)
{
	bool somethingChanged = false;

	do
	{
		somethingChanged = false;
		for (size_t i = 0; i < gameObjects.size() - 1; i++)
		{
			if (gameObjects[i]->GetDepth() > gameObjects[i + 1]->GetDepth())
			{
				Gameobject* temp = gameObjects[i];

				gameObjects[i] = gameObjects[i + 1];

				gameObjects[i + 1] = temp;

				somethingChanged = true;
			}
		}
	} while (somethingChanged);
}
