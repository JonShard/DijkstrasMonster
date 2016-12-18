#include <SFML/Graphics.hpp>
#include <iostream>
#include "HelpFunctions.h"

using namespace sf;

class Node
{

	private:
		Vector2f position;				//position of the node in pixels	
		Color nodeColor;				//color of the node
		float rotationSpeed;			//how fast the icon rotates.
		bool isGoal;					//is this node the level's goal.
		int powerUp;					//what power the node has 0 is none.

		int lastIndex;					//The last node refered to by this node.
		int connectedNotes[10]			//index of the connected nodes.

	public:
		void setPos();					//set a random pos.
		void setPos(Vector2f);			//set a spesific pos.
		void setRotationSpeed();		//sets a random rot speed.
		void setRotationSpeed(float);	//sets a the rot speed.
		void setColor();				//sets random color.
		void setColor(Color);			//sets the color.
		void setPowerUp(int);			//sets the powerup.
		bool connectNode(int index);	//Adds a node to the array. Returns false if full.

		Vector2f getPos();				//returns the pos.
		Color getColor();				//returns the color.
		float getRotationSpeed();		//returns the rot speed.
		int getPowerUp();				//returns the powerup.
		int getConnectedNode(int index);//returns the index of the x.th connected node. 0 if no empty.
}