#include "zombie.h"

Zombie::Zombie(std::string i , std::string l_i ,float x0 ,float  y0)
{
	id = i;
	line_id = l_i;
	damage = ZOMBIE_TYPE_1_DAMAGE;
	velocity = ZOMBIE_VELOCITY;
	walk_again_velocity = ZOMBIE_VELOCITY;
	width = ZOMBIE_TYPE_1_WIDTH;
	height= ZOMBIE_TYPE_1_HEIGHT;
	eating_speed = 1;
	eat_status = false;

	Load_Frames();

	shape.setSize(sf::Vector2f(width,height));
	shape.setTexture(&walking_frames_texture[walking_frame_index]);
	shape.setPosition(sf::Vector2f(x0,y0 - ZOMBIE_TYPE_1_HEIGHT/2));

}

void Zombie::Load_Frames()
{
	frame_rate = FRAME_RATE;


	walking_frame_index = 0;
	for(int i=0 ; i<NUM_OF_FRAME_TYPE_1_WALKING ; i++)
	{
		sf::Texture walking_texture;
		std::ostringstream path;
		path << ZOMBIE_TYPE_1_WALKING_FRAMES_ROOT << i + 1 << ".png";
		if(!walking_texture.loadFromFile(path.str()))
		{
			std:: cout << "error in loading zombie frames texture !" << std::endl;
		}
		walking_frames_texture.push_back(walking_texture);
	}

	eating_frame_index = 0;
	for(int i=0 ; i<NUM_OF_FRAME_TYPE_1_EATING ; i++)
	{
		sf::Texture eating_texture;
		std::ostringstream path;
		path << ZOMBIE_TYPE_1_EATING_FRAMES_ROOT << i + 1 << ".png";
		if(!eating_texture.loadFromFile(path.str()))
		{
			std:: cout << "error in loading zombie frames texture !" << std::endl;
		}
		eating_frames_texture.push_back(eating_texture);
	}
}

void Zombie::Move()
{
	shape.move(velocity,0);
}

void Zombie::draw(sf::RenderWindow &window , float current_global_time)
{
	window.draw(shape);
	if(eat_status)
	{
		if(current_global_time - last_time_change_frame >= frame_rate)
		{
			eating_frame_index ++;
			last_time_change_frame = current_global_time;
			if(eating_frame_index == NUM_OF_FRAME_TYPE_1_EATING)
				eating_frame_index = 0;
			shape.setTexture(&eating_frames_texture[eating_frame_index]);	
		}
	}
	else
	{
		if(current_global_time - last_time_change_frame >= frame_rate)
		{
			walking_frame_index ++;
			last_time_change_frame = current_global_time;
			if(walking_frame_index == NUM_OF_FRAME_TYPE_1_WALKING)
				walking_frame_index = 0;
			shape.setTexture(&walking_frames_texture[walking_frame_index]);	
		}	
	}	
}

bool Zombie::is_get_Shot(sf::Vector2f bullet_position ,std::string bullet_type)
{
	if(bullet_position.x >= shape.getPosition().x)
	{
		if(bullet_type == "Ice Bullet")
		{
			velocity = ZOMBIE_VELOCITY/2;
			walk_again_velocity = velocity;
		}
		damage --;
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
	eat_status = true;
}

void Zombie::go_Forward()
{
	velocity = walk_again_velocity;
	eat_status = false;

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

bool Zombie::is_House_Reached(float house_x_position)
{
	if(shape.getPosition().x <house_x_position)
		return true;
	return false;
}