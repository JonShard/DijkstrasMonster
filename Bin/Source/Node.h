#if !defined(__Node_h)
#define __Node_h
#include <SFML/Graphics.hpp>			//for Graphics stuff
#include "HelpFunctions.h"
#include "Constants.h"


class Node
{

	private:
		sf::CircleShape nodeBody;
		sf::Vector2f position;				//position of the node in pixels	
		float rotationSpeed;			//how fast the icon rotates.
		float rotation;
		bool isGoal;					//is this node the level's goal.
		int powerUp;					//what power the node has 0 is none.

		int lastIndex;					//The last node refered to by this node.
		int connectedNotes[MAXPATHSPERNODE];//index of the connected nodes.

	public:
		Node();
		void setAll();
		void setPos();					//set a random pos.
		void setPos(sf::Vector2f vec);			//set a spesific pos.
		void setRotationSpeed();		//sets a random rot speed.
		void setRotationSpeed(float rtspd);	//sets a the rot speed.
		void updateRotation();
		void setColor();				//sets random color.
		void setColor(sf::Color col);			//sets the color.
		void setPowerUp(int pwr);			//sets the powerup.
		bool connectNode(int index);	//Adds a node to the array. Returns false if full.

		sf::CircleShape getShape();
		sf::Vector2f getPos();				//returns the pos.
		sf::Color getColor();				//returns the color.
		float getRotationSpeed();		//returns the rot speed.
		int getPowerUp();				//returns the powerup.
		int getConnectedNode(int index);//returns the index of the x.th connected node. 0 if no empty.

};





#endif