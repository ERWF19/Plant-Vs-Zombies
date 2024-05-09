#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <time.h>
#include "line.h"


const std::string PLAYGROUND_TEXTURE_PATH = "pic/playground.png";
const std::string THROW_SOUND = "soundeffect/throw.ogg";
const std::string ON_SUNFLOWER_CARD_PIC = "pic/on_sunflower.png";
const std::string OFF_SUNFLOWER_CARD_PIC = "pic/off_sunflower.png";
const std::string ON_PEASHOOTER_CARD_PIC = "pic/on_peashooter.png";
const std::string OFF_PEASHOOTER_CARD_PIC = "pic/off_peashooter.png";
const std::string ON_SNOW_PEASHOOTER_CARD_PIC = "pic/on_snow_peashooter.png";
const std::string OFF_SNOW_PEASHOOTER_CARD_PIC = "pic/off_snow_peashooter.png";
const std::string ON_WALLNUT_CARD_PIC = "pic/on_wallnut.png";
const std::string OFF_WALLNUT_CARD_PIC = "pic/off_wallnut.png";


const float CARD_WIDTH = 180;
const float CARD_HEIGHT = 100;
const float FIRST_CARD_COORDINATE_WIDTH = 100;
const float FIRST_CARD_COORDINATE_HEIGHT = 20;



class GamePlay
{
public:
	GamePlay(float width , float height);
	void draw(sf::RenderWindow &window);
	void Move_Mouse(sf::RenderWindow &window);
	void Draw_Plants(sf::RenderWindow &window);
	void Card_Selection(sf::RenderWindow &window);
	bool is_Line_Range(sf::Vector2i localPosition ,Plant *p);
	bool grow_plant(Plant *p);
	void Generate_Zombie();
	void Move_Zombies();
	void Draw_Zombies(sf::RenderWindow &window);
	void Plants_Fire(float current_global_time);
	Line* Find_Line(std::string line_id);
	void Move_Bullets();
	void Draw_Bullets(sf::RenderWindow &window);
	void Bullet_Impact();
	void Kill_Plants(float current_global_time);
	void Plants_Death();
	void Zombie_Death();

private:

	int sun_score;
	int selected_card_index;
	sf::RectangleShape playground;
	sf::Texture playground_texture;
	std::vector<Line *> lines;
	std::vector <sf::RectangleShape> cards; 
	sf::Texture card_1_on_texture;
	sf::Texture card_1_off_texture;
	sf::Texture card_2_on_texture;
	sf::Texture card_2_off_texture;
	sf::Texture card_3_on_texture;
	sf::Texture card_3_off_texture;
	sf::Texture card_4_on_texture;
	sf::Texture card_4_off_texture;
	std::vector<Plant*> plants;
	std::vector<Zombie*> zombies;
	std::vector<Bullet*> bullets;
	sf::SoundBuffer buffer;
	sf::Sound throw_sound;


};