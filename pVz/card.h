#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


const float CARD_WIDTH = 125;
const float CARD_HEIGHT = 70;
const float PRICE_CHAR_SIZE = 15;

const std::string DIGIT_FONT_PATH = "font/digit_font.ttf";

class Card
{
public:
	Card(std::string n,int pr,float x_position , float y_position, std::string on_card_path ,  std::string off_card_path ,float invalit_t);
	void draw(sf::RenderWindow &window ,float current_global_time);
	sf::Vector2f getPosition();
	bool is_Valid();
	void Apply_Current_Time(float current_global_time);

private:
	bool validation;
	std::string name;
	sf::RectangleShape shape;
	sf::Texture on_texture;
	sf::Texture off_texture;
	sf::Text price;
	sf::Font font;
	float last_time_selected;
	float invalid_time;
};