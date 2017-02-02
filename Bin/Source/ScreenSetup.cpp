#include "ScreenSetup.h"
#include <iostream>																//For printing debug info to terminal.
#include <cmath>																//sqrt(), pow(), abs(), atan2().
#include <SFML/Graphics.hpp>													//For Graphics stuff
#include "HelpFunctions.h"

using namespace std; 															//The standard liberary namespace.
using namespace sf;																//The SFML liberary namespace.




MainMenuScreen MMS;
OptionsScreen OPS;
GameScreen GMS;


void updateScreens()
{


	/*logo;
	backgroundTop;
	backgroundBottom;
	//Button start
	//button options
	*/



	
	GMS.nodeBoard.setSize(Vector2f(windowHeight - 2*nodeGenMargin, windowWidth - 2*nodeGenMargin));
	GMS.nodeBoard.setPosition(Vector2f(nodeGenMargin, nodeGenMargin));
	GMS.nodeBoard.setFillColor(Color(35,35,35));
	

}