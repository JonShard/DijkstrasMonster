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
	int numerOfNodes = randomNumber(5, MAXNODES, ranMillisec());	//generat amount of nodes.
	
	for(int i = 0; i < numerOfNodes; i++)
	{
		lastNode++;
		nodes[lastNode].setAll();
	}

}






int main ()		  							//first thing that runs, duuh!
{
	ContextSettings settings;
	settings.antialiasingLevel = 8;

	RenderWindow window(VideoMode(windowHeight, windowWidth), "Dijkstra's Monster", //opens the window and sets the size.
						 Style::Titlebar | Style::Close);


	RectangleShape nodeBoard (Vector2f(windowHeight - 2*nodeGenMargin, windowWidth - 2*nodeGenMargin));
	nodeBoard.setPosition(Vector2f(nodeGenMargin, nodeGenMargin));
	nodeBoard.setFillColor(Color(30,30,30));

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

		for (int i = 0; i < lastNode; i++)
		{
			nodes[i].updateRotation();
			window.draw(nodes[i].getShape());	//drawing nodes.
		}

		window.display();					//sends the buffer to the display.

		//////////////		Screen drawn		///////////////
	} 

	
	return 0;
}



