#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "bullet.h"
#include "sun.h"



const std::string PLANT_TYPE_1_TEXTURE_PATH = "pic/sunflower.png";
const std::string PLANT_TYPE_2_TEXTURE_PATH = "pic/peashooter.png";
const std::string PLANT_TYPE_3_TEXTURE_PATH = "pic/snow peashooter.png";
const std::string PLANT_TYPE_4_TEXTURE_PATH = "pic/frames/walnut_frames/walnut.png";
const std::string PLANT_TYPE_4_CRACKED1_TEXTURE_PATH = "pic/frames/walnut_frames/walnut_cracked1.png";
const std::string PLANT_TYPE_4_CRACKED2_TEXTURE_PATH = "pic/frames/walnut_frames/walnut_cracked2.png";


const float PLANT_FRAME_RATE = 0.1;
const std::string PLANT_TYPE_1_FRAMES_ROOT = "pic/frames/sunflower_frames/";
const std::string PLANT_TYPE_2_FRAMES_ROOT = "pic/frames/peashooter_frames/";
const std::string PLANT_TYPE_3_FRAMES_ROOT = "pic/frames/snow_peashooter_frames/";
const int PLANT_TYPE_1_NUM_OF_FRAMES = 31;
const int PLANT_TYPE_2_NUM_OF_FRAMES = 20;
const int PLANT_TYPE_3_NUM_OF_FRAMES = 18;


const float SUNFLOWER_WIDTH = 80;
const float SUNFLOWER_HEIGHT = 80;
const float PEASHOOTER_WIDTH = 100;
const float PEASHOOTER_HEIGHT = 100;
const float SNOW_PEASHOOTER_WIDTH = 120;
const float SNOW_PEASHOOTER_HEIGHT = 120;
const float WALNUT_WIDTH = 80;
const float WALNUT_HEIGHT = 80;
const float SUNFLOWER_DAMAGE = 5;
const float PEASHOOTER_DAMAGE = 5;
const float SNOW_PEASHOOTER_DAMAGE = 5;
const float WALNUT_DAMAGE = 40;
const float WALNUT_CRACKED1_DAMAGE = 20;
const float WALNUT_CRACKED2_DAMAGE = 10;




class Plant
{
public:
	std::string line_id ;
	std::string square_id ;
	Plant(std::string type,std::vector<float> options);
	void Load_Frames(std::string root_path , int num_of_frames);
	void draw(sf::RenderWindow &window,float current_global_time);
	void set_Square(std::string l , std::string s,float square_width ,float square_height);
	Bullet* Shoot_Bullet(float current_global_time);
	Sun* Produce_Sun(float current_global_time);
	bool is_Act_Time(float current_global_time);
	float get_x_Position();
	void getting_Damage(float zombie_damage);
	bool is_Producer();
	bool is_Shooter();
	float get_Width();
	bool is_Dead();

private:
	std::string name;
	std::vector<float> plant_options;
	float width;
	float height;
	float health;
	float damage;
	float last_reaction_time;
	float action_speed;
	bool shooter;
	bool producer;
	sf::RectangleShape shape;
	std::vector<sf::Texture> frames_texture;
	int frame_index;
	float frame_rate;
	float last_time_change_frame;
};