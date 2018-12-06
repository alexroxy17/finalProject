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
Player players[3] = {{"Nate", 0, 0, 1500}, {"Rosana", 0, 0, 1500}, {"Shauna", 0, 0, 1500}}; //Initializing players

FILE *fp;
Property properties[40];

fp = fopen("properties.csv", "r");

if(fp == NULL)
{
	puts("Error reading file");
}

int count = 0;
while (fscanf(fp, "%d %[^,] %d %d %d %d %d", &properties[count].group, properties[count].name, &properties[count].price, &properties[count].isBought, &properties[count].owner, &properties[count].houseCount, &properties[count].hotelCount) == 7) {
        count++;
    }
for(int i=0; i<count;i++)
{
	printf("%d\n", properties[i].group);
}



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

printf("\nPlayer 1 is %s\nPlayer 2 is %s\nPlayer 3 is %s", players[0].name, players[1].name, players[2].name);
printf("\nPlayer 1 is %s\nPlayer 2 is %s\nPlayer 3 is %s", getPiece(players[0].piece), getPiece(players[1].piece), getPiece(players[2].piece));
}


