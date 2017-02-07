#if !defined (__SoundManager_h)							//If this file has not been defined, define it now.
#define __SoundManager_h

#include <SFML/Graphics.hpp>					//for Graphics stuff
#include <SFML/Audio.hpp>
#include "HelpFunctions.h"
#include "Constants.h"							//The header file containing all the Constants used in this program.


struct GuiSound
{
	sf::SoundBuffer submitSound;					//Button sounds:
	sf::SoundBuffer switchSound;
	sf::SoundBuffer backSound;
	sf::SoundBuffer errorSound;
};

struct Player
{
	sf::Sound ButtonSound;							//Will play all the button sounds from steams.
	sf::Music MusicSound;							//will play all the music from file.
};

void configureSounds();
void playGuiSound(int select);				//Starts playing selected sound.
void playMusic(int select);						//Starts playing selecet music.


#endif