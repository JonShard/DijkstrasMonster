#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Node.h"

using namespace sf;
using namespace std;

extern Node nodes[];		//imports global veriables from main:
extern int lastNode;


Node::Node()
{
	
}

void Node::setAll()
{
	cout << "\n\n\n======================="
		 << "\nGenerating new node.";
	setPos();
	setColor();
	setRotationSpeed();
	nodeBody.setRadius(nodeRadius);
	nodeBody.setOrigin(nodeBody.getRadius(), nodeBody.getRadius());	//sets the pivot point of the node.
	nodeBody.setPointCount(5);
	nodeBody.setOutlineThickness(-4);
	nodeBody.setOutlineColor(Color(250, 150, 100));
}

void Node::setPos() 					//set a random pos.
{
	cout << "\nPOSITION";
	do{
	position.x = randomNumber(nodeGenMargin, windowHeight - nodeGenMargin, ranMillisec());
    position.y = randomNumber(nodeGenMargin, windowWidth - nodeGenMargin, ranMillisec());
    }while(!emptySpace(position, nodeToNodeMargin));

    nodeBody.setPosition(position);
}


void Node::setPos(Vector2f vec) 		//set a spesific pos.
{	position = vec;		}


void Node::setRotationSpeed() 			//sets a random rot speed.
{	rotationSpeed = ((randomNumber(0, 15, ranMillisec()) - randomNumber(0, 15, ranMillisec())) / 100.0F);
}

void Node::setRotationSpeed(float rtspd)//sets a the rot speed.
{	rotationSpeed = rtspd;	}

void Node::updateRotation()
{	rotation += rotationSpeed;
	nodeBody.setRotation(rotation);
}

void Node::setColor() 					//sets random color.
{
	int r = randomNumber(100, 240, ranMillisec());
	int g = randomNumber(100, 240, ranMillisec());
	int b = randomNumber(100, 240, ranMillisec());
	nodeBody.setFillColor(Color(r, g, b));
}


void Node::setColor(Color col) 				//sets the color.
{	
	nodeBody.setFillColor(col);	
}


void Node::setPowerUp(int pwr) 				//sets the powerup.
{	powerUp = pwr;	}


bool Node::connectNode(int index) 		//Adds a node to the array. Returns false if full.
{
	int i = -1;
	while (connectedNotes[++i] != 0 && i < 10)
	{
		if (i == 0) 
		{
			connectedNotes[i] = index;
			return true;
		}
	}
	
	return false;				//both nodes are taken.
}


CircleShape Node::getShape()	//returns the shape so it can be drawn.
{
	return nodeBody;
}

Vector2f Node::getPos() 				//returns the pos.
{	return position;	}

Color Node::getColor() 					//returns the color.
{	return nodeBody.getFillColor(); 	}

float Node::getRotationSpeed() 			//returns the rot speed.
{	return rotationSpeed;	}

int Node::getPowerUp() 					//returns the powerup.
{	return powerUp;		}

int Node::getConnectedNode(int index)	//returns the index of the x.th connected node. 0 if no empty.
{	
	for (int i = 0; i < sizeof(connectedNotes) / sizeof(connectedNotes[0]); i++)
	{
		if (i = index) return connectedNotes[i];
	}
}


bool emptySpace(Vector2f location, int rad)		//returns false if node has another node too close to it.
{

	for (int n = 0; n < lastNode; n++)
	{

		if ( sqrt(
				pow(abs(location.x - nodes[n].getPos().x),  2)
			  + pow(abs(location.y - nodes[n].getPos().y),  2)) < rad)
		{
			return false;
		}

		
	}

	return true;
}
