#include "Scene.h"


Scene::Scene(std::string filePath)
{
	SetFilePath(filePath);
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
	//TODO:
}

void Scene::CreateObject(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic)
{
	//TODO:
}