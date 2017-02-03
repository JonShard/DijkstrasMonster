#if !defined(__ScreenSetup_h)
#define __ScreenSetup_h

#include <SFML/Graphics.hpp>					//for Graphics stuff
#include "HelpFunctions.h"						//The header file for HelpFunctions, contains useful functions.
#include "Node.h"								//The header file for the node class.
#include "Path.h"								//The header file for the path class.
#include "Constants.h"							//The header file containing all the Constants used in this program.


struct MainMenuScreen
{
	sf::Sprite logo;			//Logo image:
	sf::Texture logoTexture;

	//Button start
	//button options
	
};

struct OptionsScreen
{

};

struct GameScreen
{

};


struct Background
{
	sf::Sprite bkTopSprite;	//Background images:
	sf::Sprite bkMiddleSprite;
	sf::Sprite bkBottomSprite;
	sf::Texture bkTopTexture;
	sf::Texture bkMiddleTexture;
	sf::Texture bkBottomTexture;
	float bkTopRotation;				//The speed the the background images will be rotating at.
	float bkMiddleRotation;
	float bkBottomRotation;

};

void configureUI();


#endif