/******************************************************/
//Name: Cayler Miley
//Program: Project2.cpp
//Purpose: Demonstrate slot machine configurations
//Extra Info: None
/******************************************************/

#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>

using namespace std;

/******************************************************/
//STRUCTS AND CLASSES
/******************************************************/

struct symbol {
	char name[15];
	int value;
	bool bonus;
};

struct slot {
	symbol stop[10];
	int payline;
};
	
/******************************************************/
//FUNCTION PROTOTYPES
/******************************************************/

void SymCopy( symbol &, symbol & );
void SymInput( char symbol[][2][10] );
void MenuText();
bool MenuNav( int &choice, slot reel[] );
void SlotGen( int &choice, slot reel[] );
void ReadIn( int &choice, slot reel[] );
void ScreenPrint( int &choice, slot reel[] );
void FilePrint( int &choice, slot reel[]);
void FindStop( int &choice, slot reel[] );
void Gamble( int &choice, slot reel[] );
void strcopy( char[], char[] );
bool strcomp( char[], char[] );
void strcat( char[], char[], char[] );

/******************************************************/
//BEGIN MAIN FUNCTION
/******************************************************/
int main(){

	srand((unsigned)time(NULL));

	int choice = 1;
	slot reel[3];

	SlotGen( choice, reel );

	while(!MenuNav( choice, reel ));

	return 0;
}
/******************************************************/
//END MAIN FUNCTION
//BEGIN FUNCTION DEFINITIONS
/******************************************************/

/******************************************************/
//Function: SymCopy
//Purpose: Copy all the elements of the symbol struct to another symbol
//Parameters: destination symbol and source symbol
/******************************************************/
void SymCopy( symbol &destsym, symbol &sourcesym ){
	//cout << sym.name << ' ' << sym.value << ' ' << sym.bonus << endl;
	strcopy( destsym.name, sourcesym.name );
	destsym.value = sourcesym.value;
	destsym.bonus = sourcesym.bonus;
}

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

	cout << "Welcome to Cayler's Project 2" << endl;
	cout << "------------------------------" << endl;
	cout << "Press to navigate: " << endl;
	cout << "1: Generate new slot machine" << endl;
	cout << "2: Read-in existing configuration" << endl;
	cout << "3: Print configuration to screen" << endl;
	cout << "4: Print configuration to file" << endl;
	cout << "5: Check specific stop" << endl;
	cout << "6: Gamble" << endl;
	cout << "7: Quit" << endl;
	cout << "Enter only an integer from 1-6" << endl;

}

/******************************************************/
//Function: MenuNav
//Purpose: Allow for Menu navigation with switch statements
//Parameters: menu choice and existing slot configuration
/******************************************************/
bool MenuNav( int &choice, slot reel[] ){

	MenuText();

	cin >> choice;

	switch(choice){
		case 1:
			SlotGen( choice, reel );
			return false;
			break;
		case 2:
			ReadIn( choice, reel );
			return false;
			break;
		case 3:
			ScreenPrint( choice, reel );
			return false;
			break;
		case 4:
			FilePrint( choice, reel );
			return false;
			break;
		case 5:
			FindStop( choice, reel );
			return false;
			break;
		case 6:
			Gamble( choice, reel );
			return false;
			break;
		case 7:
			cout << "Thank you for viewing Cayler's Project 2" << endl;
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
void SlotGen( int &choice, slot reel[] ){
	cout << endl << endl << "Slot Machine Generated" << endl << endl;

	char symarray[6][2][15];
	int randomrow = 0;
	int randomcol = 0;
	char name[6][15];
	int value[6];

	SymInput( symarray );

	for(int i = 0; i < 6; i++){
		strcopy( name[i], symarray[i][0] );
		value[i] = atoi(symarray[i][1]);
	}
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 10; j++){
			randomrow = rand() % 6;
			strcopy( reel[i].stop[j].name, name[randomrow] );
			reel[i].stop[j].value = value[randomrow];
			if( reel[i].stop[j].value != 0 ){
				reel[i].stop[j].bonus = true;
			}
			else reel[i].stop[j].bonus = false;
		}
	} 
}

/******************************************************/
//Function: Read In
//Purpose: Read in input file with slot configuration to change existing slot configuration
//Parameters: menu choice and existing slot configuration
/******************************************************/
void ReadIn( int &choice, slot reel[] ){
	char infile[25];
	cout << endl << endl << "Enter name of input file:";
	cin >> infile;
	ifstream fin;
	fin.open(infile);

	if( fin.is_open() ){
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 3; j++){
				fin >> reel[j].stop[i].name;
				fin >> reel[j].stop[i].value;
			}
		}
	}
	else{
		cout << endl << endl << "File doesn't exist" << endl << endl;
		ReadIn( choice, reel );
	}

	fin.close();
	
}

/******************************************************/
//Function: Screen Print
//Purpose: Print existing slot configurationt to the screen
//Parameters: menu choice and existing slot configuration
/******************************************************/
void ScreenPrint( int &choice, slot reel[] ){
	cout << endl << endl << "Slot Machine Configuration:" << endl << endl;

	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 3; j++){
			cout << reel[j].stop[i].name << ' ' << reel[j].stop[i].value << ' ';
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
void FilePrint( int &choice, slot reel[] ){
	
	char outfile[25];

	ofstream fout;
	cout << endl << endl;
	cout << "Enter a filename: ";
	cin >> outfile;
	fout.open(outfile);

	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 3; j++){
			fout << reel[j].stop[i].name << ' ' << reel[j].stop[i].value << ' ';
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
void FindStop( int &choice, slot reel[] ){

	int row = 0;
	int col = 0;

	cout << "Enter row: ";
	cin >> row;

	if( row > 10 || row < 1 ){
		cout << "Row must be less than 11 and greater than 0" << endl;
		FindStop (choice, reel);
	}
	else{	

		row -= 1;

		cout << "Enter column: ";
		cin >> col;

		if( col > 3 || col < 1 ){
			cout << "Column must be less than 4 and greater than 0" << endl;
			FindStop (choice, reel);
		}	
		else{

			col -= 1;

			cout << "Stop at row:" << row+1 << " column:" << col+1 << " is: " << endl << endl;
			cout << reel[col].stop[row].name << " Value: " << reel[col].stop[row].value << endl << endl;
		}
	}
}

void Gamble( int &choice, slot reel[] ){

	srand((unsigned)time(NULL));

	cout << endl << endl << "Payline 1 -------------------";
	cout << endl << "Payline 2 -------------------" << endl;
	cout << "Payline 3 -------------------";

	int payline = 0;
	cout << endl << endl << "Choose payline: ";
	cin >> payline;

	if(payline > 4 || payline < 1){
		cout << "Payline must an integer from 1-3" << endl;
		cout << "Choose payline: ";
		cin >> payline;
	}

	cout << endl;

	payline -= 1;

	symbol paysymbol[3][3];

	int randindex = 0;
	int paybonus = 0;

	for(int i = 0; i < 3; i++){
		randindex = rand() % 10;
		if(randindex == 0){
			SymCopy( paysymbol[i][0], reel[i].stop[9] );
			SymCopy( paysymbol[i][1], reel[i].stop[randindex] );
			SymCopy( paysymbol[i][2], reel[i].stop[randindex+1] );

			paybonus = paysymbol[i][payline].value + paybonus;
		}
		else if(randindex == 9){
			SymCopy( paysymbol[i][0], reel[i].stop[randindex-1] );
			SymCopy( paysymbol[i][1], reel[i].stop[randindex] );
			SymCopy( paysymbol[i][2], reel[i].stop[0] );

			paybonus = paysymbol[i][payline].value + paybonus;
		}
		else{
			SymCopy( paysymbol[i][0], reel[i].stop[randindex-1] );
			SymCopy( paysymbol[i][1], reel[i].stop[randindex] );
			SymCopy( paysymbol[i][2], reel[i].stop[randindex+1] );

			paybonus = paysymbol[i][payline].value + paybonus;
		}	
	}

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout << paysymbol[j][i].name << ' ';
		}
			cout << endl;
	}	

	cout << endl <<"Payline: " << payline+1 << endl << endl;

	cout << paysymbol[0][payline].name << ' ';
	cout << paysymbol[1][payline].name << ' ';
	cout << paysymbol[2][payline].name << ' ';
	cout << "Bonus: " << paybonus << endl << endl;

	char cherry[] = "cherry";

	if( strcomp(paysymbol[payline][0].name, paysymbol[payline][1].name ) > 0 && 
	strcomp(paysymbol[payline][0].name, paysymbol[payline][2].name ) > 0 ){
		cout << "You Win!" << endl;
	}
	else if( strcomp( cherry, paysymbol[payline][0].name) > 0 ||
	strcomp( cherry, paysymbol[payline][1].name) > 0 ||
	strcomp( cherry, paysymbol[payline][2].name) > 0 ){
		cout << "You win a small prize!" << endl;
	}
	else{
		cout << "Try again!" << endl;
	}

	cout << endl;
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

