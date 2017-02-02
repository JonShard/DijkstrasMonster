#if !defined(__ScreenSetup_h)
#define __ScreenSetup_h

#include <SFML/Graphics.hpp>					//for Graphics stuff
#include "HelpFunctions.h"						//The header file for HelpFunctions, contains useful functions.
#include "Node.h"								//The header file for the node class.
#include "Path.h"								//The header file for the path class.
#include "Constants.h"							//The header file containing all the Constants used in this program.


struct MainMenuScreen
{
	sf::Sprite logo;
	sf::Sprite backgroundTop;
	sf::Sprite backgroundBottom;
	//Button start
	//button options
	
};

struct OptionsScreen
{

};

struct GameScreen
{
	sf::RectangleShape nodeBoard;

};

void updateScreens();


#endif