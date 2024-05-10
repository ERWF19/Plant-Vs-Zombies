#include <SFML/Graphics.hpp>
#include <iostream>
#include "bullet.h"

const std::string PLANT_TYPE_1 = "Sunflower";
const std::string PLANT_TYPE_2 = "Peashooter";
const std::string PLANT_TYPE_3 = "Snow Peashooter";
const std::string PLANT_TYPE_4 = "Wallnut";

const std::string PLANT_TYPE_1_TEXTURE_PATH = "pic/sunflower.png";
const std::string PLANT_TYPE_2_TEXTURE_PATH = "pic/peashooter.png";
const std::string PLANT_TYPE_3_TEXTURE_PATH = "pic/snow peashooter.png";
const std::string PLANT_TYPE_4_TEXTURE_PATH = "pic/wallnut.png";
const std::string PLANT_TYPE_4_CRACKED1_TEXTURE_PATH = "pic/wallnut_cracked1.png";
const std::string PLANT_TYPE_4_CRACKED2_TEXTURE_PATH = "pic/wallnut_cracked2.png";


const float SUNFLOWER_WIDTH = 80;
const float SUNFLOWER_HEIGHT = 80;
const float PEASHOOTER_WIDTH = 80;
const float PEASHOOTER_HEIGHT = 80;
const float SNOW_PEASHOOTER_WIDTH = 100;
const float SNOW_PEASHOOTER_HEIGHT = 80;
const float WALLNUT_WIDTH = 80;
const float WALLNUT_HEIGHT = 80;
const float SUNFLOWER_DAMAGE = 5;
const float PEASHOOTER_DAMAGE = 5;
const float SNOW_PEASHOOTER_DAMAGE = 5;
const float WALLNUT_DAMAGE = 40;
const float WALLNUT_CRACKED1_DAMAGE = 20;
const float WALLNUT_CRACKED2_DAMAGE = 10;




class Plant
{
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

private:
	sf::RectangleShape shape;
	std::vector<sf::Texture> frames_texture;
	std::string name;
	float width;
	float height;
	float damage;
	float price;
	float last_reaction_time;
	float action_speed;
	bool shooter;
};