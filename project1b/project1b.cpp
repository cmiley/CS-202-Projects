/******************************************************/
//Name: Cayler Miley
//Program: Project1b.cpp
//Purpose: Demonstrate slot machine configurations
//Extra Info: None
/******************************************************/

#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>

using namespace std;

/******************************************************/
//FUNCTION PROTOTYPES
/******************************************************/
void SymInput( char symbol[][2][10] );
void MenuText();
bool MenuNav( int &choice, char[][3][15] );
void SlotGen( int &choice, char[][3][15] );
void ReadIn( int &choice, char[][3][15] );
void ScreenPrint( int &choice, char[][3][15] );
void FilePrint( int &choice, char[][3][15] );
void FindStop( int &choice, char[][3][15] );
void strcopy( char[], char[] );
bool strcomp( char[], char[] );
void strcat( char[], char[], char[] );

/******************************************************/
//BEGIN MAIN FUNCTION
/******************************************************/
int main(){

	int choice = 1;
	srand((unsigned)time(NULL));
	bool quit = false;

	//Allocate array for reels
	char slotmech[10][3][15];

	//Initialize a default configuration for the slot machine
	SlotGen( choice, slotmech );

	MenuNav( choice, slotmech );
	while( choice != 7 ){
		MenuNav( choice, slotmech );
	}

	return 0;
}
/******************************************************/
//END MAIN FUNCTION
//BEGIN FUNCTION DEFINITIONS
/******************************************************/

/******************************************************/
//Function: SymInput
//Purpose: Input symbols file
//Parameters: symbol array
/******************************************************/
void SymInput( char symbol[6][2][15] ){
	
	char symfile[] = "symbols";

	ifstream fin;
	fin.open(symfile);

	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 2; j++){
			fin >> symbol[i][j];
		}
	}

	fin.close();

}

/******************************************************/
//Function: MenuText
//Purpose: Display text for menu navigation and options
//Parameters: None
/******************************************************/
void MenuText(){

	cout << "Welcome to Cayler's Project 1b" << endl;
	cout << "------------------------------" << endl;
	cout << "Press to navigate: " << endl;
	cout << "1: Generate new slot machine" << endl;
	cout << "2: Read-in existing configuration" << endl;
	cout << "3: Print configuration to screen" << endl;
	cout << "4: Print configuration to file" << endl;
	cout << "5: Check specific stop" << endl;
	cout << "6: Quit" << endl;
	cout << "Enter only an integer from 1-6" << endl;

}

/******************************************************/
//Function: MenuNav
//Purpose: Allow for Menu navigation with switch statements
//Parameters: menu choice and existing slot configuration
/******************************************************/
bool MenuNav( int &choice, char slotmech[10][3][15] ){

	MenuText();

	cin >> choice;

	switch(choice){
		case 1:
			SlotGen( choice, slotmech );
			return false;
			break;
		case 2:
			ReadIn( choice, slotmech );
			return false;
			break;
		case 3:
			ScreenPrint( choice, slotmech );
			return false;
			break;
		case 4:
			FilePrint( choice, slotmech );
			return false;
			break;
		case 5:
			FindStop( choice, slotmech );
			return false;
			break;
		case 6:
			cout << "Thank you for viewing Cayler's Project 1b" << endl;
			choice = 7;
			return true;
			break;
		default:
			cout << endl << endl << "Enter an integer 1-6" << endl << endl;
			choice = 7;
			return false;
			//break;
	}
}

/******************************************************/
//Function: SlotGen	
//Purpose: Generate random slot machine configuration
//Parameters: menu choice and existing slot configuration
/******************************************************/
void SlotGen( int &choice, char slotmech[10][3][15] ){
	cout << endl << endl << "Slot Machine Generated" << endl << endl;

	char symbol[6][2][15];
	int randomrow = 0;
	int randomcol = 0;
	char randsym[6][25];

	SymInput( symbol );

	for(int i = 0; i < 6; i++){
		strcat( symbol[i][0], symbol[i][1], randsym[i] );
	}
	
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 3; j++){
			randomrow = rand() % 6;
			strcopy( slotmech[i][j], randsym[randomrow] );
		}
	} 
}

/******************************************************/
//Function: Read In
//Purpose: Read in input file with slot configuration to change existing slot configuration
//Parameters: menu choice and existing slot configuration
/******************************************************/
void ReadIn( int &choice, char slotmech[10][3][15] ){
	char infile[25];
	cout << endl << endl << "Enter name of input file:";
	cin >> infile;
	ifstream fin;
	fin.open(infile);

	if( fin.is_open() ){
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 3; j++){
				fin >> slotmech[i][j];
			}
		}
	}
	else{
		cout << endl << endl << "File doesn't exist" << endl << endl;
		ReadIn( choice, slotmech );
	}

	fin.close();
	
}

/******************************************************/
//Function: Screen Print
//Purpose: Print existing slot configurationt to the screen
//Parameters: menu choice and existing slot configuration
/******************************************************/
void ScreenPrint( int &choice, char slotmech[10][3][15] ){
	cout << endl << endl << "Slot Machine Configuration:" << endl << endl;

	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 3; j++){
			cout << slotmech[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl << endl;
}

/******************************************************/
//Function: File Print
//Purpose: Print slot configuration to file (in the same format required for input file)
//Parameters: menu choice and existing slot configuration
/******************************************************/
void FilePrint( int &choice, char slotmech[10][3][15] ){
	
	char outfile[25];

	ofstream fout;
	cout << endl << endl;
	cout << "Enter a filename: ";
	cin >> outfile;
	fout.open(outfile);

	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 3; j++){
			fout << slotmech[i][j] << ' ';
		}
		fout << endl;
	}

	fout.close();

	cout << endl << endl << "File: " << outfile << "created" << endl << endl;
}

/******************************************************/
//Function: Find Stop
//Purpose: Find a specific stop at a location
//Parameters: menu choice and existing slot configuration
/******************************************************/
void FindStop( int &choice, char slotmech[10][3][15] ){

	int row = 0;
	int col = 0;

	cout << "Enter row: ";
	cin >> row;

	if( row > 10 || row < 1 ){
		cout << "Row must be less than 11 and greater than 0" << endl;
		FindStop (choice, slotmech);
	}
	else{	

		row -= 1;

		cout << "Enter column: ";
		cin >> col;

		if( col > 3 || col < 1 ){
			cout << "Column must be less than 4 and greater than 0" << endl;
			FindStop (choice, slotmech);
		}	
		else{

			col -= 1;

			cout << "Stop at row:" << row+1 << " column:" << col+1 << " is: " << endl << endl;
			cout << slotmech[row][col] << endl << endl;
		}
	}
}

/******************************************************/
//Function: String copy
//Purpose: Copy a c-style string to a destination string
//Parameters: destination and source strings
/******************************************************/
void strcopy( char dest[], char source[] ){
	int i = 0;
	while( source[i] != '\0' ){
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';	
}

/******************************************************/
//Function: String Compare
//Purpose: Return true for 2 strings that are equivalent and false if not
//Parameters: 2 c-style strings
/******************************************************/
bool strcomp( char string1[], char string2[] ){
	bool charcomp = true;
	int i = 0;
	while( charcomp ){
		if( string1[i] == string2[i] ){
			i++;
			if( string1[i] == '\0' && string2[i] == string1[i] ){
				return true;
			}
		}
		else return false;
	}
}

/******************************************************/
//Function: String Concatonate
//Purpose: Copy 2 discrete strings to a single destination string
//Parameters: 2 source strings (first and second) and destination string
/******************************************************/
void strcat( char first[], char second[], char dest[] ){
	int i = 0;	
	while( first[i] != '\0' ){
		dest[i] = first[i];
		i++;
	}

	dest[i] = ' ';

	int j = 0;
	while( second[j] != '\0' ){
		dest[i] = second[j];

		i++;
		j++;

	}

	dest[i] = '\0';
}

