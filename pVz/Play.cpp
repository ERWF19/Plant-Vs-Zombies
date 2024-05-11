#include "functions.h"

void Play(sf::RenderWindow &window)
{
	GamePlay gameplay(window.getSize().x,window.getSize().y);

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

		if(global_time.getElapsedTime().asSeconds() > 5 && global_time.getElapsedTime().asSeconds() < 5.02)
		{
			zombie_intro_sound.play();
			gameplay.Generate_Zombie();
			zombieـperiodicity.restart();
		}

		if(zombieـperiodicity.getElapsedTime().asSeconds() >= 15 && global_time.getElapsedTime().asSeconds() > 60)
		{
			gameplay.Generate_Zombie();
			zombieـperiodicity.restart();
		}

		if(falling_sun_periodicity.getElapsedTime().asSeconds() >= 3)
		{
			std::srand(time(0));
			float sun_x_position = FALLING_SUN_PRIMARY_X_POSITION  + (std::rand() % window.getSize().x - SQUARE_LENGTH);
			float sun_y_position = FALLING_SUN_PRIMARY_Y_POSITION;
			gameplay.Generate_Falling_Sun(sun_x_position,sun_y_position);
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