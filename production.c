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

void monopoly(int numCircuits) {

Player players[3] = {{"Nate", 0, 0, 1500}, {"Rosana", 0, 0, 1500}, {"Shauna", 0, 0, 1500}}; //Initializing players


char p1Name[20];
char p2Name[20];
char p3Name[20];

char p1Piece[20];
char p2Piece[20];
char p3Piece[20];

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
	printf("\nWhat piece would player %d like to play as?", i);
	char input[20];//Initialize
	for(int j=0;j<20;j++)
	{
		input[j]='\0';
	}
	scanf("%s",input); //Take in input
puts("okay1");

	int flag = detectPiece(input);
	puts("okay1.5");
	if(flag != -2)
	//new comment!
	{
		puts("okay2");
		playerPieces[i-1] = detectPiece(input);
	}
	else //iff invalid input
	{
		puts("okay3");
		if(i==1)
		{
			puts("Invalid input. Defaulting to car.");
			playerPieces[0] = PCAR;
		}
		else if(i==2)
		{
			puts("Invalid input. Defaulting to battleship..");
			playerPieces[1] = PBAT;
		}
		else if(i==3)
		{
			puts("Invalid input. Defaulting to thimble.");
			playerPieces[2] = PTHI;
		}
		else
		{
			puts("Bigly error in selecting pieces");
		}
	}
}

players[0].piece = playerPieces[0];
players[1].piece = playerPieces[1];
players[2].piece = playerPieces[2];

printf("\nPlayer 1 is %s\nPlayer 2 is %s\nPlayer 3 is %s", players[0].name, players[1].name, players[2].name);
printf("\nPlayer 1 is %d\nPlayer 2 is %d\nPlayer 3 is %d", players[0].piece, players[1].piece, players[2].piece);
}


