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
BackgroundMenu BKM;
BackgroundGame BKG;


void configureUI()
{
	int wX = window.getSize().x;	
	int wY = window.getSize().y;


	//Main menu GUI items
	if(!MMS.logoTexture.loadFromFile("../Sprites/logo.png")) 
			cout << "\nFailed loading Sprites/Logo.png";	//Load texture.
	MMS.logo.setTexture(MMS.logoTexture, true);																//set texture to the sprite.
	MMS.logoTexture.setSmooth(true);																		//enable texture sommthing.
	MMS.logo.setScale(0.5, 0.5);																			//scale the texture to good size.
	MMS.logo.setPosition(wX /2, MMS.logoTexture.getSize().y/3.5);							//Sprite to the right place on screen.
	MMS.logo.setOrigin(MMS.logoTexture.getSize().x/2, MMS.logoTexture.getSize().y/2);						//Set origin point, so its not being moved from top-right.
	




	//Menu background images
	if(!BKM.bkSmokeTexture.loadFromFile("../Sprites/Backgrounds/back_Smoke.png"))
			cout << "\nFailed loading Sprites/Backgrounds/back_Smoke.png";	//Load texture.
	BKM.bkSmokeBottomSprite.setTexture(BKM.bkSmokeTexture, true);																//set texture to the sprite.
	BKM.bkSmokeTexture.setSmooth(true);
	BKM.bkSmokeBottomSprite.setColor(Color(220,220,255,75));																		//enable texture sommthing.
	BKM.bkSmokeBottomSprite.setScale(wX/float(BKM.bkSmokeTexture.getSize().x)*sqrt(2) *1.8, wX/float(BKM.bkSmokeTexture.getSize().x)*sqrt(2)*1.8);																			//scale the texture to good size.
	BKM.bkSmokeBottomSprite.setPosition(wX, wY/2);							//Sprite to the right place on screen.
	BKM.bkSmokeBottomSprite.setOrigin(BKM.bkSmokeTexture.getSize().x/2, BKM.bkSmokeTexture.getSize().y/2);						//Set origin point, so its not being moved from top-right.
	BKM.bkSmokeBottomRotation = 0.016;


	BKM.bkSmokeTopSprite.setTexture(BKM.bkSmokeTexture, true);																//set texture to the sprite.
	BKM.bkSmokeTexture.setSmooth(true);
	BKM.bkSmokeTopSprite.setColor(Color(220,220,255,75));																		//enable texture sommthing.
	BKM.bkSmokeTopSprite.setScale(wX/float(BKM.bkSmokeTexture.getSize().x)*sqrt(2) *1.8, wX/float(BKM.bkSmokeTexture.getSize().x)*sqrt(2)*1.8);																			//scale the texture to good size.
	BKM.bkSmokeTopSprite.setPosition(0, wY/2);							//Sprite to the right place on screen.
	BKM.bkSmokeTopSprite.setOrigin(BKM.bkSmokeTexture.getSize().x/2, BKM.bkSmokeTexture.getSize().y/2);						//Set origin point, so its not being moved from top-right.
	BKM.bkSmokeTopSprite.rotate(140); //start one of them offset.
	BKM.bkSmokeTopRotation = -0.012;






	//Game background images
	if(!BKG.bkBottomTexture.loadFromFile("../Sprites/Backgrounds/back_Bottom.png")) 
			cout << "\nFailed loading Sprites/Backgrounds/back_Bottom.png";	//Load texture.
	BKG.bkBottomSprite.setTexture(BKG.bkBottomTexture, true);																//set texture to the sprite.
	BKG.bkBottomTexture.setSmooth(true);																		//enable texture sommthing.
	BKG.bkBottomSprite.setScale(wX/float(BKG.bkBottomTexture.getSize().x)*sqrt(2), wX/float(BKG.bkBottomTexture.getSize().x)*sqrt(2));																			//scale the texture to good size.
	BKG.bkBottomSprite.setPosition(wX /2, wY/2);							//Sprite to the right place on screen.
	BKG.bkBottomSprite.setOrigin(BKG.bkBottomTexture.getSize().x/2, BKG.bkBottomTexture.getSize().y/2);						//Set origin point, so its not being moved from top-right.
	BKG.bkBottomRotation = 0.017;

	if(!BKG.bkMiddleTexture.loadFromFile("../Sprites/Backgrounds/back_BlueGreen.png")) 
			cout << "\nFailed loading Sprites/Backgrounds/back_BlueGreen.png";	//Load texture.
	BKG.bkMiddleSprite.setTexture(BKG.bkMiddleTexture, true);																//set texture to the sprite.
	BKG.bkMiddleTexture.setSmooth(true);
	BKG.bkMiddleSprite.setColor(Color(255,255,255,120));																		//enable texture sommthing.
	BKG.bkMiddleSprite.setScale(wX/float(BKG.bkMiddleTexture.getSize().x)*sqrt(2), wX/float(BKG.bkMiddleTexture.getSize().x)*sqrt(2));																			//scale the texture to good size.
	BKG.bkMiddleSprite.setPosition(wX /2, wY/2);							//Sprite to the right place on screen.
	BKG.bkMiddleSprite.setOrigin(BKG.bkMiddleTexture.getSize().x/2, BKG.bkMiddleTexture.getSize().y/2);						//Set origin point, so its not being moved from top-right.
	BKG.bkMiddleRotation = -0.02;


	if(!BKG.bkTopTexture.loadFromFile("../Sprites/Backgrounds/back_OrangeBlue.png")) 
			cout << "\nFailed loading Sprites/Backgrounds/back_OrageBlue.png";	//Load texture.
	BKG.bkTopSprite.setTexture(BKG.bkTopTexture, true);																//set texture to the sprite.
	BKG.bkTopTexture.setSmooth(true);
	BKG.bkTopSprite.setColor(Color(255,255,255,80));																		//enable texture sommthing.
	BKG.bkTopSprite.setScale(wX/float(BKG.bkTopTexture.getSize().x)*sqrt(2), wX/float(BKG.bkTopTexture.getSize().x)*sqrt(2));																			//scale the texture to good size.
	BKG.bkTopSprite.setPosition(wX /2, wY/2);							//Sprite to the right place on screen.
	BKG.bkTopSprite.setOrigin(BKG.bkTopTexture.getSize().x/2, BKG.bkTopTexture.getSize().y/2);						//Set origin point, so its not being moved from top-right.
	BKG.bkTopRotation = 0.03;
	

}