#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

const std::string BULLET_TYPE_1 = "Pea Bullet";
const std::string BULLET_TYPE_2 = "Ice Bullet";


class Bullet
{
private:
	float velocity;
	sf::CircleShape shape;
	std::string type;
public:
	std::string line_id;
	Bullet(std::string plant_name,std::string l_i,float x_plant,float y_plant,float plant_width ,float plant_height);
	void Move();
	void draw(sf::RenderWindow &window);
	sf::Vector2f get_Position();

};