#if !defined (__Path_h)
#define __Path_h
#include <SFML/Graphics.hpp>			//for Graphics stuff
#include "HelpFunctions.h"
#include "Constants.h"


class Path
{

	private:
		sf::RectangleShape pathBody;
		int weight;
		sf::Color pathColor;
		int node1, node2;


	public:
	Path();

	void setAll();
	void setWeight();					//sets a random weight
	void setWeight(int wgt);
	void setNodes(int n1, int n2);		//sets both nodes to spesifc indexes.
	bool addNode(int node);						//adds a node to path, false if has two.	
	void setColor();							//sets random color.
	void setColor(sf::Color clr);						//sets the color.

	int getWeight();							//returns weight of path.
	sf::Vector2f getNodes();							//returns an array with connected nodes.
	sf::Color getColor();						//returns the sf::Color.
	sf::RectangleShape getShape();

};


#endif