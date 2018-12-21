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
#include <math.h>
#include "finalProject.h"

#include <string.h>
Property properties[40];
Player players[3];
int railroadRentLookup[4];
int currentCircuit;
ChanceCard chanceCards[25];


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

	//----------PLAYER INFO----------//
		//Default starting names
		players[0].name = "Nate";
		players[1].name = "Rosana";
		players[2].name = "Shauna";

		for(int i=0;i<3;i++)
		{
			players[i].cash=1500;
			players[i].piece = 0; //This function is deprecated, no longer used.
			players[i].position = 0;
			players[i].ownedRailroads  = 0;
			players[i].ownedUtilities  = 0;
			players[i].ownedProperties = 0;
			players[i].circuits = 0;
		}

	//----------PROPERTY INFO----------//
	int   propertyGroups[40] = {99,0,99,0,99,8,1,99,1,1,99,2,9,2,2,8,3,99,3,3,99,4,99,4,4,8,5,5,9,5,99,6,6,99,6,8,99,7,99,7};
	char* propertyNames[40]  = {"GO","Mediterranean Avenue","Chance","Baltic Avenue","Income Tax","Reading Railroad","Oriental Avenue","Chance","Vermont Avenue","Connecticut Avenue","Jail","St. Charles Place","Electric Company","States Avenue","Virginia Avenue","Pennsylvania Railroad","St. James Place","Chance","Tennesee Place","New York Avenue","Free Parking","Kentucky Avenue","Chance","Indiana Avenue","Illinois Avenue","B. & O. Railroad","Atlantic Avenue","Ventnor Avenue","Water Works","Marvin Gardens","Go To Jail","Pacific Avenue","North Carolina Avenue","Chance","Pennsylvania Avenue","Short Line","Chance","Park Place","Luxury Tax","Boardwalk"};
	int   propertyPrices[40] = {-200,60,0,60,200,200,100,0,100,120,0,140,150,140,160,200,180,0,180,200,0,220,0,220,240,200,260,260,150,280,0,300,300,0,320,200,0,350,75,400};
	int   pricePerHouse[40]  = {-1,50,-1,50,-1,-1,50,-1,50,50,-1,100,-1,100,100,-1,100,-1,100,100,-1,150,-1,150,150,-1,150,150,-1,150,-1,200,200,-1,200,-1,-1,200,-1,200};
	int   rent[40]		     =   {-1,2,-1,4,-1,-1,6,-1,6,8,-1,10,-1,10,12,-1,14,-1,14,16,-1,18,-1,18,20,-1,22,22,-1,24,-1,26,26,-1,28,-1,-1,35,-1,50};
	int   oneHouseRent[40]   =   {-1,10,-1,20,-1,-1,30,-1,30,40,-1,50,-1,50,60,-1,70,-1,70,80,-1,90,-1,90,100,-1,110,110,-1,120,-1,130,130,-1,150,-1,-1,175,-1,200};
	int   twoHouseRent[40]   =   {-1,30,-1,60,-1,-1,90,-1,90,100,-1,150,-1,150,180,-1,200,-1,200,220,-1,250,-1,250,300,-1,330,330,-1,360,-1,390,390,-1,450,-1,-1,500,-1,600};
	int   threeHouseRent[40] =   {-1,90,-1,180,-1,-1,270,-1,270,300,-1,450,-1,450,500,-1,550,-1,550,600,-1,700,-1,700,750,-1,800,800,-1,850,-1,900,900,-1,1000,-1,-1,1100,-1,1400};
	int   fourHouseRent[40]  =   {-1,160,-1,320,-1,-1,400,-1,400,450,-1,625,-1,625,700,-1,750,-1,750,800,-1,875,-1,875,925,-1,975,975,-1,1025,-1,1100,1100,-1,1200,-1,-1,1300,-1,1700};
	int   hotelRent[40]      =   {-1,250,-1,450,-1,-1,550,-1,550,600,-1,750,-1,750,900,-1,950,-1,950,1000,-1,1050,-1,1050,1100,-1,1150,1150,-1,1200,-1,1275,1275,-1,1400,-1,-1,1500,-1,2000};



	for(int i=0;i<40;i++) //Initialize every property in array
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
		properties[i].location = i;
	}

	railroadRentLookup[0] = 25;
	railroadRentLookup[1] = 50;
	railroadRentLookup[2] = 100;
	railroadRentLookup[3] = 200;

	//----------CHANCE CARDS----------//

	//Names for chance cards:
	char* chanceName[25]      = {"Advance to GO. Collect $200","Advance to Illinois Ave","Advance to St. Charles Place","Bank pays you divident of $50","Go back three places","Make general repairs on all your properties","Pay poor tax of $15 ","Take a trip to Reading Railroad","Take a walk on the Boardwalk","Your building and loan matures. Collect $150","You have won a crossword competition. Collect $100","Advance to GO. Collect $200","Bank error in your favor. Collect $200","Doctor's fees. Pay $50","From sale to stock, you get $50","Grand Opera Night. Collect $50 for tickets","Holiday Fund matures. Collect $100","Income Tax refund. Collect $20","Life Insurance matures. Collect $100","Hospital Fees. Pay $50","School fees. Pay $50","Recieve $25 Consulting Fee","You are assessed for street repairs: Pay $40 per house and $115 per hotel you own.","You have won second prize in a beauty contest. Collect $10.","You inherit $100"};
	//Indicating relative spacing of where to move
	int   chanceRelSpace[25]  = {0,0,0,0,-3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	//Indicates absolute spacing of where to move
	int   chanceAbsSpace[25]  = {GO,ILLIAVE,STCHPLA,-1,-1,-1,-1,READRR,BOARDWALK,-1,-1,GO,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

	//Initializing chance card array

	for(int i=0; i<25; i++) //There are 25 chance cards
	{
		chanceCards[i].name = chanceName[i];
		chanceCards[i].chanceCashID = i;
		chanceCards[i].relativeSpacing = chanceRelSpace[i];
		chanceCards[i].absoluteSpacing = chanceAbsSpace[i];
	}




//Done initializing


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


	/*	//NOTE: This section may be used at a later date. It is used
	 	//to gather what piece or token a player wants to use.

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
	*/

	puts("\nPlayer 1 goes first!");
	while(getLeastCircuits() <= numCircuits) //if end condition
	{
		//printf("\n\nTESTING PURPOSES: Current circuits: %d\n\n", getLeastCircuits());
		for(int player=0;player<NUMPLAYERS;player++)
		{
			int isPlayerRollDouble = doTurn(player);

			switch(isPlayerRollDouble)
			{
			case 0:
				break;
			case 1:
				puts("\nBecause you rolled doubles, you get to go again! You will not get another turn if you roll another double.");
				int x = doTurn(player); //Note that a player can never take three turns in a row. X is a useless variable.
				x+=1; //Do something with X so this compiler stops bugging me about it
				break;
			default:
				puts("Error in switch case for monoploy");
			}



			//sleep(1);
			printf("\n\nYour turn is up! Moving to next player in \n5...");
			sleep(1);
			printf("\n4...");
			sleep(1);
			printf("\n3...");
			sleep(1);
			printf("\n2...");
			sleep(1);
			printf("\n1...\n");
			sleep(1);
			printf("Next player!\n\n");
			sleep(1);
		}

		for(int i=0;i<numCircuits+1;i++)
		{
			if(getLeastCircuits() == i)
			{
				currentCircuit = i; //Finding current circuit
			}
		}
	}
	printf("\n\n\n\n----------GAME OVER---------");
	//----------AVENGERS: ENDGAME----------//
	int firstPlace = -1; //Find first place
	int maxCash = -500000;
	for(int i=0;i<NUMPLAYERS;i++)
	{
		if(players[i].cash > maxCash)
		{
			firstPlace  = i;
			maxCash = players[i].cash;
		}
	}

	int lastPlace = -1; //Find last place
	int lastCash  = 500000;
	for(int i=0;i<NUMPLAYERS;i++)
	{
		if(players[i].cash < lastCash)
		{
			lastPlace = i;
			lastCash  = players[i].cash;
		}
	}

	int secondPlace = -1;
	//Find middle place
	if(((firstPlace == 0) && (lastPlace == 1)) || ((firstPlace == 1) && (lastPlace == 0)))
		secondPlace = 2;
	else if(((firstPlace == 0) && (lastPlace == 2)) || ((firstPlace == 2) && (lastPlace == 0)))
		secondPlace = 1;
	else if(((firstPlace == 1) && (lastPlace == 2)) || ((firstPlace == 2) && (lastPlace == 1)))
		secondPlace = 0;
	else
		puts("Critical error in scoreboard if else statement");

	//int spaceNum = 0;
	printf("\nScoreboard:");

	printf("\n1st Place: %s", players[firstPlace].name);
	//Write a uniform number of spaces
	for(int i=0; i< (15-strlen(players[firstPlace].name)); i++)
	{
		printf(" ");
	}
	printf("Cash: %d", players[firstPlace].cash);

	printf("\n2nd Place: %s", players[secondPlace].name);
	//Write a uniform number of spaces
	for(int i=0; i< (15-strlen(players[secondPlace].name)); i++)
	{
		printf(" ");
	}
	printf("Cash: %d", players[secondPlace].cash);

	printf("\n3rd Place: %s", players[lastPlace].name);
	//Write a uniform number of spaces
	for(int i=0; i< (15-strlen(players[lastPlace].name)); i++)
	{
		printf(" ");
	}
	printf("Cash: %d\n\n\n", players[lastPlace].cash);

	//int isDebtor[3]       = {0, 0, 0};
	int yearsSentenced[3] = {0, 0, 0};

	for(int i=0;i<NUMPLAYERS; i++)
	{
		if(players[i].cash < 0)
		{
			//isDebtor[i] = 1;
			yearsSentenced[i] = abs((int)ceil((double)(players[i].cash)/10.0));
			printf("Due to the poor management of their estate, %s is in debt! They have been sentenced to %d years in Debtor's Prison!\n", players[i].name, yearsSentenced[i]);
		}
	}
	//End of game!
}

int doTurn(int playerNumber) //Returns flag if roll is double
{
	int roll = getRoll(); //Roll
	int isRollDouble = 0;
	if(isDouble(roll)) //Detect double
	{
		roll = roll-100;
		isRollDouble = 1;
	}

	printf("\n%s rolls a %d.",players[playerNumber].name, roll);
	if(isRollDouble)
	{
		printf(" Doubles!\n");
	}

	int newPos = players[playerNumber].position += roll;

	if(newPos > 39)
	{
		players[playerNumber].position -= 40; //If a player goes past Go
		players[playerNumber].cash += 200;
		printf("While moving, you went past GO! Collect $200. You balance is now %d.", players[playerNumber].cash);
		players[playerNumber].circuits++;
	}


	printCurrentPos(playerNumber);
	doSpecialActions(playerNumber, roll);
	doNormalActions(playerNumber, roll);

	return isRollDouble;
}




