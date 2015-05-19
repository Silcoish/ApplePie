#include <SFML/Graphics.hpp>

class Sprite
{
	public:
		int width, height, depth;
		sf::Texture sprite;
		float animTime;
	public:
	Sprite();
	~Sprite();
	void Load(std::string& fileLocation);

};