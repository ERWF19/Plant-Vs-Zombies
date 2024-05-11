#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>


const std::string PLANT_TYPE_1 = "sunflower";
const std::string PLANT_TYPE_2 = "peashooter";
const std::string PLANT_TYPE_3 = "snow_peashooter";
const std::string PLANT_TYPE_4 = "walnut";

const std::string BULLET_TYPE_1 = "Pea Bullet";
const std::string BULLET_TYPE_2 = "Ice Bullet";

const std::string BULLET_TYPE_1_TEXTURE_PATH = "pic/bullets/pea.png";
const std::string BULLET_TYPE_2_TEXTURE_PATH = "pic/bullets/snow_pea.png";

class Bullet
{
private:
	float velocity;
	float damage;
	sf::CircleShape shape;
	sf::Texture bullet_texture;
	std::string type;
public:
	std::string line_id;
	Bullet(std::string plant_name,std::string l_i,float v,float d,float x_plant,float y_plant,float plant_width ,float plant_height);
	void Move();
	void draw(sf::RenderWindow &window);
	sf::Vector2f get_Position();
	std::string get_Type();
	float get_damage();


};