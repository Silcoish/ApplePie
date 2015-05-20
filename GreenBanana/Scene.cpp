#include "Scene.h"
#include "Player.h"
#include "Floor.h"
#include "Coin.h"
#include "Trap.h"
#include "Health.h"

void Scene::Update(float dt)
{
	for (auto it = objectsInScene.begin(); it != objectsInScene.end(); ++it)
	{
		(*it)->Update(dt);
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
	std::string loadData;
	std::string type, name;
	float x, y;
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

			commaCount++;
		}
		commaCount = 0;
		CreateObject(type, name, x, y, worldspace, isStatic);
	}

}

void Scene::CreateObject(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic)
{
	if (type == "Player" || type == "player")
	{
		Player* newObject = new Player(type ,name, x, y, worldSpace, isStatic);
		newObject->SetCurrentScene(this);
		objectsInScene.push_back(newObject);
	}
	else if (type == "Floor" || type == "floor")
	{
		Floor* newObject = new Floor(type, name, x, y, worldSpace, isStatic);
		objectsInScene.push_back(newObject);
	}
	else if (type == "Coin" || type == "coin")
	{
		//Coin* newObject = new Coin(type, name, x, y, worldSpace, isStatic);
	}
	else if (type == "Trap" || type == "Trap")
	{
		//Trap* newObject = new Trap(type, name, x, y, worldSpace, isStatic);
	}
	else if (type == "Health" || type == "health")
	{
		//Health* newObject = new Health(type, name, x, y, worldSpace, isStatic);
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

bool Scene::CollisionCheck(BoxCollider* cola, std::vector<Gameobject*>& out_allCollisions, sf::Vector2f offset)
{
	BoxCollider* colb;
	bool hitSomething = false;

	for (size_t i = 0; i < objectsInScene.size(); i++)
	{
		colb = objectsInScene[i]->GetCollider();
		if (cola != colb)
		{
			float distx = abs(colb->center.x - cola->center.x + offset.x);
			float disty = abs(colb->center.y - cola->center.y + offset.y);

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

	return hitSomething;
}

void Scene::SceneLogic(float dt)
{

}
