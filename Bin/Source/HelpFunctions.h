#if !defined(__HelpFunctions_h)
#define __HelpFunctions_h
#include <SFML/Graphics.hpp>			//for Graphics stuff
#include "Node.h"
#include "Path.h"
#include "Constants.h"


bool noDoublePaths();


long randomNumber(int min, int max);
int rantime();
int ranMillisec();
sf::Vector2f nodePos(int index);
float getAngle(sf::Vector2f v1, sf::Vector2f v2);
int lengthBetween(sf::Vector2f v1, sf::Vector2f v2);
int lengthBetweenNodes(int n1, int n2);
sf::Vector2f normalizeVector(sf::Vector2f);
bool emptySpace(sf::Vector2f postion, int rad);
void printAllData();


#endif