/*
 * finalProject.h
 *
 *  Created on: Dec 3, 2018
 *      Author: student
 */

#ifndef FINALPROJECT_H_
#define FINALPROJECT_H_

#include <stdbool.h>

//Main function
void monopoly(int numCircuits);
int  detectPiece(char* playerStringPiece);


//Group constants:
#define GBROWN  0
#define GTEAL   1
#define GPINK   2
#define GORANGE 3
#define GRED    4
#define GYELLOW 5
#define GGREEN  6
#define GBLUE   7

//Piece constants;
#define PDOG 0 //Dog
#define PCAR 1 //Car
#define PBAT 2 //Battleship
#define PHAT 3 //Hat
#define PTHI 4 //Thimble
#define PSHO 5 //Shoe
#define PIRO 6 //Iron
#define PWHE 7 //Wheel

#define NUMPLAYERS 3

typedef struct property {
	int group;    //Refer to constants for which group
	int price;    //Price as an int
	int isBought; //0 for not bought, 1 for bought
	int owner;    //player number
	int houseCount;
	int hotelCount;
} Property;

typedef struct player {
	char *name;
	int  piece; //Refer to constants for pieces
	int  position; //Position on board
	int  cash; //Starts at 1500
} Player;


#endif /* FINALPROJECT_H_ */
