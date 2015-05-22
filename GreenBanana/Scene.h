#ifndef SCENE_H
#define SCENE_H
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "Gameobject.h"
#include "TextObject.h"
#include "InputManager.h"

class Scene
{
public:
	std::vector<Gameobject*> objectsInScene;
	Sprite* background = NULL;

	void Update(float dt);//General Data that all scenes run
	virtual void Render(sf::RenderWindow* rw);//Render that all scenes run
	virtual void SceneLogic(float dt) = 0; //Individual Scene Updates

	void Parse();
	void CreateObject(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth);
	void Unload();
	virtual void ResetScene();

	std::string GetName() { return name; };
	std::string GetFilePath() { return filePath; };

	void SetName(std::string newName) { name = newName; };
	void SetFilePath(std::string newPath) { filePath = newPath; };
	//void SetBackground(std::string fileName) { background = new Sprite(); background->LoadTexture(fileName); }

	bool CollisionCheck(BoxCollider* col, std::vector<Gameobject*>& out_allCollisions);
	bool CollisionCheck(BoxCollider* col, std::vector<Gameobject*>& out_allCollisions, sf::Vector2f& offset);

	void SortGameobjects(std::vector<Gameobject*>& gameObjects);

protected:
	std::string name;
	std::string filePath;
private:
	Gameobject* currentObject = NULL;
	InputMapper* inputManager = &InputMapper::shared_instance(); 
};

#endif


