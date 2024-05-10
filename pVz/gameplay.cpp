#include "gameplay.h"


GamePlay::GamePlay(float width , float height)
{
	sun_score = 0;
	playground.setSize(sf::Vector2f(width,height));

	if(!playground_texture.loadFromFile(PLAYGROUND_TEXTURE_PATH))
	{
		std::cout << "error in loading playground texture !" << std::endl;
	}
	playground.setTexture(&playground_texture);

	for(int i=0 ; i<NUM_OF_LINE ; i++)
	{
		Line *l = new Line(FIRST_LINE_X_POSITION,FIRST_LINE_Y_POSITION + (SQUARE_LENGTH * i),std::to_string(i));
		lines.push_back(l);
	}

	Load_Cards();

	if(!buffer.loadFromFile(THROW_SOUND))
	{
		std:: cout << "Error in loading throw sound !" << std::endl;
	}
	throw_sound.setBuffer(buffer);
	
}

void GamePlay::Load_Cards()
{

	Card* plant_type_1_card = new Card(PLANT_TYPE_1 ,50,FIRST_CARD_COORDINATE_X,FIRST_CARD_COORDINATE_Y,PLANT_TYPE_1_ON_CARD_PATH,PLANT_TYPE_1_OFF_CARD_PATH,8);
	cards.push_back(plant_type_1_card);

	Card* plant_type_2_card = new Card(PLANT_TYPE_2 ,100,FIRST_CARD_COORDINATE_X,FIRST_CARD_COORDINATE_Y + CARD_HEIGHT + 10,PLANT_TYPE_2_ON_CARD_PATH,PLANT_TYPE_2_OFF_CARD_PATH,8);
	cards.push_back(plant_type_2_card);

	Card* plant_type_3_card = new Card(PLANT_TYPE_3 ,175,FIRST_CARD_COORDINATE_X,FIRST_CARD_COORDINATE_Y + 2 * (CARD_HEIGHT +10),PLANT_TYPE_3_ON_CARD_PATH,PLANT_TYPE_3_OFF_CARD_PATH,8);
	cards.push_back(plant_type_3_card);

	Card* plant_type_4_card = new Card(PLANT_TYPE_4 ,50,FIRST_CARD_COORDINATE_X,FIRST_CARD_COORDINATE_Y + 3 * (CARD_HEIGHT +10),PLANT_TYPE_4_ON_CARD_PATH,PLANT_TYPE_4_OFF_CARD_PATH,30);
	cards.push_back(plant_type_4_card);	
	
}

void GamePlay::draw(sf::RenderWindow &window ,float current_global_time)
{
	window.draw(playground);
	Draw_Cards(window , current_global_time);
	Draw_Plants(window);
	Draw_Zombies(window,current_global_time);
	Draw_Bullets(window);
}

void GamePlay::Move_Mouse(sf::RenderWindow &window)
{
	sf::Vector2i localPosition = sf::Mouse::getPosition(window);
	sf::Vector2f card_position;
	for(int i=0 ; i<cards.size() ; i++)
	{

		card_position = cards[i]->getPosition();
		if(localPosition.x >= card_position.x && localPosition.x <= card_position.x + CARD_WIDTH
			&& localPosition.y >= card_position.y && localPosition.y <= card_position.y + CARD_HEIGHT)
		{
			selected_card_index = i;
			break;
		}
		else
		{
			selected_card_index = -1;
		}
	}
}

void GamePlay::Card_Selection(sf::RenderWindow &window , float current_global_time)
{
	if(selected_card_index == 0 || selected_card_index == 1 || selected_card_index == 2 || selected_card_index == 3)
	{
		Card * selected_card = cards[selected_card_index];
		if(selected_card->is_Valid())
		{
			sf::Vector2i localPosition;
			Plant *new_plant = new Plant(selected_card_index);

			plants.push_back(new_plant);
			bool selected_statement = true;
			while(window.isOpen())
			{
				sf::Event event;
				while(window.pollEvent(event))
				{
					localPosition = sf::Mouse::getPosition(window);
					if(is_Line_Range(localPosition , new_plant))
					{
						if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							selected_card->Apply_Current_Time(current_global_time);
							Line* plant_line = Find_Line(new_plant->line_id);
							plant_line->Add_Plant(new_plant);
							selected_statement =  !is_Valid_Square(new_plant);
							break;
						}
					}

					if(event.type == sf::Event::Closed)
						window.close();
				}
				if(!selected_statement)
					break;
				window.clear();
				draw(window,current_global_time);
				window.display();
			}
		}
	}
}
bool GamePlay::is_Line_Range(sf::Vector2i localPosition ,Plant *p)
{
	for(int i=0 ; i<NUM_OF_LINE; i++)
	{
		if(lines[i]->is_Square_Range(localPosition,p))
			return true;
	}
	return false;
	
}

void GamePlay::Draw_Cards(sf::RenderWindow &window ,float current_global_time)
{
	for(int i=0 ; i<cards.size() ; i++)
	{
		cards[i]->draw(window,current_global_time);
	}
}

void GamePlay::Draw_Plants(sf::RenderWindow &window)
{
	for(int i=0 ; i<plants.size() ; i++)
	{
		plants[i]->draw(window);
	}
}
void GamePlay::Draw_Zombies(sf::RenderWindow &window , float current_global_time)
{
	for(int i=0 ; i<zombies.size() ; i++)
	{
		zombies[i]->draw(window,current_global_time);
	}
}

void GamePlay::Draw_Bullets(sf::RenderWindow &window)
{
	for(int i=0 ; i<bullets.size() ; i++)
	{
		bullets[i]->draw(window);
	}
}



bool GamePlay::is_Valid_Square(Plant *p)
{
	for(int i=0 ; i<NUM_OF_LINE ; i++)
	{
		if(p->line_id == lines[i]->id)
			if(lines[i]->is_Square_Free(p))
				return true;
	}
	return false;
}

void GamePlay::Generate_Zombie()
{
	std::srand(time(0));
	Zombie* z = lines[0 +(std::rand() % 5)]->Generate_Zombie();
	zombies.push_back(z);
}

void GamePlay::Move_Zombies()
{
	for(int i=0 ; i<zombies.size() ; i++)
	{
		zombies[i]->Move();
	}
}

void GamePlay::Plants_Fire(float current_global_time)
{
	for(int i=0 ; i<plants.size() ; i++)
	{
		Line *plant_line = Find_Line(plants[i]->line_id);

		if(plants[i]->is_Shoot_Time(current_global_time) && plants[i]->is_Shooter())
		{
			if(plant_line->is_Deadline(plants[i]))
			{
				Bullet* new_bullet = plants[i]->Shoot_Bullet(current_global_time);
				throw_sound.play();
				bullets.push_back(new_bullet);
			}
		}
	}
}

Line* GamePlay::Find_Line(std::string line_id)
{
	for(int i=0 ; i<lines.size() ; i++)
	{
		if(lines[i]->id == line_id)
			return lines[i];
	}
	return NULL;
}

void GamePlay::Move_Bullets()
{
	for(int i=0 ; i<bullets.size() ; i++)
	{
		bullets[i]->Move();
	}
}

void GamePlay::Bullet_Impact()
{
	Line* bullet_line;
	for(int i=0 ; i<bullets.size() ; i++)
	{
		bullet_line = Find_Line(bullets[i]->line_id);
		if(bullet_line->is_Collided(bullets[i]))
		{
			bullets.erase(bullets.begin() + i);
		}
	}
}

void GamePlay::Kill_Plants(float current_global_time)
{
	Line* zombie_line;
	for(int i=0 ; i<zombies.size() ; i++)
	{
		if(zombies[i]->is_Bite_Time(current_global_time))
		{
			zombie_line = Find_Line(zombies[i]->line_id);
			zombie_line->Eat_Plant(zombies[i],current_global_time);
		}
	}

}

void GamePlay::Plants_Death()
{
	for(int i=0 ; i<plants.size() ; i++)
	{
		if(plants[i]->is_Dead())
		{
			Line* plant_line = Find_Line(plants[i]->line_id);
			plant_line->Clean_Square(plants[i]);
			plants.erase(plants.begin() + i);
		}
	}
}

void GamePlay::Zombies_Death()
{
	for(int i=0 ; i<zombies.size() ; i++)
	{
		if(!zombies[i]->Are_You_Okay())
		{
			Line* zombie_line = Find_Line(zombies[i]->line_id);
			zombie_line->Delete_Zombie(zombies[i]);
			zombies.erase(zombies.begin() + i);
		}
	}	
}

bool GamePlay::GameOver(float house_x_position)
{
	for(int i=0 ; i<zombies.size() ; i++)
	{
		if(zombies[i]->is_House_Reached(house_x_position))
			return true;
	}
	return false;
}


