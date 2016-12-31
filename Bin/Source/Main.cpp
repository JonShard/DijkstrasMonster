#include <SFML/Graphics.hpp>		//for Graphics stuff
#include <iostream>
#include "HelpFunctions.h"
#include "Node.h"
#include "Path.h"


using namespace std;
using namespace sf;

const float pathThicknessMultiplier = 1;

const int windowWidth = 800;
const int windowHeight = 1200;



int rantime()					//returns the amount of seconds the app has ran.  
{
	Clock upTime;
	Time ElapsedTime = upTime.getElapsedTime();
	return int(upTime.getElapsedTime().asSeconds());
}


int main ()//start  			//first thing that runs, duuh!
{
	RenderWindow window(VideoMode(windowHeight, windowWidth), "Dijkstra's Monster", //opens the window and sets the size.
						 Style::Titlebar | Style::Close);


	testHelp();



	while(window.isOpen())//update	//ran every update fram the window is open.
	{



		Event event;
		while(window.pollEvent(event))		//It think this checks for event happening.
		{


			if(event.type == Event::Closed)	//if the event happening is closed:
			{								//then close the window as well.
				window.close();				
			}
		}


		window.clear();						//clears the canvas.
		//window draw!
		window.display();					//sends the buffer to the display.

	} 

	
	return 0;
}