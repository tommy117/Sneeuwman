/*
 * SneeuwVlok.cpp
 *
 *  Created on: 7 mrt. 2012
 *      Author: Tom
 */

#include "SneeuwVlok.hpp"

//constructor
SneeuwVlok::SneeuwVlok(int positionX, int positionY) {
	//initiele x en y positie setten.
	this->positionX = positionX;
	this->positionY = positionY;

	//sneeuwvlokje is niet dod
	this->dead = false;

	//min max grootte van de sneeuwvlok
	int minsize = 1;
	int maxsize = 6;

	//grootte = random getal tussen 1-6
	this->size = rand() % (maxsize-minsize) + minsize;
}

void SneeuwVlok::draw() {
	//kies kleur
	maSetColor( 0xffffff );
	maFillRect( this->positionX, this->positionY, this->size, this->size );
}

void SneeuwVlok::fall( int groundLevel) {
	//twee pixels bij de y positie om het sneeuwvlokje naar beneden te verplaatsen
	this->positionY = this->positionY + 2;

	//als het vlokje op de grond is gevallen bestempelen we deze als dood
	if(this->positionY > groundLevel) {
		this->dead = true;
	}
}

bool SneeuwVlok::isDead() {
	//zeg of het sneeuwvlokje dood of levend is
	return this->dead;
}




