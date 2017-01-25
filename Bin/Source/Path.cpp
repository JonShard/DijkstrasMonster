#include <SFML/Graphics.hpp>
#include <iostream>
#include "Path.h"

using namespace sf;
using namespace std;

extern int lastNode;
extern int lastPath;


Path::Path()
{
	node1 = -1;	// means not set yet.
	node2 = -1;
}

	
void Path::setAll()
{
	cout << "\n\n\n======================="
		 << "\nSetting up path #" << lastPath;
	setWeight();
	setColor();

	for (int r, c, i = 0; i < 2; i++)		//sets the two nodes the path is between.
	{
		do
		{
			r = randomNumber(0, lastNode);
			c++;
		}while(!addNode(r) && c > 100);		//the c is just there to make sure it does not loop forever.
		cout << "\nAdded node " << r;
	}

	pathBody.setSize(Vector2f(lengthBetweenNodes(node1, node2), pathThickness + (weight/4)));
	pathBody.setPosition(nodePos(node1));
	pathBody.setRotation(getAngle(nodePos(node1), nodePos(node2)));
}


void Path::setWeight()
{
	cout << "\nWEIGHT";
	weight = randomNumber(1, MAXWEIGHT); 	//can not be greater than 10, cuz then the color will be over 255.
}


void Path::setWeight(int wgt)
{
	weight = wgt;
}


void Path::setNodes(int n1, int n2)		//sets both nodes to spesifc indexes.
{	node1 = n1; 	node2 = n2;	}


bool Path::addNode(int index) 		//Adds a node to the array. Returns false if full.
{
	if (node1 == -1 && node2 != index)
	{
		node1 = index;
		return true;			//set a node successfully.
	}
	else if (node2 == -1 && node1 != index)
	{
		node2 = index;
		return true;			//set a node successfully.
	}

	return false;				//both nodes are taken.
}							


void Path::setColor()							//sets random color.
{	
	int r, g , b;				// the greater the weight, the more red, the less green.
	r = weight * 25;
	g = 255 - weight * 25;
	b = 0;
	pathColor = Color(r, g, b);
	pathBody.setFillColor(pathColor);
}


void Path::setColor(Color clr)  					//sets the color.
{	pathColor = clr;	}


int Path::getWeight() 							//returns weight of path.
{	return weight;	}


int* Path::getNodes()							//returns an array with connected nodes.
{	int* troll;
	troll[0] = node1;
	troll[1] = node2; 
	return 	troll;
}


Color Path::getColor()
{
	return pathColor;
}


RectangleShape Path::getShape()
{	return pathBody;	}