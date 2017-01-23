#if !defined(__Constants_h)
#define __Constants_h
#include <SFML/Graphics.hpp>			//for Graphics stuff


const int windowWidth = 800;
const int windowHeight = 1200;
const int MAXNODES = 15;		//maximum amount of nodes that can exist.
const int MAXPATHS = 50;		//maximum amount of paths.
const int MAXPATHSPERNODE = 10;

const float pathThicknessMultiplier = 1;
const int nodeGenMargin = 100;				//The distance from the window border which nodes can spawn.
const int nodeRadius = 40;
const int nodeToNodeMargin = 140;			//The distance a node can spawn from another node. Spacing.							
 

//RNG values:
const long rngM = 4294967296;
const int rngA = 219013;
const int rngC = 2531011;


#endif