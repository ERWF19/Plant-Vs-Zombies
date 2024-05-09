#include "functions.h"

void Play(sf::RenderWindow &window)
{
	GamePlay gameplay(window.getSize().x,window.getSize().y);

	sf::Clock global_time;
	sf:: Clock zombieـperiodicity;

	sf::Music soundtrack;
	if(!soundtrack.openFromFile("soundeffect/grasswalk.ogg"))
	{
		std:: cout << "Error in loading soundtrack music" << std::endl;
	}
	soundtrack.play();

	sf::SoundBuffer buffer;
	sf::Sound zombie_intro_sound;

	if(!buffer.loadFromFile("soundeffect/awooga.ogg"))
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

		gameplay.Move_Zombies();
		gameplay.Plants_Fire(global_time.getElapsedTime().asSeconds());
		gameplay.Move_Bullets();
		gameplay.Bullet_Impact();
		gameplay.Plants_Death();
		gameplay.Zombie_Death();
		gameplay.Kill_Plants(global_time.getElapsedTime().asSeconds());
		window.clear();
		gameplay.draw(window,global_time.getElapsedTime().asSeconds());
		window.display();
	}
}