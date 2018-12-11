/*
 * finalProject.h
 *
 *  Created on: Dec 3, 2018
 *      Author: student
 */

#ifndef FINALPROJECT_H_
#define FINALPROJECT_H_

#include <stdbool.h>
#include <math.h>




//Development Testing
void fileTest(void);

#define CRITFAIL 523069

//Group constants:
#define GBROWN    0
#define GTEAL     1
#define GPINK     2
#define GORANGE   3
#define GRED      4
#define GYELLOW   5
#define GGREEN    6
#define GBLUE     7
#define GRAILROAD 8
#define GUTILITY  9
#define GSPECIAL 99 //For Go, Chance, Jail, Gotojail

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
#define PBANK -1
#define PLAYER1 0
#define PLAYER2 1
#define PLAYER3 2

typedef struct property {
	int   group;    //Refer to constants for which group
	char* name;
	int   price;    //Price as an int
	int   isBought; //0 for not bought, 1 for bought
	int   owner;    //player number
	int   houseCount;
	int   hotelCount;
	int   houseCost;
	int   baseRentPrice;
	int   oneHouseRentPrice;
	int   twoHouseRentPrice;
	int   threeHouseRentPrice;
	int   fourHouseRentPrice;
	int   hotelRentPrice;
	int   location;
} Property;

typedef struct player {
	char     *name;
	int      piece; //Refer to constants for pieces
	int      position; //Position on board
	int      cash; //Starts at 1500
	int      ownedRailroads;
	int      ownedUtilities;
	int      ownedProperties;
	Property propertyList[40];
	int		 circuits;
} Player;

typedef struct chancecard {
	char *name;
	int  chanceCashID;
	int  relativeSpacing;
	int  absoluteSpacing;
} ChanceCard;

/*
typedef struct teststruct {
	int one;
	int two;
} TestStruct;                   //Used during development to test stuff out, but I'm too afraid to delete it right now

struct my_record {
	char name;
	int value;
};
*/




#define GO 0
#define MEDIAVE 1
#define CHANCE1 2
#define BALTAVE 3
#define INCOMETAX 4
#define READRR 5
#define ORIEAVE 6
#define CHANCE2 7
#define VERMAVE 8
#define CONNAVE 9
#define JAIL 10
#define STCHPLA 11
#define ELECTRIC 12
#define STATAVE 13
#define VIRGAVE 14
#define PENNRR 15
#define STJAPLA 16
#define CHANCE3 17
#define TENNAVE 18
#define NEWYAVE 19
#define FREEPARKING 20
#define KENTAVE 21
#define CHANCE4 22
#define INDIAVE 23
#define ILLIAVE 24
#define BNORR 25
#define ATLAAVE 26
#define VENTAVE 27
#define WATERWORKS 28
#define MARVINGARDENS 29
#define GOTOJAIL 30
#define PACIAVE 31
#define NORTAVE 32
#define CHANCE5 33
#define PENNAVE 34
#define SHORTLINE 35
#define CHANCE6 36
#define PARKPLA 37
#define LUXURYTAX 38
#define BOARDWALK 39

#define CHANCECARDS 25;

//Main function
void monopoly(int numCircuits);

//Helpers
int  detectPieceFromInput(char* playerStringPiece);    //Detects a piece from input.
const char* getPiece(int playerPieceInteger); //Returns piece as a string, with an uppercase first character.
const char* getGroup(int propertyGroupInteger); //Returns property group as a string, with an uppercase first character.
const char* getOwner(int ownerInteger);
int getRoll(void); //Roll 2d6
int isDouble(int roll);//Determine if a roll is a double or not. Returns 1 if true, 0 if false.
void printCurrentPos(int playerNumber);
int isYes(char input[20]);
void doSpecialActions(int playerNumber, int roll);
void doChance(int playerNumber, int roll);
void doGo(int playerNumber);
void doIncomeTax(int playerNumber);
void doLuxuryTax(int playerNumber);
void doJail(int playerNumber);
void doGoToJail(int playerNumber);
void doNormalActions(int playerNumber, int diceRoll);
void doBuyHouses(int playerNumber);
int getLeastCircuits(void);
int doTurn(int playerNumber);

int countHouses(int playerNumber);
int countHotels(int playerNumber);

extern int railroadRentLookup[4];
extern Player players[3];
extern Property properties[40];
extern int currentCircuit;
extern ChanceCard chanceCards[25];


#endif /* FINALPROJECT_H_ */
