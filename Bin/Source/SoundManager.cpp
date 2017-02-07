#include <iostream>
#include <SFML/Graphics.hpp>													//For Graphics stuff
#include <SFML/Audio.hpp>
#include "SoundManager.h"

using namespace std;
using namespace sf;

GuiSound GS;
Player PL;


void configureSounds()
{
	if(!GS.submitSound.loadFromFile("../Sounds/Submit.ogg"))
				cout << "\nFailed loading Sounds/Submit.ogg";	//Load texture.
	else cout << "\nLoaded Submit.ogg";
	
	if(!GS.switchSound.loadFromFile("../Sounds/Switch.ogg"))
				cout << "\nFailed loading Sounds/Switch.ogg";	//Load texture.
	else cout << "\nLoaded Switch.ogg";
	
	if(!GS.backSound.loadFromFile("../Sounds/Back.ogg"))
				cout << "\nFailed loading Sounds/Back.ogg";	//Load texture.
	else cout << "\nLoaded back.ogg";
	
	if(!GS.errorSound.loadFromFile("../Sounds/Error.ogg"))
				cout << "\nFailed loading Sounds/Error.ogg";	//Load texture.
	else cout << "\nLoaded error.ogg";

}

void playGuiSound(int select)
{
	cout << "\nPlaying GuiSound.";
	if(select == 0) PL.ButtonSound.setBuffer(GS.submitSound);
	if(select == 1) PL.ButtonSound.setBuffer(GS.switchSound);
	if(select == 2) PL.ButtonSound.setBuffer(GS.backSound);
	if(select == 3) PL.ButtonSound.setBuffer(GS.errorSound);

	PL.ButtonSound.play();
}