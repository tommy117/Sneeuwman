/*
 * SneeuwMan.cpp
 *
 *  Created on: 7 mrt. 2012
 *      Author: Tom
 */

#include "SneeuwMan.hpp"


//constructor, initiele x en y positie setten.
SneeuwMan::SneeuwMan(int positionX, int positionY) {
	this->positionX = positionX;
	this->positionY = positionY;
}


//Beweeg function van de sneeuwman. X positie + wijziging van de xpositie is de nieuw positie
void SneeuwMan::move(int direction) {
	this->positionX = this->positionX+direction;
}


void SneeuwMan::draw (){

//kleur de sneeuwman wit

maSetColor( 0xffffff );

maFillRect( (this->positionX + 12), positionY - 125, 50, 50 );

maFillRect( (this->positionX), positionY - 75, 75, 75 );


// gezicht, armen en knopen zwart

maSetColor( 0x000000 );

maFillRect( (this->positionX + 23), positionY - 110, 4, 4 );

maFillRect( (this->positionX + 46), positionY - 110, 4, 4 );

maFillRect( (this->positionX + 20), positionY - 90, 35, 2 );

maFillRect( (this->positionX - 35), positionY - 75, 35, 6 );

maFillRect( (this->positionX + 75), positionY - 75, 35, 6 );

maFillRect( (this->positionX + 35), positionY - 60, 4, 4 );

maFillRect( (this->positionX + 35), positionY - 40, 4, 4 );

maFillRect( (this->positionX + 35), positionY - 20, 4, 4 );



maUpdateScreen();
}





