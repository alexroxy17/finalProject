/*
 ============================================================================
 Name        : finalProject.c
 Author      : Nathaniel Bajakian, Rosana Pochat, Shauna Sullivan
 Version     : 0.1
 Copyright   : Copyright Nathaniel Bajakian, 2018, Creative Commons
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "finalProject.h"


int main(int argc, char* argv[]) {

	int numCircuits = -1; //Initialize circuits
	printf("MONOPOLY\n");
	puts("How many circuits around the board would you like to play?");
	scanf("%d",&numCircuits);


	

	monopoly(numCircuits);

	printf("\n\nThank you for playing our game! Adapted by Nathaniel S. Bajakian, Rosana Pochat, and Shauna Sullivan, WPI 2021");
	printf("\nIf you have any comments, questions, or concerns, please email nsbajakian@wpi.edu.");




	return EXIT_SUCCESS;
}
