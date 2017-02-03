//These are the functions that actually calls the draw() in RenderWindow
#include <SFML/Graphics.hpp>								//Graphics
#include <iostream>																//For printing debug info to terminal.
#include "StateMachine.h"									//Handles switching between states and updating them.

using namespace std; 															//The standard liberary namespace.
using namespace sf;																//The SFML liberary namespace.


extern int state;														//what state the game is in: MainMenu = 0, Options = 1, Game = 2																
extern Node nodes[];															//Array of nodes on the board.
extern Path paths[];															//Array of paths between the nodes.
extern int lastNode;															//Last used node. Useful for loops.
extern int lastPath;															//Same thing for the paths.

extern Font font;														//The font used by all the text.
extern RenderWindow window;												//The window rendering the grapthics

extern MainMenuScreen MMS;
extern OptionsScreen OPS;
extern GameScreen GMS;
extern Background BKG;


void update()
{
	Event event;
	while(window.pollEvent(event))									
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape))				// ESC to quit.
		{
			window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::G))					//Random network when G is pressed.
		{
			randomNetwork();
		}

		if (Keyboard::isKeyPressed(Keyboard::S))					//Spesific network when S is pressed.
		{															//Ask for arguments in terminal (nodes and paths).
			cout << "\n\n\n\n\nAmount of nodes:\n>"; 	int nds; cin >> nds;
			cout << "\n\nAmount of paths:\n>";			int pts; cin >> pts;
			spesificNetwork(nds, pts);								//Genetate a spesific network.
		}

		if (Keyboard::isKeyPressed(Keyboard::Num1))				// Num 1 to goto main menu.
		{
			state = 0;
		}

		if (Keyboard::isKeyPressed(Keyboard::Num2))				// Num 2 to goto Options.
		{
			state = 1;
		}

		if (Keyboard::isKeyPressed(Keyboard::Num3))				// Num 3 to Goto Game.
		{
			state = 2;
		}

		if(event.type == Event::Closed)								//If the event happening is closed:
		{															//then close the window as well.
			window.close();
		}
	}
}


void updateBackground()
{
	BKG.bkBottomSprite.rotate(BKG.bkBottomRotation);
	BKG.bkMiddleSprite.rotate(BKG.bkMiddleRotation);
	BKG.bkTopSprite.rotate(BKG.bkTopRotation);
}


void updateMainMenu()
{

	updateBackground();
	drawMainMenu();
}


void updateOptions()
{

	updateBackground();
	drawOptions();
}


void updateGame()
{

	updateBackground();
	drawGame();
}


void drawMainMenu()
{

	drawBackground();
	window.draw(MMS.logo);
}


void drawOptions()
{
	drawBackground();	
}


void drawGame()
{
	drawBackground();

	for(int p = 0; p < lastPath; p++)								//Draws the paths.
		{
			window.draw(paths[p].getShape());							//PathBody(line)
			window.draw(paths[p].getText());							//PathText(weightNr)
		}

		for (int n = 0; n < lastNode; n++)								//Drawing nodes.
		{
			nodes[n].updateRotation();									//Rotates the node.
			window.draw(nodes[n].getShape());							//Draws nodeBody.
		}

}


void drawBackground()
{
	window.draw(BKG.bkBottomSprite);
	window.draw(BKG.bkMiddleSprite);
	window.draw(BKG.bkTopSprite);
}



void randomNetwork()													//Generate a random network withing the parametes
{																		//set in the constant file. MINNODES, MAXNODES...
	lastNode = 0;
	lastPath = 0;
	int numberOfNodes = randomNumber(MINNODES, MAXNODES);				//Generate amount of nodes.
	int maxpaths = 0;

	for(int i = 0; i < numberOfNodes; i++) maxpaths += i;				//Maximum number of paths a network allows without double paths.
	int numberOfPaths = randomNumber(numberOfNodes, maxpaths);
	generate(numberOfNodes, numberOfPaths, maxpaths);					//Calls the generate function with the randomized argumetns.
}


void spesificNetwork(int amountOfNodes, int amountOfpaths)				//Calls the generate functrion with spsific arguments.
{
	lastNode = 0;														//Resets lastNode and last Paths so the generation starts
	lastPath = 0;														//at the beginnig of the nodes[] and paths[].
	int maxpaths = 0;
	for(int i = 0; i < amountOfNodes; i++) maxpaths += i;				//Maximum number of paths a network allows without double paths.
	if (maxpaths >= amountOfpaths) generate(amountOfNodes, amountOfpaths, maxpaths);
	else cout << "\nERROR: too many paths.\n\n";						//Error if attempting to generate too many paths. 
}