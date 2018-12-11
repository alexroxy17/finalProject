#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "finalProject.h"

Property properties[40];
Player players[3];
int railroadRentLookup[4];
int currentCircuit;
ChanceCard chanceCards[25];

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

	printf("\nRolling...");
	sleep(1);
	int die1 = rand() % (max_number + 1 - min_number) + min_number; //Roll one dice
	srand(time(NULL));
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
		if(isYes(response1))
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
				printf("Rent with one owned railroad:  %d\n", railroadRentLookup[0]);
				printf("Rent with two owned railroads: %d\n", railroadRentLookup[1]);
				printf("Rent with one owned railroads: %d\n", railroadRentLookup[2]);
				printf("Rent with one owned railroads: %d\n", railroadRentLookup[3]);
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


int isYes(char input[20])
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

int isChance(int position) //Returns 1 if the current position is chance, 0 otherwise.
{
	int isChance = -1;

	switch(position)
	{
		case CHANCE1:
		case CHANCE2:
		case CHANCE3:
		case CHANCE4:
		case CHANCE5:
		case CHANCE6:
			isChance = 1;
			break;
		default:
			isChance = 0;
	}

	return isChance;
}

void doSpecialActions(int playerNumber, int roll)
{
	int currentPos   = players[playerNumber].position;
	int currentGroup = properties[currentPos].group;

	if(currentGroup == GSPECIAL)//If the player landed on a special group
	{
		switch(currentPos)
		{
			case CHANCE1:
			case CHANCE2:
			case CHANCE3:
			case CHANCE4:
			case CHANCE5:
			case CHANCE6:
				doChance(playerNumber, roll);
				break;
			case GO:
				doGo(playerNumber);
				break;
			case INCOMETAX:
				doIncomeTax(playerNumber);
				break;
			case LUXURYTAX:
				doLuxuryTax(playerNumber);
				break;
			case JAIL:
				doJail(playerNumber);
				break;
			case GOTOJAIL:
				doGoToJail(playerNumber);
				break;
			case FREEPARKING:
				printf("\nFree parking! Relax and enjoy.");
				break;
			default:
				puts("You made an error in the switch case for doSpecialAction");
		}
	}
	//Don't need to do anything if else
}

void doChance(int playerNumber, int roll)
{
	//Make array for cards
	//Update position, money if necessary
	//puts("Chance is not implemented yet.");

	srand(time(NULL));   //Seed random with current time, ensure "true" randomness

	int max_number = 24;  // Die has a maximum of 6 pips
	int min_number = 0;  // Die has a miniumum of 1 pip

	int randCard = rand() % (max_number + 1 - min_number) + min_number; //Choose a random card

	ChanceCard randomChanceCard = chanceCards[randCard];

	int oldPos = -1;
	int newPos = -1;

	int numHouses = 0;
	int numHotels = 0;
	int formula = 0;

	switch(randomChanceCard.chanceCashID)
	{
	case 0:
	case 11: {
		players[playerNumber].cash+= 200;
		players[playerNumber].position = 0;
		players[playerNumber].circuits++;
		printf("\nAdvance to GO. Collect $200. Your balance is now %d.", players[playerNumber].cash);
		break;}
	case 1:{//Advance to IlliAve
		//Determine if they're already past IllinoisAve
		oldPos = players[playerNumber].position;
		newPos = randomChanceCard.absoluteSpacing;


		players[playerNumber].position = randomChanceCard.absoluteSpacing; //Move to illi
		printf("\nAdvance to Illinois Avenue. ");
		if(oldPos > newPos)
		{
			players[playerNumber].cash += 200;
			printf("You passed GO In the process. Collect $200. Your balance is now %d.", players[playerNumber].cash);
		}
		break;}
	case 2:{//Advance to StCharlesPlace
		//Determine if they're already past StCharlesPlace
		oldPos = players[playerNumber].position;
		newPos = randomChanceCard.absoluteSpacing;


		players[playerNumber].position = randomChanceCard.absoluteSpacing; //Move to illi
		printf("\nAdvance to St Charles Place. ");
		if(oldPos > newPos)
		{
			players[playerNumber].cash += 200;
			printf("You passed GO In the process. Collect $200. Your balance is now %d.", players[playerNumber].cash);
		}
		printCurrentPos(playerNumber);
		doSpecialActions(playerNumber, roll);
		doNormalActions(playerNumber, roll);
		break;}
	case 3:{
		players[playerNumber].cash += 50;
		printf("\nBank pays dividend of $50. Your balance is now %d.", players[playerNumber].cash);
		break;}
	case 4: //Go back three spaces
	{
		players[playerNumber].position -= 3;
		printf("\nGo back three spaces. Your new position is %s.", properties[players[playerNumber].position].name);
		printCurrentPos(playerNumber);
		doSpecialActions(playerNumber, roll);
		doNormalActions(playerNumber, roll);
		break;
	}
	case 5:
		numHouses = countHouses(playerNumber);
		numHotels = countHotels(playerNumber);
		formula   = (25 * numHouses) + (100 * numHotels);

		players[playerNumber].cash -= formula;
		printf("/n Make general repairs on all your properties. Total cost: %d. Your new balance is %d.\n", formula, players[playerNumber].cash);
		break;
	case 6:
		players[playerNumber].cash -= 15;
		printf("\nPay poor tax of $15. Your balance is now %d.", players[playerNumber].cash);
		break;
	case 7:
		oldPos = players[playerNumber].position;
		newPos = READRR;
		players[playerNumber].position = READRR;
		printf("\nTake a trip on the Reading Railroad!\n");
		if(oldPos > newPos)
		{
			players[playerNumber].cash += 200;
			printf("You passed GO In the process. Collect $200. Your balance is now %d.\n", players[playerNumber].cash);
		}
		printCurrentPos(playerNumber);
		doSpecialActions(playerNumber, roll);
		doNormalActions(playerNumber, roll);
		break;
	case 8:
		oldPos = players[playerNumber].position;
		newPos = BOARDWALK;
		players[playerNumber].position = newPos;
		printf("\nTake a walk on Boardwalk!\n");
		if(oldPos > newPos)
		{
			players[playerNumber].cash += 200;
			printf("You passed GO In the process. Collect $200. Your balance is now %d.\n", players[playerNumber].cash);
		}
		printCurrentPos(playerNumber);
		doSpecialActions(playerNumber, roll);
		doNormalActions(playerNumber, roll);
		break;
	case 9:
		players[playerNumber].cash += 150;
		printf("\nYour loan matures. Collect $150. Your balance is now %d.\n", players[playerNumber].cash);
		break;
	case 10:
		players[playerNumber].cash += 100;
		printf("\nYou have won a crossword competition. Collect $100. Your balance is now %d.\n", players[playerNumber].cash);
		break;
	case 12:
		players[playerNumber].cash += 200;
		printf("\nBank error in your favor. Collect $200. Your balance is now %d.\n", players[playerNumber].cash);
		break;
	case 13:
	case 19:
	case 20:
		players[playerNumber].cash -= 50;
		printf("\nDoctor's fees. Pay $50. Your balance is now %d.\n", players[playerNumber].cash);
		break;
	case 14:
		players[playerNumber].cash += 50;
		printf("\nSale of stock. Collect $50. Your balance is now %d.\n", players[playerNumber].cash);
		break;
	case 15:
		players[playerNumber].cash += 50;
		printf("\nGrand Opera night. Collect $50 in tickets. Your balance is now %d.\n", players[playerNumber].cash);
		break;
	case 16:
		players[playerNumber].cash += 100;
		printf("\nHoliday fund matures. Collect $100. Your balance is now %d.\n", players[playerNumber].cash);
		break;
	case 17:
		players[playerNumber].cash += 20;
		printf("\nIncome tax refund. Collect $20. Your balance is now %d.\n", players[playerNumber].cash);
		break;
	case 18:
		players[playerNumber].cash += 100;
		printf("\nLife insurance matures. Collect $100. Your balance is now %d.\n", players[playerNumber].cash);
		break;
	case 21:
		players[playerNumber].cash += 25;
		printf("\nRecieve consulting fee. Collect $25. Your balance is now %d.\n", players[playerNumber].cash);
		break;
	case 22:
		numHouses = countHouses(playerNumber);
		numHotels = countHotels(playerNumber);
		formula   = (40 * numHouses) + (115 * numHotels);

		players[playerNumber].cash -= formula;
		printf("\nYou are assessed for street repairs. Total cost: %d. Your new balance is %d.\n", formula, players[playerNumber].cash);
		break;
	case 23:
		players[playerNumber].cash += 10;
		printf("\nYou have won second place in a beauty contest. Collect $10. Your balance is now %d.\n", players[playerNumber].cash);
		break;
	case 24:
		players[playerNumber].cash += 100;
		printf("\nYou recieve inheritance. Collect $100. Your balance is now %d.\n", players[playerNumber].cash);
		break;
	default:
		puts("Critical error in getChance");

	}
}

void doGo(int playerNumber)
{
	int newCash = players[playerNumber].cash + 200;
	players[playerNumber].cash = newCash;
	players[playerNumber].circuits++;
	printf("\nYou got paid $200 for passing GO. Your new balance is %d.", newCash);
}

void doIncomeTax(int playerNumber)
{
	if(players[playerNumber].cash < 2000)
	{
		int tenPercent = abs(round(players[playerNumber].cash *  0.1)); //is 10 percent of player's cash
		int newCash = players[playerNumber].cash - tenPercent;//Subtract ten percent
		players[playerNumber].cash = newCash;//Update cash

		puts("Your balance is below $2000, so you paid 10% of your current value.");
		printf("\nYou paid $%d in income tax. Your new balance is $%d.", tenPercent, newCash);
	}
	else
	{
		int newCash = players[playerNumber].cash - 200;
		players[playerNumber].cash = newCash;

		printf("\nYou paid $200 in Income Tax. Your new balance is %d.", newCash);
	}
}

void doLuxuryTax(int playerNumber)
{
	int newCash = (players[playerNumber].cash - 75); //Luxury Tax is $75
	printf("\nYou paid $75 in Luxury Tax. Your new balance is %d.", newCash);
	players[playerNumber].cash = newCash;
}

void doJail(int playerNumber)
{
	printf("\nWow! Look at all the criminals! You decide not to stay very long, as there is a deeply foreboding smell of cheetos.\n"); //Shauna wanted to say something about Trump here
}

void doGoToJail(int playerNumber)
{
	printf("\nYou may have landed on Go To Jail, but President Trump pardoned you from this witch hunt!");
}





void doNormalActions(int playerNumber, int diceRoll)
{
	int currentPos   = players[playerNumber].position;
	int currentGroup = properties[currentPos].group;

	if((currentGroup != GSPECIAL) && properties[currentPos].owner == PBANK)//If the player landed on a special group
	{
		printf("\nYou have $%d.\nBuy this property? (Y/N)\n", players[playerNumber].cash);
		char buyProperty[20];
		scanf("%9s", buyProperty);
		if(isYes(buyProperty))
		{
			properties[currentPos].owner = playerNumber; //Update the owner of the property
			players[playerNumber].propertyList[players[playerNumber].ownedProperties] = properties[currentPos]; //Put property into first available slot
			players[playerNumber].ownedProperties++; //Increment number of owned properties
			if(properties[players[playerNumber].position].group == GRAILROAD)
			{
				players[playerNumber].ownedRailroads++;
			}
			if(properties[players[playerNumber].position].group == GUTILITY)
			{
				players[playerNumber].ownedUtilities++;
			}


			int propertyCost = properties[currentPos].price; //Get price

			players[playerNumber].cash -= propertyCost; //Player cash is equal to player cash minus property cost.
			printf("Congratulations! You now own %s. Your new balance is %d.", properties[currentPos].name, players[playerNumber].cash);
		}
	}
	else if((currentGroup != GSPECIAL) && (properties[currentPos].owner != playerNumber)) //If you land on someone else's property
	{
		int rentToPay = -1;
		//puts("Known bug: owner of property will still be paid if the person trying to pay does not have enough money.");

		//IF IT IS A NORMAL PROPERTY
		if((properties[currentPos].group != GRAILROAD) && (properties[currentPos].group != GSPECIAL) && (properties[currentPos].group != GUTILITY))
		{
			switch(properties[currentPos].houseCount)
			{
				case 0:
					//No house rent price
					rentToPay = properties[currentPos].baseRentPrice;
					//Pay owner
					players[properties[currentPos].owner].cash += rentToPay;
					//Detract money from payer
					players[playerNumber].cash -= rentToPay;
					break;
				case 1:
					//One house rent price
					rentToPay = properties[currentPos].oneHouseRentPrice;
					//Pay owner
					players[properties[currentPos].owner].cash += rentToPay;
					//Detract money from payer
					players[playerNumber].cash -= rentToPay;
					break;
				case 2:
					//Two house rent price
					rentToPay = properties[currentPos].twoHouseRentPrice;
					//pay Owner
					players[properties[currentPos].owner].cash += rentToPay;
					//Detract money from payer
					players[playerNumber].cash -= rentToPay;
					break;
				case 3:
					//Three house rent price
					rentToPay = properties[currentPos].threeHouseRentPrice;
					//pay Owner
					players[properties[currentPos].owner].cash += rentToPay;
					//Detract money from payer
					players[playerNumber].cash -= rentToPay;
					break;
				case 4:
					//Four house rent price
					rentToPay = properties[currentPos].fourHouseRentPrice;
					//pay Owner
					players[properties[currentPos].owner].cash += rentToPay;
					//Detract money from payer
					players[playerNumber].cash -= rentToPay;
					break;
				case 5:
					//Hotel rent price
					rentToPay = properties[currentPos].hotelRentPrice;
					//pay Owner
					players[properties[currentPos].owner].cash += rentToPay;
					//Detract money from payer
					players[playerNumber].cash -= rentToPay;
					break;
				default:
					puts("Error in rent payment system");
			}
			printf("%s owns this property! You owe them $%d. Your balance is now $%d. Their balance is now %d.", players[properties[currentPos].owner].name, rentToPay, players[playerNumber].cash, players[properties[currentPos].owner].cash);
		}

		//ELSE: IF IT IS A RAILROAD
		else if(properties[currentPos].group == GRAILROAD)
		{
			int ownedRailroads = players[properties[currentPos].owner].ownedRailroads; //Find out how many railroads the owner of the property has
			//Determine how much the player must pay:
			rentToPay = railroadRentLookup[ownedRailroads]; //From global variable railroadRent, initialized in the beginning of production.c
			//Pay owner
			players[properties[currentPos].owner].cash += rentToPay;
			//Take money from player
			players[playerNumber].cash -= rentToPay;
			printf("%s owns this property! You owe them $%d. Your balance is now $%d. Their balance is now %d.\n", players[properties[currentPos].owner].name, rentToPay, players[playerNumber].cash, players[properties[currentPos].owner].cash);
		}

		//ELSE: IF IT IS A UTILITY
		else if(properties[currentPos].group == GUTILITY)
		{
			//Determine what the rent will actually be
			switch(players[properties[currentPos].owner].ownedUtilities)
			{
			case 1: //If the owner only owns one utility
				rentToPay = 4 * diceRoll;
				//Pay owner
				players[properties[currentPos].owner].cash+= rentToPay;
				//Take money from player
				players[playerNumber].cash -= rentToPay;
				break;
			case 2:
				rentToPay = 10 * diceRoll;
				//Pay Owner
				players[properties[currentPos].owner].cash+= rentToPay;
				//Take money from player
				players[playerNumber].cash -= rentToPay;
				break;
			default:
				puts("Critical error in railroad rent switch case");

			}
			printf("%s owns this property! You owe them $%d. Your balance is now $%d. Their balance is now %d.\n", players[properties[currentPos].owner].name, rentToPay, players[playerNumber].cash, players[properties[currentPos].owner].cash);
		}
		else
		{
			puts("Critical error in payment of rent.");
		}
	}
	else if((currentGroup != GSPECIAL) && (properties[currentPos].owner == playerNumber)) //If you land on your own property
	{
		printf("\nYou landed on your own property! Time to kick back, relax, and enjoy not paying rent!");
	}

	if(currentCircuit > 0)
	{
		printf("\nYou have $%d.\nWould you like to buy houses? (Y/N)\n", players[playerNumber].cash);
		char buyHouses[20];
		scanf("%9s", buyHouses);
		if(isYes(buyHouses))
		{
			doBuyHouses(playerNumber);
		}
	}
}

void doBuyHouses(int playerNumber)
{
	int ownedProperties = players[playerNumber].ownedProperties;
	printf("Which property would you like to buy houses for? (Use first number. Example: 1, 2, 3, etc.)\n");
	for(int i=0;i<ownedProperties;i++)
	{
		int num = i+1;
		printf("%d) %s -- Group: %s -- Current Houses: %d -- House Cost: %d\n", num, players[playerNumber].propertyList[i].name, getGroup(players[playerNumber].propertyList[i].group), players[playerNumber].propertyList[i].houseCount, players[playerNumber].propertyList[i].houseCost);
	}
	int whichProperty = -1;
	scanf("%d", &whichProperty);
	//----ERROR CHECKING----//
	if(whichProperty < 1)
	{
		puts("Error in doNormalActions");
	}
	//----END ERROR CHECKING----//
	whichProperty -=1;
	printf("\nHow many MORE houses would you like to buy for %s?\n", players[playerNumber].propertyList[whichProperty].name);
	int howManyMoreHouses = -1;
	scanf("%d", &howManyMoreHouses);
	int currentHouseCount = players[playerNumber].propertyList[whichProperty].houseCount;

	if((howManyMoreHouses + currentHouseCount) > 5) //If the user is asking for more houses than actually exist
	{
		puts("You entered too many houses. Canceling transaction.");
	}
	else if((howManyMoreHouses * players[playerNumber].propertyList[whichProperty].houseCost) > players[playerNumber].cash)
	{
		puts("You don't have enough money for that. Canceling transaction.");
	}
	else
	{
		//int playerCash = players[playerNumber].cash;
		switch(howManyMoreHouses)
		{
			case 0:
				puts("You entered 0 houses. Canceling transaction.");
				break;
			case 1:
					players[playerNumber].cash -= (players[playerNumber].propertyList[whichProperty].houseCost * 1); //Subtract cost of houses
					players[playerNumber].propertyList[whichProperty].houseCount += 1;                               //Increase houses on property
					properties[players[playerNumber].propertyList[whichProperty].location].houseCount += 1;
					if(players[playerNumber].propertyList[whichProperty].houseCount == 5)
						printf("%s now has a hotel!",   players[playerNumber].propertyList[whichProperty].name);
					else
						printf("%s now has %d houses!", players[playerNumber].propertyList[whichProperty].name, players[playerNumber].propertyList[whichProperty].houseCount);
				break;
			case 2:
					players[playerNumber].cash -= (players[playerNumber].propertyList[whichProperty].houseCost * 2); //Subtract cost of houses
					players[playerNumber].propertyList[whichProperty].houseCount += 2;                               //Increase houses on property
					properties[players[playerNumber].propertyList[whichProperty].location].houseCount += 2;
					if(players[playerNumber].propertyList[whichProperty].houseCount == 5)
						printf("%s now has a hotel!",   players[playerNumber].propertyList[whichProperty].name);
					else
						printf("%s now has %d houses!", players[playerNumber].propertyList[whichProperty].name, players[playerNumber].propertyList[whichProperty].houseCount);
				break;
			case 3:
					players[playerNumber].cash -= (players[playerNumber].propertyList[whichProperty].houseCost * 3); //Subtract cost of houses
					players[playerNumber].propertyList[whichProperty].houseCount += 3;
					properties[players[playerNumber].propertyList[whichProperty].location].houseCount += 3;//Increase houses on property
					if(players[playerNumber].propertyList[whichProperty].houseCount == 5)
						printf("%s now has a hotel!",   players[playerNumber].propertyList[whichProperty].name);
					else
						printf("%s now has %d houses!", players[playerNumber].propertyList[whichProperty].name, players[playerNumber].propertyList[whichProperty].houseCount);
				break;
			case 4:
					players[playerNumber].cash -= (players[playerNumber].propertyList[whichProperty].houseCost * 4); //Subtract cost of houses
					players[playerNumber].propertyList[whichProperty].houseCount += 4;                               //Increase houses on property
					properties[players[playerNumber].propertyList[whichProperty].location].houseCount += 4;
					if(players[playerNumber].propertyList[whichProperty].houseCount == 5)
						printf("%s now has a hotel!",   players[playerNumber].propertyList[whichProperty].name);
					else
						printf("%s now has %d houses!", players[playerNumber].propertyList[whichProperty].name, players[playerNumber].propertyList[whichProperty].houseCount);
				break;
			case 5:
					players[playerNumber].cash -= (players[playerNumber].propertyList[whichProperty].houseCost * 5); //Subtract cost of houses
					players[playerNumber].propertyList[whichProperty].houseCount += 5;                               //Increase houses on property
					properties[players[playerNumber].propertyList[whichProperty].location].houseCount += 5;
					printf("%s now has a hotel!",   players[playerNumber].propertyList[whichProperty].name);
				break;
		}
	}
}

int getLeastCircuits(void)
{
	int leastCircuits = 500000;

	for(int i=0; i<NUMPLAYERS;i++)
	{
		if(players[i].circuits < leastCircuits)
		{
			leastCircuits = players[i].circuits; //Search through all the players, and find what the least number of circuits travelled is.
		}
	}
	return leastCircuits;
}


int countHouses(int playerNumber)
{
	int houses = 0;

	for(int i=0; i<players[playerNumber].ownedProperties;i++)
	{
		if(players[playerNumber].propertyList[i].houseCount != 5)
		{
			houses += players[playerNumber].propertyList[i].houseCount;
		}
	}
	return houses;
}
int countHotels(int playerNumber)
{
	int hotels = 0;

	for(int i=0; i<players[playerNumber].ownedProperties;i++)
	{
		if(players[playerNumber].propertyList[i].houseCount == 5)
		{
			hotels++;
		}
	}
	return hotels;
}
