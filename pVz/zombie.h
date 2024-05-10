#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>


const std::string ZOMBIE_TYPE_1_WALKING_FRAMES_ROOT = "pic/walking_frames/"; 
const std::string ZOMBIE_TYPE_1_EATING_FRAMES_ROOT = "pic/eating_frames/"; 


const int NUM_OF_FRAME_TYPE_1_WALKING = 38;
const int NUM_OF_FRAME_TYPE_1_EATING = 14;
const float ZOMBIE_TYPE_1_WIDTH = 150;
const float  ZOMBIE_TYPE_1_HEIGHT= 300;
const float ZOMBIE_VELOCITY = -0.5;
const float ZOMBIE_TYPE_1_DAMAGE = 10;
const float FRAME_RATE = 0.1;

class Zombie
{
private:
	sf::RectangleShape shape;
	sf::Texture texture;
	std::string id;
	int damage;
	float velocity;
	float walk_again_velocity;
	float width;
	float height;
	float last_reaction_time;
	float eating_speed;
	std::vector<sf::Texture> walking_frames_texture;
	std::vector<sf::Texture> eating_frames_texture;
	int walking_frame_index;
	int eating_frame_index;
	float frame_rate;
	float last_time_change_frame;
	bool eat_status;

public:
	std::string line_id;
	Zombie(std::string i , std::string l_i ,float primary_x ,float  primary_y);
	void Load_Frames();
	void Move();
	void draw(sf::RenderWindow &window ,float current_global_time);
	bool is_get_Shot(sf::Vector2f bullet_position,std::string bullet_type);
	float get_x_Position();
	void Stop();
	void go_Forward();
	void Bite(float current_global_time);
	bool is_Bite_Time(float current_global_time);
	bool Are_You_Okay();
	bool is_House_Reached(float house_x_position);

};