#include "Gameobject.h"
#include "GameManager.h"

Gameobject::~Gameobject()
{

}

std::string Gameobject::Serialize()
{
	std::stringstream ss;
	ss << GetType();
	ss << ",";
	ss << GetName();
	ss << ",";
	ss << GetStartPosition().x;
	ss << ",";
	ss << GetStartPosition().y;
	ss << ",";
	ss << GetworldSpace();
	ss << ",";
	ss << GetIsStatic();
	ss << ",";
	ss << GetDepth();
	ss << std::endl;

	return ss.str();
}

sf::Vector2f Gameobject::GetSize()
{
	if (animations.curSprite != nullptr)
	{
		return sf::Vector2f(animations.curSprite->width, animations.curSprite->height);
	}

	return sf::Vector2f(0, 0);
}

void Gameobject::Update(float dt)
{
	
}

void Gameobject::ResetObject()
{


}

void Gameobject::Render(sf::RenderWindow* rw)
{
	collider->center = position + sf::Vector2f(animations.curSprite->width / 2, animations.curSprite->height / 2);

	animations.curSprite->sprite->setPosition(GetPosition());
	

	if (GetworldSpace())
	{
		animations.curSprite->sprite->setPosition(GetPosition());
		rw->draw(*animations.curSprite->sprite);
	}
	else
	{
		collider->center += GameManager::shared_instance().cameraPos;
		animations.curSprite->sprite->setPosition(GetPosition() + GameManager::shared_instance().cameraPos);
		rw->draw(*animations.curSprite->sprite);
	}

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

		rw->draw(line, 8, sf::Lines);
	}
}

void Gameobject::ScaleSprites(std::map<std::string, Animation>& out_anims, float scale)
{
	for (auto it = out_anims.begin(); it != out_anims.end(); it++)
	{
		std::vector<Sprite*> animSheet = out_anims[(it)->first].sprites;
		for (size_t j = 0; j < animSheet.size(); j++)
		{
			animSheet[j]->sprite->setScale(scale, scale);
			animSheet[j]->width = animSheet[j]->sprite->getTextureRect().width * scale;
			animSheet[j]->height = animSheet[j]->sprite->getTextureRect().height* scale;
		}
	}
}

void Gameobject::ScaleSprites(std::map<std::string, Animation>& out_anims, sf::Vector2f newSize)
{
	for (auto it = out_anims.begin(); it != out_anims.end(); it++)
	{
		std::vector<Sprite*> animSheet = out_anims[(it)->first].sprites;
		for (size_t j = 0; j < animSheet.size(); j++)
		{
			float scaleX = newSize.x / animSheet[j]->sprite->getTextureRect().width;
			float scaleY = newSize.y / animSheet[j]->sprite->getTextureRect().height;


			animSheet[j]->sprite->setScale(scaleX, scaleY);
			animSheet[j]->width = animSheet[j]->sprite->getTextureRect().width * scaleX;
			animSheet[j]->height = animSheet[j]->sprite->getTextureRect().height* scaleY;
		}
	}
}