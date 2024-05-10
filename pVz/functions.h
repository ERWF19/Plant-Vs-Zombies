#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "gameplay.h"

const float HOUSE_X_POSITION = 270;
const std::string DEAD_TEXT_FONT_PATH = "font/zombie_font2.ttf";
const std::string DEAD_TEXT_STRING = "THE ZOMBIES\n    ATE YOUR\n      BRAINS !";
const float DEAD_TEXT_CHAR_SIZE = 150;
const float DEAD_TEXT_X_POSITION = 225;
const float DEAD_TEXT_Y_POSITION = 60;
const std::string GAMEOVER_SOUND_PATH = "soundeffect/evillaugh.ogg";
const std::string DEAD_SOUND_PATH = "soundeffect/scream.ogg";


void Play(sf::RenderWindow &window);

void gameover(sf::RenderWindow &window);