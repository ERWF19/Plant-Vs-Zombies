#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <time.h>
#include "line.h"
#include "card.h"



const std::string PLAYGROUND_TEXTURE_PATH = "pic/playground.png";
const std::string THROW_SOUND = "soundeffect/throw.ogg";
const std::string PLANT_TYPE_1_ON_CARD_PATH = "pic/cards/on_sunflower.png";
const std::string PLANT_TYPE_1_OFF_CARD_PATH  = "pic/cards/off_sunflower.png";
const std::string PLANT_TYPE_2_ON_CARD_PATH = "pic/cards/on_peashooter.png";
const std::string PLANT_TYPE_2_OFF_CARD_PATH = "pic/cards/off_peashooter.png";
const std::string PLANT_TYPE_3_ON_CARD_PATH = "pic/cards/on_snow_peashooter.png";
const std::string PLANT_TYPE_3_OFF_CARD_PATH = "pic/cards/off_snow_peashooter.png";
const std::string PLANT_TYPE_4_ON_CARD_PATH = "pic/cards/on_wallnut.png";
const std::string PLANT_TYPE_4_OFF_CARD_PATH = "pic/cards/off_wallnut.png";



const float FIRST_LINE_X_POSITION = 311;
const float FIRST_LINE_Y_POSITION = 138;
const float FIRST_CARD_COORDINATE_X = 50;
const float FIRST_CARD_COORDINATE_Y = 50;
const int NUM_OF_CARDS = 5;



class GamePlay
{
public:
	GamePlay(float width , float height);
	void Load_Cards();
	void draw(sf::RenderWindow &window,float current_global_time);
	void Move_Mouse(sf::RenderWindow &window);
	void Draw_Cards(sf::RenderWindow &window);
	void Draw_Plants(sf::RenderWindow &window);
	void Card_Selection(sf::RenderWindow &window,float current_global_time);
	bool is_Line_Range(sf::Vector2i localPosition ,Plant *p);
	bool is_Valid_Square(Plant *p);
	void Generate_Zombie();
	void Move_Zombies();
	void Draw_Zombies(sf::RenderWindow &window,float current_global_time);
	void Plants_Fire(float current_global_time);
	Line* Find_Line(std::string line_id);
	void Move_Bullets();
	void Draw_Bullets(sf::RenderWindow &window);
	void Bullet_Impact();
	void Kill_Plants(float current_global_time);
	void Plants_Death();
	void Zombies_Death();
	bool GameOver(float house_x_position);


private:

	int sun_score;
	int selected_card_index;
	sf::RectangleShape playground;
	sf::Texture playground_texture;
	std::vector<Line *> lines;
	std::vector<Plant*> plants;
	std::vector<Zombie*> zombies;
	std::vector<Bullet*> bullets;
	std::vector <Card*> cards; 
	sf::SoundBuffer buffer;
	sf::Sound throw_sound;
};