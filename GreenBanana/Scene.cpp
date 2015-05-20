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
					if (!colHorizontal && !colVertical)//Direct hit on corner
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
					else if (colVertical)
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
