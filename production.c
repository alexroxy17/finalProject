/*
 * production.c
 *
 *  Created on: Dec 3, 2018
 *      Author: student
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "finalProject.h"

#include <string.h>
Property properties[40];
Player players[3];
int railroadRent[4];


//--------------------GLOBAL VARIABLES--------------------//


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


	players[0].name = "Nate";
	players[1].name = "Rosana";
	players[2].name = "Shauna";

	for(int i=0;i<3;i++)
	{
		players[i].cash=1500;
		players[i].piece = 0;
		players[i].position = 0;
		players[i].ownedRailroads = 0;
		players[i].ownedUtilities = 0;
	}


int   propertyGroups[40]  = {99,0,99,0,99,8,1,99,1,1,99,2,9,2,2,8,3,99,3,3,99,4,99,4,4,8,5,5,9,5,99,6,6,99,6,8,99,7,99,7};
char* propertyNames[40]   = {"GO","Mediterranean Ave.","Chance","Baltic Ave.","Income Tax","Reading Railroad","Oriental Ave.","Chance","Vermont Ave.","Connecticut Ave.","Jail","St. Charles Place","Electric Company","States Ave.","Virginia Ave.","Pennsylvania Railroad","St. James Place","Chance","Tennesee Place","New York Ave.","Free Parking","Kentucky Ave.","Chance","Indiana Ave.","Illinois Ave.","B. & O. Railroad","Atlantic Ave","Ventnor Ave.","Water Works","Marvin Gardens","Go To Jail","Pacific Ave.","North Carolina Ave.","Chance","Pennsylvania Ave.","Short Line","Chance","Park Place","Luxury Tax","Boardwalk"};
int   propertyPrices[40]  = {-200,60,0,60,200,200,100,0,100,120,0,140,150,140,160,200,180,0,180,200,0,220,0,220,240,200,260,260,150,280,0,300,300,0,320,200,0,350,75,400};
int   pricePerHouse[40]   = {-1,50,-1,50,-1,-1,50,-1,50,50,-1,100,-1,100,100,-1,100,-1,100,100,-1,150,-1,150,150,-1,150,150,-1,150,-1,200,200,-1,200,-1,-1,200,-1,200};
int   rent[40]		      =   {-1,2,-1,4,-1,-1,6,-1,6,8,-1,10,-1,10,12,-1,14,-1,14,16,-1,18,-1,18,20,-1,22,22,-1,24,-1,26,26,-1,28,-1,-1,35,-1,50};
int   oneHouseRent[40]    =   {-1,10,-1,20,-1,-1,30,-1,30,40,-1,50,-1,50,60,-1,70,-1,70,80,-1,90,-1,90,100,-1,110,110,-1,120,-1,130,130,-1,150,-1,-1,175,-1,200};
int   twoHouseRent[40]    =   {-1,30,-1,60,-1,-1,90,-1,90,100,-1,150,-1,150,180,-1,200,-1,200,220,-1,250,-1,250,300,-1,330,330,-1,360,-1,390,390,-1,450,-1,-1,500,-1,600};
int   threeHouseRent[40]  =   {-1,90,-1,180,-1,-1,270,-1,270,300,-1,450,-1,450,500,-1,550,-1,550,600,-1,700,-1,700,750,-1,800,800,-1,850,-1,900,900,-1,1000,-1,-1,1100,-1,1400};
int   fourHouseRent[40]   =   {-1,160,-1,320,-1,-1,400,-1,400,450,-1,625,-1,625,700,-1,750,-1,750,800,-1,875,-1,875,925,-1,975,975,-1,1025,-1,1100,1100,-1,1200,-1,-1,1300,-1,1700};
int   hotelRent[40]       =   {-1,250,-1,450,-1,-1,550,-1,550,600,-1,750,-1,750,900,-1,950,-1,950,1000,-1,1050,-1,1050,1100,-1,1150,1150,-1,1200,-1,1275,1275,-1,1400,-1,-1,1500,-1,2000};



for(int i=0;i<40;i++) //Initialize every property
{
	properties[i].group      = propertyGroups[i];
	properties[i].name       = propertyNames[i];
	properties[i].price      = propertyPrices[i];
	properties[i].isBought   = 0;
	properties[i].owner      = PBANK;
	properties[i].houseCount = 0;
	properties[i].hotelCount = 0;
	properties[i].houseCost  = pricePerHouse[i];
	properties[i].baseRentPrice       = rent[i];
	properties[i].oneHouseRentPrice   = oneHouseRent[i];
	properties[i].twoHouseRentPrice   = twoHouseRent[i];
	properties[i].threeHouseRentPrice = threeHouseRent[i];
	properties[i].fourHouseRentPrice  = fourHouseRent[i];
	properties[i].hotelRentPrice      = hotelRent[i];
}

railroadRent[0] = 25;
railroadRent[1] = 50;
railroadRent[2] = 100;
railroadRent[3] = 200;


//players[0].position=BOARDWALK;



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


//Getting everyone's pieces
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

//printf("\nPlayer 1 is %s\nPlayer 2 is %s\nPlayer 3 is %s", players[0].name, players[1].name, players[2].name);
printf("\nPlayer 1 is %s\nPlayer 2 is %s\nPlayer 3 is %s", getPiece(players[0].piece), getPiece(players[1].piece), getPiece(players[2].piece));


puts("\nPlayer 1 goes first!");
for (int i=0;i<numCircuits;i++) //Main game loop!
{
	int roll = getRoll(); //Roll
	int isRollDouble = 0;
	if(isDouble(roll)) //Detect double
	{
		roll = roll-100;
		isRollDouble = 1;
	}

	printf("\nPlayer 1 rolls a %d.", roll);
	if(isRollDouble)
	{
		printf(" Doubles!\n");
	}

	players[0].position += roll;

	printCurrentPos(0);

}

}



