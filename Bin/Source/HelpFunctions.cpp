#include <iostream>																//For printing debug info to terminal.
#include <cmath>																//sqrt(), pow(), abs(), atan2().
#include <SFML/Graphics.hpp>													//For Graphics stuff
#include "HelpFunctions.h"

using namespace std; 															//The standard liberary namespace.
using namespace sf;																//The SFML liberary namespace.


extern Node nodes[];															//Array of nodes on the board.
extern Path paths[];															//Array of paths between the nodes.
extern int lastNode;															//Last used node. Useful for loops.
extern int lastPath;															//Same thing for the paths.


Clock clockOne;																	//Elapsed time in ms.
int totalSeed = 241745;


void generate(int nodeCount, int pathCount, int allowedPaths)			//Handles the actuall generation,
{																		//calls the object to have them generate
	for(int i = 0; i < nodeCount; i++)									//the right values.
	{
		nodes[lastNode].setAll();
		lastNode++;
	}
	 
	cout << "\n\n\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" 
		 << "\nNumber of nodes are: " << nodeCount << "\t Number of paths are: " 
		 << pathCount << "\t  Max allowed nodes: " << allowedPaths
		 << "\nFinished generating nodes."
		 << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";

	for(int j = 0; j < pathCount; j++)
	{
		paths[lastPath].setAll();
		lastPath++;
	}
}


bool noDoublePaths()
{
	cout << "\nStaring to check if this node already exist in the network.";	//Used to check if a path already exist in the network.
	for(int i = 0; i < lastPath; i ++)
	{
		int nd1 = paths[lastPath].getNodes().x;									//Sorts the paths node indexes into biggest and smallest
		int nd2 = paths[lastPath].getNodes().y;									//then compairs them to see if thy both are equal.

		int locPathBig = 0;														//Biggest node in local path. As in value of index.
		int locPathSml = 0; 													//Smallest node in local path.
		int rmtPathBig = 0; 													//Biggest node in remote Path.
		int rmtPathSml = 0;														//Smallest node in remote Path.

		//sorting the biggest node value into the correct int for comparison.
		if (nd1 > nd2){	locPathBig = nd1;	locPathSml = nd2;	}
		else 		{	locPathBig = nd2;	locPathSml = nd1;	}
		
		if (paths[i].getNodes().x > paths[i].getNodes().y)
			{rmtPathBig = paths[i].getNodes().x;	rmtPathSml = paths[i].getNodes().y;	}
		else
			{rmtPathBig = paths[i].getNodes().y;	rmtPathSml = paths[i].getNodes().x;	}


		if (locPathBig == rmtPathBig && locPathSml == rmtPathSml)				//Checks If the indexes are equal.
			{	cout << "\n This node exist already, retrying...\n";
				return false;													//False if they are equal.
			}
	}
	cout << "\nThis path does not exist yet.\n";
	return true;																//True if they are different.
}



long randomNumber(int min, int max)												//Random int in a range.
{
	long result = 0;
	int attempt = 0;
	do{
		int seed = ranMillisec();

		cout << "\nGenerating random number("<< min<<", "<<max<<") from:\t Seed: " << seed;
		cout << "\tTotal Seed: " << totalSeed;
		cout << "\tAttempt: " << ++attempt;
		totalSeed += seed;
		result =  (rngA * totalSeed + rngC) % rngM;
		result =  (min + abs(result)) % (max + 1);
		cout << "\tCHECKING: " << result;

	}while(result <= min || result > max);

	cout << "\tRANDOM NUMBER:\t==========> " << result;

	return result;

}


int rantime()																	//Returns the amount of seconds the app has ran.  
{
	Clock upTime;
	Time ElapsedTime = upTime.getElapsedTime();
	return int(upTime.getElapsedTime().asSeconds());
}


int ranMillisec()																//Returns the current milliSecond.
{
	Time bobby = clockOne.getElapsedTime();

	int millisec = bobby.asMilliseconds();
	int sec = millisec / 1000;

	return millisec - (sec * 1000);

}


Vector2f nodePos(int index)														//Returns the postion of a node in nodes[]
{	return nodes[index].getPos();	}


float getAngle(Vector2f v1, Vector2f v2)										//Retuns the angle between two points.
{
   	float angle = 0;
	
   	float deltaX = v1.x - v2.x;
   	float deltaY = v2.y - v1.y;		//revesed Y

   	angle = atan2(deltaX, deltaY);
   	angle = (angle * 180) / PI;

    return ((angle < 0) ? (360 + angle +90) : angle + 90);
}


int lengthBetween(Vector2f v1, Vector2f v2)										//Will return the distance between to points(x,y)
{
	return sqrt( pow(v1.x - v2.x,  2)
			   + pow(v1.y - v2.y,  2));	
}


int lengthBetweenNodes(int n1, int n2)											//Will return the distance between two nodes.
{
	cout << "\nThe distance is: " << lengthBetween(nodes[n1].getPos(), nodes[n2].getPos());

	cout << "\n Positions are: " << nodes[n1].getPos().x << "::" << nodes[n1].getPos().y 
					   << "\t\t" << nodes[n2].getPos().x << "::" << nodes[n2].getPos().y;
	return lengthBetween(nodes[n1].getPos(), nodes[n2].getPos());
}


Vector2f normalizeVector(Vector2f v)
{
	Vector2f n;
	float magnitude = sqrt(pow(v.x, 2) + pow(v.y, 2));
	n.x = v.x/magnitude;
	n.y = v.y/magnitude;
	return n;
}


bool emptySpace(Vector2f location, int rad)		//returns false if the point 1 and point 2 is less than rad from eachother.
{

	for (int n = 0; n < lastNode; n++)
	{
		if (lengthBetween(location, nodes[n].getPos()) < rad)
		{
			return false;
		}
	}

	return true;
}


