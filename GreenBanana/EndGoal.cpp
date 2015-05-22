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


	SpritesheetLoader loader;
	Animation jump;
	jump.name = "jump";
	jump.sprites = loader.Load("Resources/Objects/Alarm.png", 615, 772, 1);
	jump.endEvent = Animation::AnimationEndEvent::HoldLastFrame;
	jump.globalSpeed = 0.02;
	animations.animations["jump"] = jump;

	animations.SwitchAnimations("jump");

	collider = new BoxCollider();
	collider->size = sf::Vector2f(615, 772);
	collider->isTrigger = true;

}


EndGoal::~EndGoal()
{
}

void EndGoal::Update(float dt)
{
	animations.Update(dt);

	collider->center = position + sf::Vector2f(animations.curSprite->width / 2, animations.curSprite->height / 2);
}
void EndGoal::Render(sf::RenderWindow* window)
{

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
