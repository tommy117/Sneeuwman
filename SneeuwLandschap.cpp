/*
 * SneeuwLandschap.cpp
 *
 *  Created on: 8 feb. 2012
 *      Author: acer
 */

#include "SneeuwLandschap.hpp"


//globale variabelen voor breedte en hoogte van het scherm
int screenWidth;
int screenHeight;


//constructor
SneeuwLandschap::SneeuwLandschap()
{
	//sla schermgrootte op in globale variabelen
	MAExtent screenSize = maGetScrSize();
	screenWidth = EXTENT_X( screenSize );
	screenHeight = EXTENT_Y( screenSize );

	//stel sneeuwhoogte in
	this->sneeuwHoogte = 30;

	//stel in waar de grond is
	this->grond = screenHeight - this->sneeuwHoogte;

	//maak een nieuwe sneeuwman
	this->sneeuwMan = new SneeuwMan( screenWidth / 2, screenHeight - this->sneeuwHoogte );
}


//wordt aangeroepen als er input is (druk op de toets, touch van scherm)
void SneeuwLandschap::run( MAEvent event )
{
	//als er een key is ingetoetst
	if( event.type == EVENT_TYPE_KEY_PRESSED )
	{
		//pak de key code
		int key = maGetKeys();

		//kijk voor linkertoets
		if( key == MAKB_LEFT )
			this->sneeuwMan->move( -6 );	//beweeg sneeuwman -6 pixels

		//kijk voor rechtertoets
		if( key == MAKB_RIGHT )
			this->sneeuwMan->move( 6 );		//beweeg sneeuwman 6 pixels
	}

	//wacht 40 milliseconden
	maWait(40);

	//bepaal een random xpositie
	int xpos = rand()  % (screenWidth);

	//maak een sneeuwvlok aan op de random-0 coordinaten
	SneeuwVlok* sneeuwvlok= new SneeuwVlok(xpos, 0);

	//voeg het sneeuwvlokje toe aan de vector array
	sneeuwVlokArray.add(sneeuwvlok);

	//doorloop de sneeuwvlokjes vector array
	for(int i = 0; i < sneeuwVlokArray.size(); i++) {
		//laat het sneeuwvlokje vallen
		sneeuwVlokArray[i]->fall(this->grond);

		//als hij dood is
		if(sneeuwVlokArray[i]->isDead()) {
			//maak een tijdelijke pointer aan
			SneeuwVlok* temp = sneeuwVlokArray[i];

			//verder de pointer in de array
			sneeuwVlokArray.remove(i);

			//verwijder het sneeuwvlokje van het geheugen
			delete temp;
		}
	}
}


//wordt elke "tick" aangeroepen om het winterlandschap, sneeuwman en sneeuwvlokken te tekenen
void SneeuwLandschap::draw()
{
	//kleur de lucht blauw
	maSetColor( 0x0055ff );
	maFillRect( 0, 0, screenWidth, screenHeight );

	//maak sneeuw op de grond, a.d.h.v. sneeuwHoogte
	maSetColor( 0xffffff );
	maFillRect( 0, screenHeight - this->sneeuwHoogte, screenWidth, this->sneeuwHoogte );

	//teken de sneeuwman
	this->sneeuwMan->draw();

	//teken de sneeuwvlokjes
	for(int i = 0; i < sneeuwVlokArray.size(); i++) {
		sneeuwVlokArray[i]->draw();
	}
}


