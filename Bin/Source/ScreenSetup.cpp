#include "ScreenSetup.h"
#include <iostream>																//For printing debug info to terminal.
#include <cmath>																//sqrt(), pow(), abs(), atan2().
#include <SFML/Graphics.hpp>													//For Graphics stuff
#include "HelpFunctions.h"

using namespace std; 															//The standard liberary namespace.
using namespace sf;																//The SFML liberary namespace.


extern RenderWindow window;

MainMenuScreen MMS;
OptionsScreen OPS;
GameScreen GMS;


void updateScreens()
{
	int wX = window.getSize().x;	
	int wY = window.getSize().y;


	if(!MMS.logoTexture.loadFromFile("../Sprites/logo.png")) 
			cout << "\nFailed loading Sprites/Logo.png";	//Load texture.
	MMS.logo.setTexture(MMS.logoTexture, true);																//set texture to the sprite.
	MMS.logoTexture.setSmooth(true);																		//enable texture sommthing.
	MMS.logo.setScale(0.5, 0.5);																			//scale the texture to good size.
	MMS.logo.setPosition(wX /2, MMS.logoTexture.getSize().y/3.5);							//Sprite to the right place on screen.
	MMS.logo.setOrigin(MMS.logoTexture.getSize().x/2, MMS.logoTexture.getSize().y/2);						//Set origin point, so its not being moved from top-right.
	

	if(!MMS.bkBottomTexture.loadFromFile("../Sprites/Backgrounds/back_Bottom.png")) 
			cout << "\nFailed loading Sprites/Backgrounds/back_Bottom.png";	//Load texture.
	MMS.bkBottomSprite.setTexture(MMS.bkBottomTexture, true);																//set texture to the sprite.
	MMS.bkBottomTexture.setSmooth(true);																		//enable texture sommthing.
	MMS.bkBottomSprite.setScale(wX/float(MMS.bkBottomTexture.getSize().x)*sqrt(2), wX/float(MMS.bkBottomTexture.getSize().x)*sqrt(2));																			//scale the texture to good size.
	MMS.bkBottomSprite.setPosition(wX /2, wY/2);							//Sprite to the right place on screen.
	MMS.bkBottomSprite.setOrigin(MMS.bkBottomTexture.getSize().x/2, MMS.bkBottomTexture.getSize().y/2);						//Set origin point, so its not being moved from top-right.
	MMS.bkBottomRotation = 0.014;


	if(!MMS.bkMiddleTexture.loadFromFile("../Sprites/Backgrounds/back_BlueGreen.png")) 
			cout << "\nFailed loading Sprites/Backgrounds/back_BlueGreen.png";	//Load texture.
	MMS.bkMiddleSprite.setTexture(MMS.bkMiddleTexture, true);																//set texture to the sprite.
	MMS.bkMiddleTexture.setSmooth(true);
	MMS.bkMiddleSprite.setColor(Color(255,255,255,120));																		//enable texture sommthing.
	MMS.bkMiddleSprite.setScale(wX/float(MMS.bkMiddleTexture.getSize().x)*sqrt(2), wX/float(MMS.bkMiddleTexture.getSize().x)*sqrt(2));																			//scale the texture to good size.
	MMS.bkMiddleSprite.setPosition(wX /2, wY/2);							//Sprite to the right place on screen.
	MMS.bkMiddleSprite.setOrigin(MMS.bkMiddleTexture.getSize().x/2, MMS.bkMiddleTexture.getSize().y/2);						//Set origin point, so its not being moved from top-right.
	MMS.bkMiddleRotation = -0.02;


	if(!MMS.bkTopTexture.loadFromFile("../Sprites/Backgrounds/back_OrangeBlue.png")) 
			cout << "\nFailed loading Sprites/Backgrounds/back_OrageBlue.png";	//Load texture.
	MMS.bkTopSprite.setTexture(MMS.bkTopTexture, true);																//set texture to the sprite.
	MMS.bkTopTexture.setSmooth(true);
	MMS.bkTopSprite.setColor(Color(255,255,255,80));																		//enable texture sommthing.
	MMS.bkTopSprite.setScale(wX/float(MMS.bkTopTexture.getSize().x)*sqrt(2), wX/float(MMS.bkTopTexture.getSize().x)*sqrt(2));																			//scale the texture to good size.
	MMS.bkTopSprite.setPosition(wX /2, wY/2);							//Sprite to the right place on screen.
	MMS.bkTopSprite.setOrigin(MMS.bkTopTexture.getSize().x/2, MMS.bkTopTexture.getSize().y/2);						//Set origin point, so its not being moved from top-right.
	MMS.bkTopRotation = 0.03;
	




	
	GMS.nodeBoard.setSize(Vector2f(windowHeight - 2*nodeGenMargin, windowWidth - 2*nodeGenMargin));
	GMS.nodeBoard.setPosition(Vector2f(nodeGenMargin, nodeGenMargin));
	GMS.nodeBoard.setFillColor(Color(35,35,35));

}