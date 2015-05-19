#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include "Gameobject.h"
class Scene
{
public:
	Scene(std::string filePath);
	~Scene();

	std::vector<Gameobject*> ObjectsInScene;

	virtual void SceneLogic();
	void Update(float dt);
	void Render(sf::RenderWindow* window);
	void Parse();
	void CreateObject(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic);
	void Unload();

	std::string GetName() { return name; };
	std::string GetFilePath() { return filePath; };

	void SetName(std::string newName) { name = newName; };
	void SetFilePath(std::string newPath) { filePath = newPath; };

protected:
	std::string name;
	std::string filePath;
	
};

