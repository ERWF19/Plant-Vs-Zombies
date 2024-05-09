#include <SFML/Graphics.hpp>
#include <iostream>
#include "bullet.h"

const std::string IMAGE_PATH_1 = "pic/sunflower.png";
const std::string IMAGE_PATH_2 = "pic/peashooter.png";
const std::string IMAGE_PATH_3 = "pic/snow peashooter.png";
const std::string IMAGE_PATH_4 = "pic/wallnut.png";
const float PLANT_DAMAGE = 4;
const float SUNFLOWER_WIDTH = 80;
const float SUNFLOWER_HEIGHT = 80;
const float PEASHOOTER_WIDTH = 80;
const float PEASHOOTER_HEIGHT = 80;
const float SNOW_PEASHOOTER_WIDTH = 100;
const float SNOW_PEASHOOTER_HEIGHT = 80;
const float WALLNUT_WIDTH = 80;
const float WALLNUT_HEIGHT = 80;
const float SUNFLOWER_DAMAGE = 4;
const float PEASHOOTER_DAMAGE = 4;
const float SNOW_PEASHOOTER_DAMAGE = 4;
const float WALLNUT_DAMAGE = 40;



class Plant
{
private:
	sf::RectangleShape shape;
	sf::Texture texture;
	std::string name;
	float width;
	float height;
	float damage;
	float price;
	float last_reaction_time;
	float action_speed;
	bool shooter;

public:
	std::string line_id ;
	std::string square_id ;
	Plant(int selected_card_index);
	void draw(sf::RenderWindow &window);
	void set_Square(std::string l , std::string s,float square_width ,float square_height);
	Bullet* Shoot_Bullet(float current_global_time);
	bool is_Shoot_Time(float current_global_time);
	float get_x_Position();
	void geting_Damage();
	bool is_Shooter();
	float get_Width();
	bool is_Dead();
};