#include "bullet.h"

Bullet::Bullet(std::string plant_name,std::string l_i,float x_plant,float y_plant,float plant_width , float plant_height)
{

	if(plant_name == "Peashooter")
	{
		if(!bullet_texture.loadFromFile(BULLET_TYPE_1_TEXTURE_PATH))
		{
			std:: cout << "error in loading bullet texture !" << std::endl;
		}

		line_id = l_i;
		shape.setRadius(10);
		shape.setTexture(&bullet_texture);
		shape.setPosition(sf::Vector2f(x_plant + plant_width - 15 , y_plant + 0.2 * plant_height - 10));
		velocity = 10;
		type = BULLET_TYPE_1;
	}
	if(plant_name == "Snow Peashooter")
	{
		if(!bullet_texture.loadFromFile(BULLET_TYPE_2_TEXTURE_PATH))
		{
			std:: cout << "error in loading bullet texture !" << std::endl;
		}
		line_id = l_i;
		shape.setRadius(10);
		shape.setTexture(&bullet_texture);
		shape.setPosition(sf::Vector2f(x_plant + plant_width - 15 , y_plant + 0.2 * plant_height - 10));	
		velocity = 10;
		type = BULLET_TYPE_2;
	}
}

void Bullet::Move()
{
	shape.move(velocity,0);
}

void Bullet::draw(sf::RenderWindow &window)
{
	window.draw(shape);
}

sf::Vector2f Bullet::get_Position()
{
	return shape.getPosition(); 
}

std::string Bullet::get_Type()
{
	return type;
}