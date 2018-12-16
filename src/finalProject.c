/*
 ============================================================================
 Name        : finalProject.c
 Author      : Nathaniel Bajakian, Rosana Pochat, Shauna Sullivan
 Version     : 0.1
 Copyright   : Copyright Nathaniel Bajakian, 2018, Creative Commons
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#include "finalProject.h"


int main(int argc, char* argv[]) {
	//puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	//Determine initial conditions:
	//How many players	//Number of circuits around the board to play

	//int numPlayers = 3; //Initialize players  //Deprecated, using constant 3 players now. Const in .h file
	int numCircuits = -1; //Initialize circuits
	//puts("fix numcircuits later when done when whole project is done you dummy");
	printf("MONOPOLY\n");
	puts("How many circuits around the board would you like to play?");
	scanf("%d",&numCircuits);

	//Property emptyProperties[40];
	//struct property allProperties[40];
	//allProperties = initializeProperties();

	monopoly(numCircuits);

	printf("\n\nThank you for playing our game! Adapted by Nathaniel S. Bajakian, Rosana Pochat, and Shauna Sullivan, WPI 2021");
	printf("\nIf you have any comments, questions, or concerns, please email nsbajakian@wpi.edu.");



	//fflush(stdout);
	//testingCSV();

	//printf("%d %d", numPlayers, numCircuits);

	//puts(getPiece(PCAR));


	return EXIT_SUCCESS;
}
