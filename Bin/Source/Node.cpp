#include <SFML/Graphics.hpp>
#include <iostream>
#include "Node.h"

using namespace sf;
using namespace std;



void Node::setPos() 					//set a random pos.
{
	position.x = randomNumber(nodeGenMargin, windowWidth - nodeGenMargin, ranMillisec());
    position.y = randomNumber(nodeGenMargin, windowHeight - nodeGenMargin, ranMillisec());
}


void Node::setPos(Vector2f vec) 		//set a spesific pos.
{	position = vec;		}


void Node::setRotationSpeed() 			//sets a random rot speed.
{	rotationSpeed = randomNumber(0, 5, ranMillisec());	
}


void Node::setRotationSpeed(float rtspd)//sets a the rot speed.
{	rotationSpeed = rtspd;	}


void Node::setColor() 					//sets random color.
{
	int r = randomNumber(5, 210, ranMillisec());
	int g = randomNumber(5, 210, ranMillisec());
	int b = randomNumber(5, 210, ranMillisec());
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

