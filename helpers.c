#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "finalProject.h"

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
