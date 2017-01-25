#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>			//for Graphics stuff
#include "HelpFunctions.h"

using namespace sf;
using namespace std;


extern int lastNode;
extern Node nodes[];


Clock clockOne;								//elapsed time in ms.
int totalSeed = 2415;



long randomNumber(int min, int max)		//Random int in a range.
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


int rantime()							//returns the amount of seconds the app has ran.  
{
	Clock upTime;
	Time ElapsedTime = upTime.getElapsedTime();
	return int(upTime.getElapsedTime().asSeconds());
}


int ranMillisec()
{
	Time bobby = clockOne.getElapsedTime();

	int millisec = bobby.asMilliseconds();
	int sec = millisec / 1000;

	return millisec - (sec * 1000);

}


Vector2f nodePos(int index)
{	return nodes[index].getPos();	}


float getAngle(Vector2f v1, Vector2f v2)
{
   	float angle = 0;
	
   	float deltaX = v1.x - v2.x;
   	float deltaY = v2.y - v1.y;		//revesed Y

   	angle = atan2(deltaX, deltaY);
   	angle = (angle * 180) / PI;

    return ((angle < 0) ? (360 + angle) : angle);
}


int lengthBetween(Vector2f v1, Vector2f v2)		//will return the distance between to points(x,y)
{
	return sqrt( pow(abs(v1.x - v2.x),  2)
			   + pow(abs(v1.y - v2.y),  2));	
}


int lengthBetweenNodes(int n1, int n2)			//will return the distance between two nodes.
{
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