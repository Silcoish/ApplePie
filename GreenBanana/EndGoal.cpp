#include "EndGoal.h"
#include "GameManager.h"


EndGoal::EndGoal(std::string type, std::string name, float x, float y, bool worldSpace, bool isStatic, int depth)
{
	SetType(type);
	SetName(name);
	SetPosition(sf::Vector2f(x, y));
	SetworldSpace(worldSpace);
	SetIsStatic(isStatic);
	SetDepth(depth);

	collider = new BoxCollider();
	collider->size = sf::Vector2f(230, 443);
	collider->isTrigger = true;

	SpritesheetLoader loader;
	Animation jump;
	jump.name = "jump";
	jump.sprites = loader.Load("Resources/Animations/Player/sleep.png", 160, 224, 11);
	jump.endEvent = Animation::AnimationEndEvent::Loop;
	jump.globalSpeed = 0.02;
	animations.animations["jump"] = jump;

	animations.SwitchAnimations("jump");

}


EndGoal::~EndGoal()
{
}

void EndGoal::Update(float dt)
{

}
void EndGoal::Render(sf::RenderWindow* window)
{
	collider->center = position + sf::Vector2f(75, 100);

	animations.curSprite->sprite->setPosition(GetPosition());

	window->draw(*animations.curSprite->sprite);

	if (GameManager::shared_instance().showBoxColliders)
	{
		sf::Vertex line[] = { sf::Vertex(sf::Vector2f(collider->center.x - collider->size.x / 2, collider->center.y - collider->size.y / 2)),
			sf::Vertex(sf::Vector2f(collider->center.x + collider->size.x / 2, collider->center.y - collider->size.y / 2)),

			sf::Vertex(sf::Vector2f(collider->center.x + collider->size.x / 2, collider->center.y - collider->size.y / 2)),
			sf::Vertex(sf::Vector2f(collider->center.x + collider->size.x / 2, collider->center.y + collider->size.y / 2)),

			sf::Vertex(sf::Vector2f(collider->center.x + collider->size.x / 2, collider->center.y + collider->size.y / 2)),
			sf::Vertex(sf::Vector2f(collider->center.x - collider->size.x / 2, collider->center.y + collider->size.y / 2)),

			sf::Vertex(sf::Vector2f(collider->center.x - collider->size.x / 2, collider->center.y + collider->size.y / 2)),
			sf::Vertex(sf::Vector2f(collider->center.x - collider->size.x / 2, collider->center.y - collider->size.y / 2)) };

		line[0].color = sf::Color(0, 255, 0, 225);
		line[1].color = sf::Color(0, 255, 0, 225);
		line[2].color = sf::Color(0, 255, 0, 225);
		line[3].color = sf::Color(0, 255, 0, 225);
		line[4].color = sf::Color(0, 255, 0, 225);
		line[5].color = sf::Color(0, 255, 0, 225);
		line[6].color = sf::Color(0, 255, 0, 225);
		line[7].color = sf::Color(0, 255, 0, 225);

		window->draw(line, 8, sf::Lines);
	}

}
