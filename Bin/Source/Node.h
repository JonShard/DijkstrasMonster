#if !defined(__Node_h)							//If this file has not been defined, define it now.
#define __Node_h
#include <SFML/Graphics.hpp>					//For Graphics stuff
#include "HelpFunctions.h"						//The header file for HelpFunctions, contains useful functions.
#include "Constants.h"							//The header file containing all the Constants used in this program.


class Node
{

	private:
		sf::CircleShape nodeBody;
		sf::Vector2f position;					//Position of the node in pixels	
		float rotationSpeed;					//How fast the icon rotates.
		float rotation;
		bool isGoal;							//Is this node the level's goal.
		int powerUp;							//what power the node has 0 is none.

		int lastIndex;							//The last node refered to by this node.
		int connectedNotes[MAXPATHSPERNODE];	//Index of the connected nodes.

	public:
		void setAll();
		void setPos();							//Set a random pos.
		void setPos(sf::Vector2f vec);			//Set a spesific pos.
		void setRotationSpeed();				//Sets a random rot speed.
		void setRotationSpeed(float rtspd);		//Sets a the rot speed.
		void updateRotation();
		void setColor();						//Sets random color.
		void setColor(sf::Color col);			//Sets the color.
		void setPowerUp(int pwr);				//Sets the powerup.
		bool connectNode(int index);			//Adds a node to the array. Returns false if full.

		sf::CircleShape getShape();
		sf::Vector2f getPos();					//Returns the pos.
		sf::Color getColor();					//Returns the color.
		float getRotationSpeed();				//Returns the rot speed.
		int getPowerUp();						//Returns the powerup.
		int getConnectedNode(int index);		//Returns the index of the x.th connected node. 0 if no empty.

};





#endif											//End of defined file __Node