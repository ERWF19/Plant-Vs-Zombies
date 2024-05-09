#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>


const std::string ZOMBIE_TYPE_1_IMAGE = "pic/Zombie.png"; 

const int NUM_OF_FRAME_TYPE_1 = 42;
const float ZOMBIE_TYPE_1_WIDTH = 100;
const float  ZOMBIE_TYPE_1_HEIGHT= 150;
const float ZOMBIE_VELOCITY = -0.1;
const float ZOMBIE_TYPE_1_DAMAGE = 10;

class Zombie
{
private:
	sf::RectangleShape shape;
	sf::Texture texture;
	std::string id;
	int damage;
	float velocity;
	float width;
	float height;
	float last_reaction_time;
	float eating_speed;
	std::vector<sf::Texture> texture_frames;
	int frame_index;

public:
	std::string line_id;
	Zombie(std::string i , std::string l_i ,float primary_x ,float  primary_y);
	void Move();
	void draw(sf::RenderWindow &window);
	bool is_get_Shot(sf::Vector2f bullet_position);
	float get_x_Position();
	void Stop();
	void go_Forward();
	void Bite(float current_global_time);
	bool is_Bite_Time(float current_global_time);
	bool Are_You_Okay();

};