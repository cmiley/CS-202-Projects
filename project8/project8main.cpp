/******************************************************/
//Name: Cayler Miley
//Program: project8main.cpp
//Purpose: Overloaded operators and complete use of everything learned in class and lab
//Extra Info: None
/******************************************************/
#include<iostream>
#include<fstream>
#include<string>
#include"classes.h"
#include<cstdlib>
#include<ctime>

using namespace std;

/******************************************************/
// FUNCTION PROTOTYPES
/******************************************************/
card* ReadInCard();
player* ReadInPlayer();
void DisplayMenu();
int Navigation( card*, player* );
card* ShuffleDeck( card* );
void DealDeck( card*, player* );
void PrintDeck( card* );
void PrintStock( card* );
void PrintDiscard( card* );
void PrintPlayerHands( player* pptr );
bool Quit( int );

/******************************************************/
// GLOBAL VARIABLES
/******************************************************/
int numplay = 0;

/******************************************************/
// MAIN
/******************************************************/
int main(){

	srand(time(NULL));

	card* odeck = ReadInCard();

	player* players = ReadInPlayer();

	//testing purposes
	if( odeck[0] < odeck[1] ){
		cout << odeck[0]  << "less than " << odeck[1] << endl;
	}
	if( odeck[0] < odeck[51] ){
		cout << odeck[0]  << "less than " << odeck[51] << endl;
	}
	if( odeck[0] > odeck[1] ){
		cout << odeck[0]  << "more than  " << odeck[1] << endl;
	}
	if( odeck[0] > odeck[51] ){
		cout << odeck[0]  << "more than  " << odeck[51] << endl;
	}

	int choice = 1;

	while( !Quit(choice) ){
		choice = Navigation( odeck, players );
	}

	//testing purposes
	if( odeck[0] < odeck[1] ){
		cout << odeck[0]  << "less than " << endl << odeck[1] << endl;
	}
	if( odeck[0] < odeck[51] ){
		cout << odeck[0]  << "less than " << endl << odeck[51] << endl;
	}
	if( odeck[0] > odeck[1] ){
		cout << odeck[0]  << "more than  " << endl << odeck[1] << endl;
	}
	if( odeck[0] > odeck[51] ){
		cout << odeck[0]  << "more than  " << endl << odeck[51] << endl;
	}

	delete[] odeck;
	delete[] players;
	odeck = NULL;
	players = NULL;

	return 0;
}
/******************************************************/
// END MAIN
/******************************************************/
/******************************************************/
// FUNCTION DEFINITIONS
/******************************************************/
/******************************************************/
//Function: ReadInCard
//Purpose: Read in card/deck array from file
//Parameters: N/A
/******************************************************/
card* ReadInCard(){
	string filename;
	cout << "Enter card file name: " << endl;
	cin >> filename;

	card* Deck = new card[52];

	int ranknum;

	ifstream fin;
	fin.open( filename.c_str() );
		if( fin ){
			for( int i = 0; i < 4; i++ ){
				for( int j = 0; j < 13; j++){
					fin >> Deck[(13*i)+j];
					ranknum = j+1;
					Deck[(13*i)+j].setrankint(ranknum);
				}
				ranknum = 0;
			}
			return Deck;
		}
	else {
		cout << "File not found" << endl;
		Deck = ReadInCard();
		return Deck;
	}
}

/******************************************************/
//Function: ReadInPlayer
//Purpose: Read in player array from file with user input number of players
//Parameters: N/A
/******************************************************/
player* ReadInPlayer(){
	string playerfile;

	cout << "Enter number of players: ";
	cin >> numplay;

	if( !cin ){
		cout << "Input not recognized" << endl;
		player* players = ReadInPlayer();
		return players;
	}

	if( numplay > 8 || numplay < 2 ){
		cout << "Players must be between 2 and 8" << endl;
		player* players = ReadInPlayer();
		return players;
	}
	else{
		cout << "Enter playerfile: ";
		cin >> playerfile;
		player* players = new player[numplay];
		ifstream fin;
		fin.open( playerfile.c_str() );

		if(fin){
			for( int i = 0; i < numplay; i++ ){
				fin >> players[i];
			}
			fin.close();
			return players;
		}
		else {
			cout << "File not found" << endl;
			players = ReadInPlayer();
			return players;
		}
	}
}

/******************************************************/
//Function: DisplayMenu
//Purpose: Output menu text
//Parameters: N/A
/******************************************************/
void DisplayMenu(){
	cout << "---------------------------" << endl;
	cout << "Welcome to 5-Card Draw" << endl;
	cout << "1: Shuffle Deck" << endl;
	cout << "2: Print Deck" << endl;
	cout << "3: Deal Deck" << endl;
	cout << "4: Print Stock" << endl;
	cout << "5: Print Discard" << endl;
	cout << "6: Print Player Hands" << endl;
	cout << "7: Quit" << endl;
	cout << "---------------------------" << endl;
}

/******************************************************/
//Function: Navigation
//Purpose: Navigate through menu system with switch statement
//Parameters: card and player arrays
/******************************************************/
int Navigation( card* Deck, player* Players ){
	DisplayMenu();

	int choice = 0;
	cin >> choice;

	switch (choice){
		case 1:
			Deck = ShuffleDeck( Deck );
			break;
		case 2:
			PrintDeck( Deck );
			break;
		case 3:
			DealDeck( Deck, Players );
			break;
		case 4:
			PrintStock( Deck );
			break;
		case 5:
			PrintDiscard( Deck );
			break;
		case 6:
			PrintPlayerHands( Players );
			break;
		case 7:
			Quit( choice );
			break;
	}
	return choice;
}

/******************************************************/
//Function: ShuffleDeck
//Purpose: Shuffle existing deck
//Parameters: card array
/******************************************************/
card* ShuffleDeck( card* cptr ){
	cout << "Deck Shuffled" << endl;
	cout << "---------------------------" << endl;
	for( int i = 0; i < 52; i++ ){
		int randnum = rand() % 52;
		cptr[i].setlocation("Stock");
		cptr[randnum].setlocation("Stock");
		card tmp = cptr[randnum];
		cptr[randnum] = cptr[i];
		cptr[i] = tmp;
	}
	return cptr;
}

/******************************************************/
//Function: DealDeck
//Purpose: Deal cards to players and move their locations accordingly
//Parameters: card and player arrays
/******************************************************/
void DealDeck( card* cptr, player* pptr ){
	cout << "---------------------------" << endl;
	for( int i = 0; i < 5; i++ ){
		for( int j = 0; j < numplay; j++ ){
			cptr->setlocation( pptr[j].getname() );
			pptr[j].setcard( *cptr, i+1 );
			cptr++;
		}	
		cptr->setlocation( "Discard" );
		cptr++;
	}
	for( int i = 0; i < numplay; i++ ){
		cout << pptr[i];
	}
	cout << "---------------------------" << endl;
}

/******************************************************/
//Function: PrintDeck
//Purpose: Show existing deck configuration
//Parameters: card array
/******************************************************/
void PrintDeck( card* cptr ){
	cout << "---------------------------" << endl;
	cout << "Deck Configuration" << endl;
	cout << "---------------------------" << endl;
	for( int i = 0; i < 52; i++ ){
		cout << cptr[i];
	}
}

/******************************************************/
//Function: PrintStock
//Purpose: Print cards in the stock location
//Parameters: card array
/******************************************************/
void PrintStock( card* cptr ){
	cout << "---------------------------" << endl;
	cout << "Stock Deck" << endl;
	cout << "---------------------------" << endl;
	for( int i = 0; i < 52; i++ ){
		if( cptr[i].getlocation() == "Stock" ){
			cout << cptr[i];
		}
	}
}

/******************************************************/
//Function: PrintDiscard
//Purpose: Print cards in the discard location
//Parameters: card array
/******************************************************/
void PrintDiscard( card* cptr ){
	cout << "---------------------------" << endl;
	cout << "Discard Pile" << endl;
	cout << "---------------------------" << endl;
	for( int i = 0; i < 52; i++ ){
		if( cptr[i].getlocation() == "Discard" ){
			cout << cptr[i];
		}
	}
}

/******************************************************/
//Function: PrintPlayerHands
//Purpose: Print cards and players
//Parameters: player array
/******************************************************/
void PrintPlayerHands( player* pptr ){
	cout << "---------------------------" << endl;
	cout << "Player Hands" << endl;
	cout << "---------------------------" << endl;
	for( int i = 0; i < numplay; i++ ){
		cout << pptr[i];
	}
}

/******************************************************/
//Function: Quit
//Purpose: Return true if quit
//Parameters: number choice
/******************************************************/
bool Quit( int num ){
	if( num == 7 ){
		return true;
	}
	else return false;
}
