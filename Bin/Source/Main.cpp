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
	int numerOfNodes = randomNumber(5, 20, ranMillisec());	//generat amount of nodes.
	
	for(int i = 0; i < numerOfNodes; i++)
	{
		lastNode++;
		nodes[lastNode].setPos();
		nodes[lastNode].setColor();

	}

}






int main ()		  							//first thing that runs, duuh!
{

	RenderWindow window(VideoMode(windowHeight, windowWidth), "Dijkstra's Monster", //opens the window and sets the size.
						 Style::Titlebar | Style::Close);



	while(window.isOpen())					//ran every update fram the window is open.
	{

		
		randomNumber(1, 6000, ranMillisec());
		

		Event event;
		while(window.pollEvent(event))		//It think this checks for event happening.
		{

			if (Keyboard::isKeyPressed(Keyboard::G))
			{
				generateRandomNetwork();			//random network when g is pressed.
			}


			if(event.type == Event::Closed)	//if the event happening is closed:
			{								//then close the window as well.
				window.close();				
			}
		}

		window.clear();						//clears the canvas.
		
		//for (int i = 0; i < lastNode; i++) window.draw(shapes[i]);

		window.display();					//sends the buffer to the display.

	} 

	
	return 0;
}



