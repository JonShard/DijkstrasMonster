#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>			//for Graphics stuff
#include "HelpFunctions.h"

using namespace sf;
using namespace std;


Clock clockOne;								//elapsed time in ms.
int totalSeed = 2415;

void testHelp()
{
	cout << "\nThe thickness is " << pathThicknessMultiplier << "f\n";
}


long randomNumber(int min, int max, int seed)		//Random int in a range.
{
	long result = 0;
	int attempt = 0;

	do{
		cout << "\n\nGenerating random number from:\nSeed: " << seed;
		cout << "\nTotal Seed: " << totalSeed;
		cout << "\nAttempt: " << ++attempt;
		totalSeed += seed;
		result =  (rngA * totalSeed + rngC) % rngM;
		result =  (min + abs(result)) % (max + 1);
		cout << "\nCHECKING:\t" << result;

	}while(result <= min || result > max);

	cout << "\nRANDOM NUMBER:\t==========> " << result;

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