#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include "Gameobject.h"
class Scene
{
public:
	Scene(std::string filePath);
	~Scene();

	std::map<std::string, Gameobject> ObjectsInScene;

	virtual void Update(float dt);
	virtual void Render(sf::RenderWindow* window);
	virtual void SceneLogic();
	void Parse();
	void CreateObject();
	void Unload();

	std::string GetName() { return name; };
	std::string GetFilePath() { return filePath; };

	void SetName(std::string newName) { name = newName; };
	void SetFilePath(std::string newPath) { filePath = newPath; };

protected:
	std::string name;
	std::string filePath;
	
};

