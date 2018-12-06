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

/*
 * #define PDOG 0 //Dog
#define PCAR 1 //Car
#define PBAT 2 //Battleship
#define PHAT 3 //Hat
#define PTHI 4 //Thimble
#define PSHO 5 //Shoe
#define PIRO 6 //Iron
#define PWHE 7 //Wheel
 */
const char* getPiece(int playerPieceInteger)
{
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
