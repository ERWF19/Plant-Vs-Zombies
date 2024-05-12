#include "zombie.h"

Zombie::Zombie(std::string z_type,std::vector<float> options,std::string i , std::string l_i ,float x0 ,float  y0)
{
	type = z_type;

	last_time_change_frame = 0;
	id = i;
	line_id = l_i;
	eat_status = false;

	if(type == ZOMBIE_TYPE_1)
	{
		health = options[1];
		damage = options[0];
		velocity = -options[3];
		walk_again_velocity = -options[3];
		width = ZOMBIE_TYPE_1_WIDTH;
		height= ZOMBIE_TYPE_1_HEIGHT;
		eating_speed = options[2];

		Load_Frames(ZOMBIE_TYPE_1_WALKING_FRAMES_ROOT,ZOMBIE_TYPE_1_EATING_FRAMES_ROOT
			,NUM_OF_FRAME_TYPE_1_WALKING,NUM_OF_FRAME_TYPE_1_EATING);

		shape.setSize(sf::Vector2f(width,height));
		shape.setTexture(&walking_frames_texture[walking_frame_index]);
		shape.setPosition(sf::Vector2f(x0,y0 - ZOMBIE_TYPE_1_HEIGHT/2));

	}
	else if(type == ZOMBIE_TYPE_2)
	{
		health = options[1];
		damage = options[0];
		velocity = -options[3];
		walk_again_velocity = -options[3];
		width = ZOMBIE_TYPE_2_WIDTH;
		height= ZOMBIE_TYPE_2_HEIGHT;
		eating_speed = options[2];

		Load_Frames(ZOMBIE_TYPE_2_WALKING_FRAMES_ROOT,ZOMBIE_TYPE_2_EATING_FRAMES_ROOT
			,NUM_OF_FRAME_TYPE_2_WALKING,NUM_OF_FRAME_TYPE_2_EATING);

		shape.setSize(sf::Vector2f(width,height));
		shape.setTexture(&walking_frames_texture[walking_frame_index]);
		shape.setPosition(sf::Vector2f(x0,y0 - 250));
	}
}

void Zombie::Load_Frames(std::string walking_frames_root,std::string eating_frames_root,int num_of_walking_frames,int num_of_eating_frames)
{
	frame_rate = ZOMBIE_FRAME_RATE;


	walking_frame_index = 0;
	for(int i=0 ; i<num_of_walking_frames ; i++)
	{
		sf::Texture walking_texture;
		std::ostringstream path;
		path << walking_frames_root << i + 1 << ".png";
		if(!walking_texture.loadFromFile(path.str()))
		{
			std:: cout << "error in loading zombie frames texture !" << std::endl;
		}
		walking_frames_texture.push_back(walking_texture);
	}

	eating_frame_index = 0;
	for(int i=0 ; i<num_of_eating_frames ; i++)
	{
		sf::Texture eating_texture;
		std::ostringstream path;
		path << eating_frames_root << i + 1 << ".png";
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
			if(eating_frame_index == eating_frames_texture.size())
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
			if(walking_frame_index == walking_frames_texture.size())
				walking_frame_index = 0;
			shape.setTexture(&walking_frames_texture[walking_frame_index]);	
		}	
	}	
}

bool Zombie::is_get_Shot(sf::Vector2f bullet_position ,std::string bullet_type,float bullet_damage)
{ 
		if(bullet_position.x >= shape.getPosition().x && bullet_position.y >= shape.getPosition().y + 50)
		{
			if(bullet_type == "Ice Bullet")
			{
				if(type == ZOMBIE_TYPE_1)
					velocity = ZOMBIE_TYPE_1_VELOCITY/2;
				else if(type == ZOMBIE_TYPE_2)
					velocity = ZOMBIE_TYPE_2_VELOCITY/2;

				walk_again_velocity = velocity;
			}
			health -= bullet_damage;
			return true;
		}
		return false;
}


float Zombie::get_x_Position()
{
	return shape.getPosition().x;
}

float Zombie::get_y_Position()
{
	return shape.getPosition().y;
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
	if(health == 0)
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

float Zombie::get_Damage()
{
	return damage;
}

float Zombie::get_Velocity()
{
	return velocity;
}