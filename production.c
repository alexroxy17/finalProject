/*
 * production.c
 *
 *  Created on: Dec 3, 2018
 *      Author: student
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "finalProject.h"

#include <string.h>

void monopoly(int numCircuits) {
/*
	#define GBROWN  0
	#define GTEAL   1
	#define GPINK   2
	#define GORANGE 3
	#define GRED    4
	#define GYELLOW 5
	#define GGREEN  6
	#define GBLUE   7

 * typedef struct property {
		int group;    //Refer to constants for which group
		cher* name;
		int price;    //Price as an int
		int isBought; //0 for not bought, 1 for bought
		int owner;    //player number
		int houseCount;
		int hotelCount;
	} Property;
 */
Player players[3] = {{"Nate", 0, 0, 1500}, {"Rosana", 0, 0, 1500}, {"Shauna", 0, 0, 1500}}; //Initializing players

int propertyGroups[40] = {99,0,99,0,99,8,1,99,1,1,99,2,9,2,2,8,3,99,3,3,99,4,99,4,4,8,5,5,9,5,99,6,6,99,6,8,99,7,99,7};
char* propertyNames[40] = {"GO","Mediterranean Ave.","Chance","Baltic Ave.","Income Tax","Reading Railroad","Oriental Ave.","Chance","Vermont Ave.","Connecticut Ave.","Jail","St. Charles Place","Electric Company","States Ave.","Virginia Ave.","Pennsylvania Railroad","St. James Place","Chance","Tennesee Place","New York Ave.","Free Parking","Kentucky Ave.","Chance","Indiana Ave.","Illinois Ave.","B. & O. Railroad","Atlantic Ave","Ventnor Ave.","Water Works","Marvin Gardens","Go To Jail","Pacific Ave.","North Carolina Ave.","Chance","Pennsylvania Ave.","Short Line","Chance","Park Place","Luxury Tax","Boardwalk"};
int propertyPrices[40] = {-200,60,0,60,200,200,100,0,100,120,0,140,150,140,160,200,180,0,180,200,0,220,0,220,240,200,260,260,150,280,0,300,300,0,320,200,0,350,75,400};

Property properties[40];

for(int i=0;i<40;i++)
{
	properties[i].group      = propertyGroups[i];
	properties[i].name       = propertyNames[i];
	properties[i].price      = propertyPrices[i];
	properties[i].isBought   = 0;
	properties[i].owner      = 0;
	properties[i].houseCount = 0;
	properties[i].hotelCount = 0;

}

for(int i=0;i<40;i++)
	printf("Group: %d Name: %s Price: %d\n", properties[i].group, properties[i].name, properties[i].price);
fflush(stdout);

/*
char p1Name[20];
char p2Name[20];
char p3Name[20];

puts("What is Player 1's name?"); //Asking for names
scanf("%19s", p1Name);
//puts("What piece does Player 1 want to use?"); //Asking for names
//scanf("%19s", p1Piece);

puts("What is Player 2's name?");
scanf("%19s", p2Name);
//puts("What piece does Player 2 want to use?"); //Asking for names
//scanf("%19s", p2Piece);

puts("What is Player 3's name?");
scanf("%19s", p3Name);
//puts("What piece does Player 3 want to use?"); //Asking for names
//scanf("%19s", p3Piece);

players[0].name = p1Name; //Setting names in struct
players[1].name = p2Name;
players[2].name = p3Name;



int playerPieces[3] = {0,0,0};

puts("Possible pieces are: Dog, Car, Battleship, Hat, Thimble, Shoe, Iron and Wheelbarrow.");
for(int i=1; i<NUMPLAYERS+1; i++) //Importing pieces
{
	printf("\nWhat piece would player %d like to play as?\n", i);
	char input[20];//Initialize
	for(int j=0;j<20;j++)
	{
		input[j]='\0';
	}
	scanf("%s",input); //Take in input

	int flag = detectPieceFromInput(input);
	if(flag != CRITFAIL)
	{
		playerPieces[i-1] = detectPieceFromInput(input);
	}
	else //iff invalid input
	{
		puts("Critical failure.");
	}
}

players[0].piece = playerPieces[0];
players[1].piece = playerPieces[1];
players[2].piece = playerPieces[2];

printf("\nPlayer 1 is %s\nPlayer 2 is %s\nPlayer 3 is %s", players[0].name, players[1].name, players[2].name);
printf("\nPlayer 1 is %s\nPlayer 2 is %s\nPlayer 3 is %s", getPiece(players[0].piece), getPiece(players[1].piece), getPiece(players[2].piece));
*/
}


