# finalProject
Possible Monopoly in C
Nathaniel Bajakian, Rosana Pochat, Shuana Sullivan 

______________________________________________________________________________
|      |      |      |      |      |      |      |      |      |      |      |
|      | RED  |      | RED  | RED  |      |YELLOW|YELLOW|      |YELLOW|      |
|______|______|______|______|______|______|______|______|______|______|______|
|      |                                                              |      |
|ORANGE|                                                              |GREEN |
|______|                                                              |______|
|      |                                                              |      |
|ORANGE|                                                              |GREEN |
|______|                                                              |______|
|      |                                                              |      |
|      |                                                              |      |
|______|                                                              |______|
|      |                                                              |      |
|ORANGE|                                                              |GREEN |
|______|                                                              |______|
|      |                                                              |      |
|      |                                                              |      |
|______|                                                              |______|
|      |                                                              |      |
| PINK |                                                              |      |
|______|                                                              |______|
|      |                                                              |      |
| PINK |                                                              | BLUE |
|______|                                                              |______|
|      |                                                              |      |
|      |                                                              |      |
|______|                                                              |______|
|      |                                                              |      |
| PINK |                                                              | BLUE |
|______|______________________________________________________________|______|
|      |      |      |      |      |      |      |      |      |      |      |
|      | TEAL | TEAL |      | TEAL |      |      |BROWN |      |BROWN |  GO  |
|______|______|______|______|______|______|______|______|______|______|______|


Property:
	Group:
	Price:
	isBought:
	Owner:
	houseCount:
	hasHotel:

Player:
	name:
	piece:
	position:
	cash: 			//initial 1500)

Groups:
	BROWN  0
	TEAL   1
	PINK   2
	ORANGE 3
	RED    4
	YELLOW 5
	GREEN  6
	BLUE   7

Pieces: 
	PDOG 0
	PCAR 1
	PBAT 2
	PHAT 3
	PTHI 4
	PSHO 5
	PIRO 6
	PWHE 7

Switch cases for game board

Chose Card
	cashModifier =
	posModifier  = 
	absPosMod    =   	//if -1 nothing happens

comand -> how many players
initialization code
player info


function list:
* main(int arqc, char* arqv [])
  //iniziation player + how many player 
    shuffleChooseCard(void)
  //check aras
* doGame(string[numPlayers])
  last 10 circuits 
  play each player
    update money, position

in the .h file we're gonna initialize the board game


_________________________________________________________
|						                                           	|  
|                      BOADGAME                         |
|_______________________________________________________|
 * 		     *		     *	  	 * 
misc		  pieces		GO(0)		groups
->card		->max(3)			    ->properties
->trains
->utilities
->free parking(20)
