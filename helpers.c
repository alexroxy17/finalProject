#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "finalProject.h"

int detectPiece(char* str)
{
	int playerPiece = -1;

	char lowerstr[20];
	for(int i=0;i<20;i++)
	{
		lowerstr[i] = '\0';
	}

	//printf("length: %d\n",strlen(str));
	for(int i=0; i<strlen(str); i++)
	{
		lowerstr[i] = tolower(str[i]);
	}


	if(strcmp("dog", lowerstr) == 0)
	{
		playerPiece = PDOG;
	}
	/*
	 * dog
	 * car
	 * battleship
	 * hat
	 * thimble
	 * shoe
	 * iron
	 * wheelbarrow
	 */
	else if(strcmp("car", lowerstr)==0)
		playerPiece = PCAR;
	else if(strcmp("battleship", lowerstr==0))
		playerPiece = PBAT;
	else if(strcmp("hat", lowerstr==0))
		playerPiece = PHAT;
	else if(strcmp("thimble", lowerstr==0))
		playerPiece = PTHI;
	else if(strcmp("shoe", lowerstr==0))
		playerPiece = PSHO;
	else if(strcmp("iron", lowerstr==0))
		playerPiece = PIRO;
	else if(strcmp("wheelbarrow", lowerstr==0))
		playerPiece = PWHE;
	else
	{
		printf("Invalid input. Please try again.");
		playerPiece = -2;
	}
	//printf("tolower: %s\n", lowerstr);
	//printf("piece: %d", strcmp(lowerstr, "dog"));

	return playerPiece;
}
