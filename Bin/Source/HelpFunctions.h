#if !defined(__HelpFunctions_h)					//If this file has not been defined, define it now.
#define __HelpFunctions_h
#include <SFML/Graphics.hpp>					//for Graphics stuff
#include "Node.h"								//The header file for the node class.
#include "Path.h"								//The header file for the path class.
#include "Constants.h"							//The header file containing all the Constants used in this program.

													//Generates the Network with the set arguments. Calls the object functions.
void generate(int nodeCount, int pathCount, int allowedPaths);
bool noDoublePaths();								//Used to check if a path already exist in the network.
long randomNumber(int min, int max);				//Used to generate a random number between a min and max value.
int rantime();										//Returns the amount of seconds the game has ran.
int ranMillisec();									//Retuns the current millisecond.
sf::Vector2f nodePos(int index);					//Returns the X,Y postion of a node in nodes[].
float getAngle(sf::Vector2f v1, sf::Vector2f v2);	//Returns the angle between two points, used for pathBody generation.
int lengthBetween(sf::Vector2f v1, sf::Vector2f v2);//Returns the length between two points.
int lengthBetweenNodes(int n1, int n2);				//Returns the length between two nodes.
sf::Vector2f normalizeVector(sf::Vector2f);			//Nomalized a vector, so that the biggest value any cordiante is 1.
bool emptySpace(sf::Vector2f postion, int rad);		//Checks if any other nodes exist within a RADius of a POSTION.



#endif											//end of defined file __HelpFunctions.