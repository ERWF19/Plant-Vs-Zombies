#include "plant.h"

Plant::Plant(int selected_card_index)
{
	if(selected_card_index == 0)
	{
		name = "Sunflower";
		price = 50;
		width = SUNFLOWER_WIDTH;
		height = SUNFLOWER_HEIGHT;
		damage = SUNFLOWER_DAMAGE;
		shooter = false;
		if(!texture.loadFromFile(IMAGE_PATH_1))
		{
			std:: cout << "error in loading Sunflower texture !" << std::endl;
		}

		shape.setTexture(&texture);
	}
	else if(selected_card_index == 1)
	{
		name = "Peashooter";
		price = 100;
		width = PEASHOOTER_WIDTH;
		height = PEASHOOTER_HEIGHT;
		action_speed = 2;
		damage = PEASHOOTER_DAMAGE;
		shooter = true;
		if(!texture.loadFromFile(IMAGE_PATH_2))
		{
			std:: cout << "error in loading Peashooter texture !" << std::endl;
		}

		shape.setTexture(&texture);
	}
	else if(selected_card_index == 2)
	{
		name = "Snow Peashooter";
		price = 200;
		width = SNOW_PEASHOOTER_WIDTH;
		height = SNOW_PEASHOOTER_HEIGHT;
		action_speed = 2;
		damage = SNOW_PEASHOOTER_DAMAGE;
		shooter = true;
		if(!texture.loadFromFile(IMAGE_PATH_3))
		{
			std:: cout << "error in loading Snow Peashooter texture !" << std::endl;
		}

		shape.setTexture(&texture);
	}
	else if(selected_card_index == 3)
	{
		name = "Walllnut";
		price = 50;
		width = WALLNUT_WIDTH;
		height = WALLNUT_HEIGHT;
		damage = WALLNUT_DAMAGE;
		shooter = false;
		if(!texture.loadFromFile(IMAGE_PATH_4))
		{
			std:: cout << "error in loading Walllnut texture !" << std::endl;
		}

		shape.setTexture(&texture);
	}

}

void Plant::draw(sf::RenderWindow &window)
{
	window.draw(shape);
}

void Plant::set_Square(std::string l , std::string s , float square_width ,float square_height)
{
	square_id = s;
	line_id =l;
	shape.setSize(sf::Vector2f(width,height));
	shape.setPosition(sf::Vector2f(square_width,square_height));
}

Bullet* Plant::Shoot_Bullet(float current_global_time)
{
	sf::Vector2f shape_position = shape.getPosition();
	Bullet* new_bullet = new Bullet(name,line_id,shape_position.x,shape_position.y,width,height);
	last_reaction_time = current_global_time;
	return new_bullet;
}

bool Plant::is_Shoot_Time(float current_global_time)
{
	if(current_global_time - last_reaction_time >= action_speed)
		return true;
	return false;
}


float Plant::get_x_Position()
{
	return shape.getPosition().x;
}

bool Plant::is_Shooter()
{
	if(shooter)
		return true;
	return false;
}

void Plant::geting_Damage()
{
	damage --;
	//std::cout <<"______________" << damage << std::endl;
}

float Plant::get_Width()
{
	return width;
}

bool Plant::is_Dead()
{
	if(damage <=0 )
	{
		return true;
	}
	else
		return false;
}