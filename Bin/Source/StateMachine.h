#if !defined(__StateMachine_h)										//If this file has not been defined, define it now.
#define __StateMachine_h

#include <SFML/Graphics.hpp>					//for Graphics stuff
#include "HelpFunctions.h"						//The header file for HelpFunctions, contains useful functions.
#include "ScreenSetup.h"
#include "Node.h"								//The header file for the node class.
#include "Path.h"								//The header file for the path class.
#include "Constants.h"							//The header file containing all the Constants used in this program.



void update();
void updateMainMenu();
void updateBackground(int select);
void updateOptions();
void updateGame();

void drawMainMenu();
void drawOptions();
void drawGame();
void drawBackground(int select);

void randomNetwork();
void spesificNetwork(int nds, int pts);




#endif