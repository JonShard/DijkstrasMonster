#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>										//Used to convert int to string
#include "Path.h"

using namespace sf;
using namespace std;

extern int lastNode;
extern int lastPath;
extern Font font;


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
	do{
		setNodes(-1, -1);	//reset the node indexes so adding new onces goes smoothly.
		for (int r, c, i = 0; i < 2; i++)		//sets the two nodes the path is between.
		{
			do
			{
				r = randomNumber(0, lastNode);
				c++;
				cout << "\nRetry count: " << c;
			}while(!addNode(r) && c < 2000);		//the c is just there to make sure it does not loop forever.
			cout << "\nAdded node " << r;
		}
		cout << "\nnode1: " << node1 << "\tnode2: " << node2 << "\tlastNode: " << lastNode << "\tlastPath: " << lastPath;
	}while(!noDoublePaths()); //Crashes here for some reason.

	
	pathBody.setSize(Vector2f(lengthBetweenNodes(node1-1, node2-1), pathThickness - (weight/3))); // -1 to compansate for lastNode++ before generation is complete.
	pathBody.setPosition(nodePos(node1-1));
	pathBody.setRotation(getAngle(nodePos(node1-1), nodePos(node2-1)));

	pathText.setFont(font);
	stringstream convert;
	convert << weight;			//converting int weight to a string that can be printed.
	pathText.setString(convert.str());
	pathText.setColor(pathColor + Color(30,30,30,0));
	pathText.setCharacterSize(WEIGHTTEXTSIZE);
	pathText.setPosition(	Vector2f((nodePos(node1-1).x + nodePos(node2-1).x)/2, (nodePos(node1-1).y + nodePos(node2-1).y)/2));
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
	if (node2 == -1 && node1 != index)
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


Vector2f Path::getNodes()							//returns an array with connected nodes.
{	
	return Vector2f(node1, node2);
}


Color Path::getColor()
{
	return pathColor;
}


RectangleShape Path::getShape()
{	return pathBody;	}


Text Path::getText()
{	return pathText;	}