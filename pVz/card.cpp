#include "card.h"

Card::Card(std::string n,int pr,float x_position , float y_position, std::string on_card_path ,  std::string off_card_path)
{
	name = n;

	shape.setSize(sf::Vector2f(CARD_WIDTH,CARD_HEIGHT));
	shape.setPosition(x_position,y_position);

	if(!on_texture.loadFromFile(on_card_path))
	{
		std::cout << "error in loading card texture!" << std::endl;
	}

	if(!off_texture.loadFromFile(off_card_path))
	{
		std::cout << "error in loading card texture!" << std::endl;
	}

	shape.setTexture(&off_texture);

	if(!font.loadFromFile(DIGIT_FONT_PATH))
	{
		std::cout << "error in loading digit font!" << std::endl;
	}

	price.setFont(font);
	price.setString(std::to_string(pr));
	price.setCharacterSize(PRICE_CHAR_SIZE);
	price.setFillColor(sf::Color::Black);
	price.setPosition(sf::Vector2f(x_position + (0.65 * CARD_WIDTH) ,y_position + (0.65 * CARD_HEIGHT) + 2.5));

}

void Card::draw(sf::RenderWindow &window)
{
	window.draw(shape);
	window.draw(price);
}

sf::Vector2f  Card::getPosition()
{
	return shape.getPosition();
}