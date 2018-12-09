#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "finalProject.h"

Property properties[40];
Player players[3];
int railroadRent[4];

int detectPieceFromInput(char* str)
{
	int playerPiece = -1; //Initialize to invalid

	char lowerstr[20];
	for(int i=0;i<20;i++)
	{
		lowerstr[i] = '\0';
	}//Create and initialize string for lowered version to go into

	for(int i=0; i<strlen(str); i++)
	{
		lowerstr[i] = tolower(str[i]);
	}//Make string lowercase for processing

	//Compare string, find out which one it is.
	if(strcmp("dog", lowerstr) == 0)
		playerPiece = PDOG;
	else if(strcmp("car", lowerstr)==0)
		playerPiece = PCAR;
	else if(strcmp("battleship", lowerstr)==0)
		playerPiece = PBAT;
	else if(strcmp("hat", lowerstr)==0)
		playerPiece = PHAT;
	else if(strcmp("thimble", lowerstr)==0)
		playerPiece = PTHI;
	else if(strcmp("shoe", lowerstr)==0)
		playerPiece = PSHO;
	else if(strcmp("iron", lowerstr)==0)
		playerPiece = PIRO;
	else if(strcmp("wheelbarrow", lowerstr)==0)
		playerPiece = PWHE;
	else
	{
		char input[20];
		for(int i=0;i<20;i++)
		{
			input[i]='\0';
		} //Initialize recursive input string
		printf("\nInvalid input. Please try again.\n");
		scanf("%s",input); //Take in input
		playerPiece = detectPieceFromInput(input);
	}
	return playerPiece;
}

const char* getPiece(int playerPieceInteger)
{
	//This function takes in the internal constant for a player piece, and
	//returns a string for the formal, english name of that piece with an uppercase first character.

	if(playerPieceInteger == PDOG)
		return "Dog";
	else if(playerPieceInteger == PCAR)
		return "Car";
	else if(playerPieceInteger == PBAT)
		return "Battleship";
	else if(playerPieceInteger == PHAT)
		return "Hat";
	else if(playerPieceInteger == PTHI)
		return "Thimble";
	else if(playerPieceInteger == PSHO)
		return "Shoe";
	else if(playerPieceInteger == PIRO)
		return "Iron";
	else if(playerPieceInteger == PWHE)
		return "Wheelbarrow";
	else
		return "Error in getPiece";
}

const char* getGroup(int propertyGroupInteger)
{
	//This takes in the internal constant for a group coulor, and
	//returns a string with the formal, english name of that piece with an uppercase first character.
	switch(propertyGroupInteger)
	{
		case GBROWN: //If brown group...
			return "Brown"; //Return "Brown"
			break;
		case GTEAL:
			return "Teal";
			break;
		case GPINK:
			return "Pink";
			break;
		case GORANGE:
			return "Orange";
			break;
		case GRED:
			return "Red";
			break;
		case GYELLOW:
			return "Yellow";
			break;
		case GGREEN:
			return "Green";
			break;
		case GBLUE:
			return "Blue";
			break;
		case GRAILROAD:
			return "Railroad";
			break;
		case GUTILITY:
			return "Utility";
			break;
		case GSPECIAL:
			return "Special";
			break;
		default:
			return "CRITICAL_ERROR_getGroup";
			puts("Critical error in getGroup");
			break;
	}
}

int getRoll(void)
{
	int result = -50000; //Initialize number to outrageously out of bounds number
	srand(time(NULL));   //Seed random with current time, ensure "true" randomness

	int max_number = 6;  // Die has a maximum of 6 pips
	int min_number = 1;  // Die has a miniumum of 1 pip


	int die1 = rand() % (max_number + 1 - min_number) + min_number; //Roll one dice
	int die2 = rand() % (max_number + 1 - min_number) + min_number; //Roll a second dice

	if(die1 == die2)
	{
		result = 100+die1+die2; //If rolling a double, add 100 to the number to signal that it is a double
	}
	else
	{
		result = die1+die2;     //If not a double, then just return the regular die.
	}

	return result;
}

int isDouble(int roll)
{
	if((roll-100) > 0) //If the roll is a double
	{
		return 1; //Return true
	}
	else //Else
	{
		return 0;
	}
}



void printCurrentPos(int whatPlayer)
{
	printf("\n%s landed on %s.", players[whatPlayer].name, properties[players[whatPlayer].position].name);

	if(properties[players[whatPlayer].position].group != GSPECIAL)
	{
		printf("\nOwner: %s", getOwner(properties[players[whatPlayer].position].owner));
		printf("\nView more details? (Y/N)\n");
		char response1[20];
		scanf("%9s", response1);
		if(getYesOrNo(response1))
		{
			printf("\nPrice : %d\n", properties[players[whatPlayer].position].price);
			if((properties[players[whatPlayer].position].group != GRAILROAD) && (properties[players[whatPlayer].position].group != GUTILITY))
			{
				printf("Houses: %d\n", properties[players[whatPlayer].position].houseCount);
				printf("Hotels: %d\n", properties[players[whatPlayer].position].hotelCount);
				printf("Cost per house: %d\n", properties[players[whatPlayer].position].houseCost);
				printf("Rent with one house:    %d\n", properties[players[whatPlayer].position].oneHouseRentPrice);
				printf("          two houses:   %d\n", properties[players[whatPlayer].position].twoHouseRentPrice);
				printf("          three houses: %d\n", properties[players[whatPlayer].position].threeHouseRentPrice);
				printf("          four houses:  %d\n", properties[players[whatPlayer].position].fourHouseRentPrice);
				printf("Rent with hotel: %d\n", properties[players[whatPlayer].position].hotelRentPrice);
			}
			else if(properties[players[whatPlayer].position].group == GRAILROAD)
			{
				printf("Rent with one owned railroad:  %d\n", railroadRent[0]);
				printf("Rent with two owned railroads: %d\n", railroadRent[1]);
				printf("Rent with one owned railroads: %d\n", railroadRent[2]);
				printf("Rent with one owned railroads: %d\n", railroadRent[3]);
			}
			else if(properties[players[whatPlayer].position].group == GUTILITY)
			{
				printf("Rent with one owned utility:   Four times value shown on dice.\n");
				printf("Rent with two owned utilities: Ten  times value shown on dice.\n");
			}
			else
			{
				printf("Critical error in printCurrentPos");
			}
		}
	}
}


int getYesOrNo(char input[20])
{
	int result = -1;

	char lowerstr[20];
	for(int i=0;i<20;i++)
	{
		lowerstr[i] = '\0';
	}//Create and initialize string for lowered version to go into

	for(int i=0; i<strlen(input); i++)
	{
		lowerstr[i] = tolower(input[i]);
	}//Make string lowercase for processing

	if((strcmp(lowerstr, "y") == 0) || (strcmp(lowerstr, "yes")) == 0)
	{
		result = 1;
	}
	else
	{
		result = 0;
	}

	return result;
}

const char* getOwner(int ownerInt)
{
	switch(ownerInt)
	{
	case PBANK:
		return "Bank";
		break;
	case PLAYER1:
		return players[PLAYER1].name;
		break;
	case PLAYER2:
		return players[PLAYER2].name;
		break;
	case PLAYER3:
		return players[PLAYER3].name;
		break;
	default:
		return "Critical error in getOwner";
		break;
	}
}
