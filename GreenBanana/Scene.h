#ifndef SCENE_H
#define SCENE_H
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "Gameobject.h"
//#include "Player.h"
//#include "Trap.h"
//#include "Health.h"
//#include "Floor.h"
//#include "Coin.h"
#include "TextObject.h"
#include "InputManager.h"



class Scene
{
public:
	std::vector<Gameobject*> objectsInScene;

	void Update(float dt);//General Data that all scenes run
	virtual void Render(sf::RenderWindow* rw);//Render that all scenes run
	virtual void SceneLogic(float dt) = 0; //Individual Scene Updates

	void Parse();
	void CreateObject(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth);
	void Unload();

	std::string GetName() { return name; };
	std::string GetFilePath() { return filePath; };

	void SetName(std::string newName) { name = newName; };
	void SetFilePath(std::string newPath) { filePath = newPath; };

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


