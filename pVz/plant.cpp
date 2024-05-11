#include "plant.h"

Plant::Plant(int selected_card_index)
{
	last_reaction_time = 0;

	if(selected_card_index == 0)
	{
		name = PLANT_TYPE_1;
		width = SUNFLOWER_WIDTH;
		height = SUNFLOWER_HEIGHT;
		action_speed = 5;
		damage = SUNFLOWER_DAMAGE;
		shooter = false;
		producer = true;

		sf::Texture texture;
		if(!texture.loadFromFile(PLANT_TYPE_1_TEXTURE_PATH))
		{
			std:: cout << "error in loading Sunflower texture !" << std::endl;
		}
		frames_texture.push_back(texture);
		shape.setTexture(&frames_texture[0]);
	}
	else if(selected_card_index == 1)
	{
		name = PLANT_TYPE_2;
		width = PEASHOOTER_WIDTH;
		height = PEASHOOTER_HEIGHT;
		action_speed = 2;
		damage = PEASHOOTER_DAMAGE;
		shooter = true;
		producer = false;

		sf::Texture texture;
		if(!texture.loadFromFile(PLANT_TYPE_2_TEXTURE_PATH))
		{
			std:: cout << "error in loading Sunflower texture !" << std::endl;
		}
		frames_texture.push_back(texture);
		shape.setTexture(&frames_texture[0]);
	}
	else if(selected_card_index == 2)
	{
		name = PLANT_TYPE_3;
		width = SNOW_PEASHOOTER_WIDTH;
		height = SNOW_PEASHOOTER_HEIGHT;
		action_speed = 2;
		damage = SNOW_PEASHOOTER_DAMAGE;
		shooter = true;
		producer = false;

		sf::Texture texture;
		if(!texture.loadFromFile(PLANT_TYPE_3_TEXTURE_PATH))
		{
			std:: cout << "error in loading Sunflower texture !" << std::endl;
		}
		frames_texture.push_back(texture);
		shape.setTexture(&frames_texture[0]);

	}
	else if(selected_card_index == 3)
	{
		name = PLANT_TYPE_4;
		width = WALLNUT_WIDTH;
		height = WALLNUT_HEIGHT;
		damage = WALLNUT_DAMAGE;
		shooter = false;
		producer = false;

		sf::Texture texture;
		if(!texture.loadFromFile(PLANT_TYPE_4_TEXTURE_PATH))
		{
			std:: cout << "error in loading Walllnut texture !" << std::endl;
		}
		frames_texture.push_back(texture);

		if(!texture.loadFromFile(PLANT_TYPE_4_CRACKED1_TEXTURE_PATH))
		{
			std:: cout << "error in loading Walllnut texture !" << std::endl;
		}
		frames_texture.push_back(texture);

		if(!texture.loadFromFile(PLANT_TYPE_4_CRACKED2_TEXTURE_PATH))
		{
			std:: cout << "error in loading Walllnut texture !" << std::endl;
		}
		frames_texture.push_back(texture);
		shape.setTexture(&frames_texture[0]);
	}
}

void Plant::draw(sf::RenderWindow &window)
{

	if(name == PLANT_TYPE_4)
	{
		if(damage == WALLNUT_CRACKED1_DAMAGE)
		{
			shape.setTexture(&frames_texture[1]);

		}
		else if(damage == WALLNUT_CRACKED2_DAMAGE)
		{
			shape.setTexture(&frames_texture[2]);
		}
	}
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

Sun* Plant::Produce_Sun(float current_global_time)
{
	sf::Vector2f shape_position = shape.getPosition();
	Sun* new_sun = new Sun(0,shape_position.x,shape_position.y);
	last_reaction_time = current_global_time;
	return new_sun;
}

bool Plant::is_Act_Time(float current_global_time)
{
	if(current_global_time - last_reaction_time >= action_speed)
		return true;
	return false;
}


float Plant::get_x_Position()
{
	return shape.getPosition().x;
}

bool Plant::is_Producer()
{
	if(producer)
		return true;
	return false;
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