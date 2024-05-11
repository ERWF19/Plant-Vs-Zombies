#include "functions.h"

void Play(sf::RenderWindow &window)
{
	GamePlay gameplay(window.getSize().x,window.getSize().y);

	std::vector<float> attacks_options;
	std::vector<float> falling_sun_options;


	Read_From_File(attacks_options,ATTACKS_OPTION_PATH);
	Read_From_File(falling_sun_options,FALLING_SUN_OPTION_PATH);


	sf::Clock global_time;
	sf::Clock zombieـperiodicity;
	sf::Clock falling_sun_periodicity;
	sf::Clock produced_sun_periodicity;


	sf::Music soundtrack;
	if(!soundtrack.openFromFile(MAIN_SOUNDTRACK_PATH))
	{
		std:: cout << "Error in loading soundtrack music" << std::endl;
	}
	soundtrack.play();

	sf::SoundBuffer buffer;
	sf::Sound zombie_intro_sound;

	if(!buffer.loadFromFile(ZOMBIE_INTRO_SOUND_PATH))
	{
		std:: cout << "Error in loading zombie_intro_sound" << std::endl;
	}

	zombie_intro_sound.setBuffer(buffer);


	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			gameplay.Move_Mouse(window);
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				gameplay.Card_Selection(window,global_time.getElapsedTime().asSeconds());
			}
			if(event.type == sf::Event::Closed)
				window.close();
		}


		if(global_time.getElapsedTime().asSeconds() > attacks_options[1] &&  global_time.getElapsedTime().asSeconds() < attacks_options[1] + 0.02)
			zombie_intro_sound.play();

		if(global_time.getElapsedTime().asSeconds() <= attacks_options[0])
		{
			if(zombieـperiodicity.getElapsedTime().asSeconds() >=  attacks_options[1])
			{
				for(int i=0 ; i<attacks_options[2] ; i++)
					gameplay.Generate_Zombie();
				attacks_options[2] += attacks_options[3];
				zombieـperiodicity.restart();

			}
		}

		if(falling_sun_periodicity.getElapsedTime().asSeconds() >= falling_sun_options[1])
		{
			std::srand(time(0));
			float sun_x_position = FALLING_SUN_PRIMARY_X_POSITION  + (std::rand() % window.getSize().x - SQUARE_LENGTH);
			float sun_y_position = FALLING_SUN_PRIMARY_Y_POSITION;
			gameplay.Generate_Falling_Sun(sun_x_position,sun_y_position,falling_sun_options[0]);
			falling_sun_periodicity.restart();
		}

		if(produced_sun_periodicity.getElapsedTime().asSeconds() >= 10)
		{
			gameplay.Generate_Produced_Sun(global_time.getElapsedTime().asSeconds());
			produced_sun_periodicity.restart();
		}

		if(gameplay.GameOver(HOUSE_X_POSITION))
		{
			sf::Sound dead_sound;
			if(!buffer.loadFromFile(DEAD_SOUND_PATH))
			{
				std:: cout << "Error in loading dead_sound" << std::endl;
			}
			dead_sound.setBuffer(buffer);
	
			dead_sound.play();
			soundtrack.stop();	
			gameover(window);
			break;
		}

		gameplay.Plants_Fire(global_time.getElapsedTime().asSeconds());
		gameplay.Move_Zombies();
		gameplay.Move_Bullets();
		gameplay.Move_Falling_Suns();
		gameplay.Bullet_Impact();
		gameplay.Zombies_Death();
		gameplay.Plants_Death();
		gameplay.Kill_Plants(global_time.getElapsedTime().asSeconds());
		window.clear();
		gameplay.draw(window,global_time.getElapsedTime().asSeconds());
		window.display();
	}
}