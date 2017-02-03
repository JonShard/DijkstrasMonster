#if !defined(__Constants_h)
#define __Constants_h
#include <SFML/Graphics.hpp>				//For Graphics stuff


const int windowWidth = 800;
const int windowHeight = 1200;
const int MINNODES = 4;
const int MAXNODES = 9;						//Maximum amount of nodes that can exist.
const int MAXPATHS = 50;					//Maximum amount of paths.
const int MAXPATHSPERNODE = 20;
const int MAXWEIGHT = 10;					//Can not be greater than 10, cuz then the color will then be over 255.

const float pathThickness = 5;
const int WEIGHTTEXTSIZE = 30;
const int nodeGenMargin = 100;				//The distance from the window border which nodes can spawn.
const int nodeRadius = 40;
const int nodeToNodeMargin = 140;			//The distance a node can spawn from another node. Spacing.							
 

const float PI = 3.1415926535897F;

//RNG values:
const long rngM = 4294967296;
const int rngA = 219013;
const int rngC = 2531011;


#endif