#if !defined (__Path_h)
#define __Path_h
#include <SFML/Graphics.hpp>			//for Graphics stuff


class Path
{

	private:
		int weight;
		sf::Color pathColor;
		int node1, node2;


	public:
	
	void setWeight(int weight);
	void setNodes(int node1, int node2);		//sets both nodes to spesifc indexes.
	bool addNode(int node);						//adds a node to path, false if has two.	
	void setColor();							//sets random color.
	void setColor(sf::Color);						//sets the color.

	int getWeight();							//returns weight of path.
	int* getNodes();							//returns an array with connected nodes.

};


#endif