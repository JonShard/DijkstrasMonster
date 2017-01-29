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
	setNodes(-1, -1);

	cout << "\n\n\n======================="
		 << "\nSetting up path #" << lastPath 
		 << "\nNode1: " << node1 << " \tnode2: " << node2;
	setWeight();
	setColor();

	for (int r, c, i = 0; i < 2; i++)		//sets the two nodes the path is between.
	{
		do
		{
			r = randomNumber(0, lastNode-1);
			c++;
		}while(!addNode(r) && c < 1000);		//the c is just there to make sure it does not loop forever.
		cout << "\nAdded node " << r;
	}
	cout << "\nnode1: " << node1 << "\t node2: " << node2 << "\tlastNode: " << lastNode-1;
	pathBody.setSize(Vector2f(lengthBetweenNodes(node1-1, node2-1), pathThickness + (weight/4))); // -1 to compansate for lastNode++ before generation is complete.
	pathBody.setPosition(nodePos(node1-1));
	pathBody.setRotation(getAngle(nodePos(node1-1), nodePos(node2-1)));
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
	if (node1 == -1)											//problem: sets both node 1 and 2 as the same index.
	{
		cout << "\nSetting Node 1 to: " << index;
		node1 = index;
		return true;			//set a node successfully.
	}
	else if (node2 == -1 && node1 != index)
	{
		cout << "\nSetting Node 2 to: " << index;
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
{	int* troll;		//cuz y !
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