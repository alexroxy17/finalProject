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
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	//Determine initial conditions:
	//How many players
	//Number of circuits around the board to play

	//int numPlayers = 3; //Initialize players
	int numCircuits = 0; //Initialize circuits



	puts("How many circuits around the board would you like to play?");
	scanf("%d",&numCircuits);



	monopoly(numCircuits);
	//printf("%d %d", numPlayers, numCircuits);




	return EXIT_SUCCESS;
}
