#include <SFML/Graphics.hpp>		//for Graphics stuff
#include <iostream>

#include "HelpFunctions.h"
#include "Node.h"
#include "Path.h"
#include "Constants.h"

using namespace std; 
using namespace sf;


Node nodes[MAXNODES + 1];					//Array of nodes on the board.
Path paths[MAXPATHS + 1];					//Array of paths between the nodes.
int lastNode = 0;							//Last used node. Useful for loops.
int lastPath = 0;							//Same thing for the paths.



void generateRandomNetwork()
{
	lastNode = 0;
	lastPath = 0;
	int numberOfNodes = randomNumber(MINNODES, MAXNODES);	//generat amount of nodes.
	int numberOfPaths = randomNumber(numberOfNodes, MAXPATHS);

	for(int i = 0; i < numberOfNodes; i++)
	{
		nodes[lastNode].setAll();
		lastNode++;

	}
	 

	cout << "\n\n\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" 
		 << "\nFinished generating nodes."
		 << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";

	for(int j = 0; j < numberOfPaths; j++)
	{
		paths[lastPath].setAll();
		lastPath++;

	}

}






int main ()		  							//first thing that runs, duuh!
{
	ContextSettings settings;
	settings.antialiasingLevel = 4;

	RenderWindow window(VideoMode(windowHeight, windowWidth), "Dijkstra's Monster", //opens the window and sets the size.
						 Style::Titlebar | Style::Close);


	RectangleShape nodeBoard (Vector2f(windowHeight - 2*nodeGenMargin, windowWidth - 2*nodeGenMargin));
	nodeBoard.setPosition(Vector2f(nodeGenMargin, nodeGenMargin));
	nodeBoard.setFillColor(Color(35,35,35));

	generateRandomNetwork();

	while(window.isOpen())					//ran every update fram the window is open.
	{
		

		Event event;
		while(window.pollEvent(event))		//It think this checks for event happening.
		{
			if (Keyboard::isKeyPressed(Keyboard::Escape))		// ESC to quit
			{
				window.close();
			}

			if (Keyboard::isKeyPressed(Keyboard::G))
			{
				generateRandomNetwork();			//random network when g is pressed.
			}


			if(event.type == Event::Closed)	//if the event happening is closed:
			{								//then close the window as well.
				window.close();
			}
		}



		//////////////		Screen drawing		///////////////

		window.clear();						//clears the canvas.
		window.draw(nodeBoard);

		for(int p = 0; p < lastPath; p++)		//draws the paths.
		{
			window.draw(paths[p].getShape());
		}

		for (int n = 0; n < lastNode; n++)		//drawing nodes.
		{
			nodes[n].updateRotation();
			window.draw(nodes[n].getShape());	
		}


		window.display();					//sends the buffer to the display.

		//////////////		Screen drawn		///////////////
	} 

	cout << "\n\n";				
	return 0;
}



