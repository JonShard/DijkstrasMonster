//	Created by Jone Skaara(Jon Shard) at NTNU in Gjoovik, Norway. This is a small game built around Dijkstras algorith.
//
#include <SFML/Graphics.hpp>		//for Graphics stuff
#include <iostream>					//Used for printing to screen(debug) and some input.

#include "HelpFunctions.h"					//The header file for HelpFunctions, contains useful functions.
#include "Node.h"							//The header file for the node class.
#include "Path.h"							//The header file for the path class.
#include "Constants.h"						//The header file containing all the Constants used in this program.

using namespace std; 						//The standard liberary namespace.
using namespace sf;							//The SFML liberary namespace.

//Global variables
Node nodes[MAXNODES + 1];					//Array of nodes on the board.
Path paths[MAXPATHS + 1];					//Array of paths between the nodes.
int lastNode = 0;							//Last used node. Useful for loops.
int lastPath = 0;							//Same thing for the paths.
Font font;									//The font imported from file used to print text on Screen.


void generate(int nodeCount, int pathCount, int allowedPaths)			//Handles the actuall generation,
{																		//calls the object to have them generate
	for(int i = 0; i < nodeCount; i++)									//the right values.
	{
		nodes[lastNode].setAll();
		lastNode++;
	}
	 
	cout << "\n\n\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" 
		 << "\nNumber of nodes are: " << nodeCount << "\t Number of paths are: " 
		 << pathCount << "\t  Max allowed nodes: " << allowedPaths
		 << "\nFinished generating nodes."
		 << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";

	for(int j = 0; j < pathCount; j++)
	{
		paths[lastPath].setAll();
		lastPath++;
	}
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





int main ()		  														//First thing that runs, duuh!
{
	ContextSettings settings;
	settings.antialiasingLevel = 4;										//If the video processor supports it, the graphics will be
																		//rended with antialiasing of 4. Planning to allow this to be changed in options.
	RenderWindow window(VideoMode(windowHeight, windowWidth), "Dijkstra's Monster", //opens the window and sets the size.
						 Style::Titlebar | Style::Close);


	RectangleShape nodeBoard (Vector2f(windowHeight - 2*nodeGenMargin, windowWidth - 2*nodeGenMargin));
	nodeBoard.setPosition(Vector2f(nodeGenMargin, nodeGenMargin));
	nodeBoard.setFillColor(Color(35,35,35));

	if(!font.loadFromFile("../OtherAssets/FONT.ttf"))					//Loads font from file. Gives error in console if
	{
		cout << "\nUnable to load font. Looking for \"FONT.fft\" in OtherAssets folder.";
	}


	randomNetwork();													//TEMPORARY - Generate a random network at launch.

	//update()
	while(window.isOpen())
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






			if(event.type == Event::Closed)								//If the event happening is closed:
			{															//then close the window as well.
				window.close();
			}
		}



		//////////////		Screen drawing		///////////////

		window.clear();													//Clears the canvas.
		window.draw(nodeBoard);

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


		window.display();												//Sends the buffer to the display.

		//////////////		Screen drawn		///////////////
	} 

	cout << "\n\n";				
	return 0;
}



