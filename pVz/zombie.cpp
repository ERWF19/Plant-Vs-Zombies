#include "zombie.h"

Zombie::Zombie(std::string i , std::string l_i ,float x0 ,float  y0)
{
	id = i;
	line_id = l_i;
	damage = ZOMBIE_TYPE_1_DAMAGE;
	velocity = ZOMBIE_VELOCITY;
	width = ZOMBIE_TYPE_1_WIDTH;
	height= ZOMBIE_TYPE_1_HEIGHT;
	eating_speed = 1;

	frame_index = 0;


	for(int i=0 ; i<NUM_OF_FRAME_TYPE_1 ; i++)
	{
		sf::Texture t;
		std::ostringstream path;
		path << "pic/walking_frames/" << i + 1 << ".png";
		if(!t.loadFromFile(path.str()))
		{
			std:: cout << "error in loading zombie frames texture !" << std::endl;
		}
		texture_frames.push_back(t);
	}

	shape.setSize(sf::Vector2f(width,height));
	shape.setTexture(&texture_frames[frame_index]);
	shape.setPosition(sf::Vector2f(x0,y0 - ZOMBIE_TYPE_1_HEIGHT/2));

}

void Zombie::Move()
{
	shape.move(velocity,0);
}

void Zombie::draw(sf::RenderWindow &window)
{
	window.draw(shape);
	if(frame_index < NUM_OF_FRAME_TYPE_1)
	{
		frame_index ++;
		shape.setTexture(&texture_frames[frame_index]);
	}
	else
	{
		frame_index = 0;
		shape.setTexture(&texture_frames[frame_index]);
	}
}

bool Zombie::is_get_Shot(sf::Vector2f bullet_position)
{
	if(bullet_position.x >= shape.getPosition().x)
	{
		damage --;
		std::cout << "get_shot !" << "  damage = " << damage << std::endl;
		return true;
	}
	return false;
}


float Zombie::get_x_Position()
{
	return shape.getPosition().x;
}

void Zombie::Stop()
{
	velocity = 0;
}

void Zombie::go_Forward()
{
	velocity = ZOMBIE_VELOCITY;
}

void Zombie::Bite(float current_global_time)
{
	last_reaction_time = current_global_time;
}

bool Zombie::is_Bite_Time(float current_global_time)
{
	if(current_global_time - last_reaction_time >=eating_speed)
		return true;
	return false;
}

bool Zombie::Are_You_Okay()
{
	if(damage == 0)
		return false;
	else
		return true;
}

/*void Zombie::get_heat()
{
	if(damage == 5)

}*/