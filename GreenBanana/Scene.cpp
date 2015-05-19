#include "Scene.h"
#include "Player.h"


Scene::Scene(std::string filePath)
{
	SetFilePath(filePath);
	Parse();
}


Scene::~Scene()
{
}

void Scene::Update(float dt)
{
	for (auto it = ObjectsInScene.begin(); it != ObjectsInScene.end(); ++it)
	{
		(*it)->Update(dt);
	}
}

void Scene::Render(sf::RenderWindow* window)
{
	for (auto it = ObjectsInScene.begin(); it != ObjectsInScene.end(); ++it)
	{
		(*it)->Render(window);
	}
}

void Scene::Unload()
{
	for (auto it = ObjectsInScene.begin(); it != ObjectsInScene.end(); ++it)
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
	while (std::getline(in, loadData, ';'))
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
			CreateObject(type, name, x, y, worldspace, isStatic);
	}

}

void Scene::CreateObject(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic)
{
	if (type == "Player" || type == "player")
	{
		Player* newObject = new Player(type ,name, x, y, worldSpace, isStatic);
		ObjectsInScene.push_back(newObject);
	}
	else if (type == "Text" || type == "text")
	{
		TextObject* text = new TextObject("text", "TextTest", 40, 40, 1, 0);
		ObjectsInScene.push_back(text);
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