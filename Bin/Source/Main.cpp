//	Created by Jone Skaara(Jon Shard) at NTNU in Gjoovik, Norway. This is a small game built around Dijkstras algorith.
//
#include <SFML/Graphics.hpp>		//for Graphics stuff
#include <iostream>					//Used for printing to screen(debug) and some input.


#include "HelpFunctions.h"					//The header file for HelpFunctions, contains useful functions.
#include "StateMachine.h"					//Handles switching between states and updating them.
#include "ScreenSetup.h"
#include "Node.h"							//The header file for the node class.
#include "Path.h"							//The header file for the path class.
#include "Constants.h"						//The header file containing all the Constants used in this program.

using namespace std; 						//The standard liberary namespace.
using namespace sf;							//The SFML liberary namespace.



//Global variables
int state = 2;								//what state the game is in: MainMenu = 0, Options = 1, Game = 2
Node nodes[MAXNODES + 1];					//Array of nodes on the board.
Path paths[MAXPATHS + 1];					//Array of paths between the nodes.
int lastNode = 0;							//Last used node. Useful for loops.
int lastPath = 0;							//Same thing for the paths.


ContextSettings settings;					//The settings Context, all the config info the window needs to run.
RenderWindow window;						//The window that draws the graphics on the screen.
Font font;									//The font imported from file used to print text on Screen.





int main ()		  														//First thing that runs, duuh!
{
	settings.antialiasingLevel = 4;										//If the video processor supports it, the graphics will be
																		//rended with antialiasing of 4. Planning to allow this to be changed in options.

	window.create(VideoMode(windowHeight, windowWidth), "Dijkstra's Monster", //opens the window and sets the size.
						 Style::Titlebar | Style::Close);	


	if(!font.loadFromFile("../OtherAssets/FONT.ttf"))					//Loads font from file. Gives error in console if
	{
		cout << "\nUnable to load font. Looking for \"FONT.fft\" in OtherAssets folder.";
	}

	updateScreens();



	//update()
	while(window.isOpen())
	{
		update();			//checks the keypress events, upadates the state, and draws to buffer.

		//////////////		Screen drawing		///////////////
		window.clear();													//Clears the canvas.

		switch (state)													//what state the game is in: MainMenu = 0, Options = 1, Game = 2
		{
			case 0:	//Main Menu
				updateMainMenu();
			break;

			case 1:	//Options
				updateOptions();
			break;

			case 2:	//Game
				updateGame();
			break;
		}	

		window.display();												//Sends the buffer to the display.
		//////////////		Screen drawn		///////////////
	} 

	cout << "\n\n";				
	return 0;
}


