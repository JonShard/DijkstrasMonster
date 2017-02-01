#if !defined (__Path_h)							//If this file has not been defined, define it now.
#define __Path_h
#include <SFML/Graphics.hpp>					//For Graphics stuff
#include "HelpFunctions.h"						//The header file for HelpFunctions, contains useful functions.
#include "Constants.h"							//The header file containing all the Constants used in this program.


class Path
{

	private:
		sf::RectangleShape pathBody;			//The Line between the nodes.
		sf::Text pathText;						//The Text displaying the weight of the node.
		int weight;								//the weight of the path, how much does it take to travel this path.
		sf::Color pathColor;					//Color of the path line/pathBody and text.
		int node1, node2;						//Holds the indexes of the nodes used by this path.


	public:
	Path();										//Reset the values for this path.

	void setAll();								//Set all the values for this path.
	void setWeight();							//Sets a random weight
	void setWeight(int wgt);
	void setNodes(int n1, int n2);				//ets both nodes to spesifc indexes.
	bool addNode(int node);						//Adds a node to path, false if has two.	
	void setColor();							//Sets random color.
	void setColor(sf::Color clr);				//Sets the color.

	int getWeight();							//Returns weight of path.
	sf::Vector2f getNodes();					//Returns an array with connected nodes.
	sf::Color getColor();						//Returns the sf::Color.
	sf::RectangleShape getShape();				//Returns the Shape of this path so it can be drawn in main.
	sf::Text getText();							//Retuns the Text for this path, so it can be drawn.
};


#endif											//End of defined file __Path