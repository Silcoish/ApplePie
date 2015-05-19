#pragma once
#include <iostream>
#include "Animator.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

class Gameobject
{
public:
	//Gameobject();
	//Gameobject(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic);
	//~Gameobject();
	
	// Methods
	virtual void Update(float dt) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;

	sf::Vector2f GetPosition() { return position; };
	void SetPosition(sf::Vector2f newPos) { position = newPos; };
	
	bool GetIsStatic() { return isStatic; };
	void SetIsStatic(bool value) { isStatic = value; };

	bool GetworldSpace() { return worldSpace; };
	void SetworldSpace(bool value) { worldSpace = value; };

	std::string GetName() { return name; };
	void SetName(std::string newName) { name = newName; };

	std::string GetType() { return type; };
	void SetType(std::string newType) { type = newType; };

	Animator GetAnimator() { return animations; };
	//Animator SetAnimator(Animator newAnimator) { animations = newAnimator; };

protected:	
	// Variables
	std::string name;
	std::string type;
	sf::Vector2f position;
	Animator animations;
	//BoxCollider collider;
	bool isStatic;
	bool worldSpace;
};

