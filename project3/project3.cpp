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

struct reel {
	symbol stop[10];
	int payline;
};

/******************************************************/
//FUNCTION PROTOTYPES
/******************************************************/

void SymInput( symbol* );
void SymCopy( symbol*, symbol* );
void MenuNav( reel*, symbol* );
void SlotGen( reel*, symbol* );
void PrintSlot( reel*, symbol* );
void CheckStop( reel*, symbol* );
void strcopy( char*, char* );
bool strcomp( char*, char* );

/******************************************************/
//BEGIN MAIN FUNCTION
/******************************************************/
int main(){

	srand((unsigned)time(NULL));
	
	int choice = 1;
	symbol placeholder[6];
	reel slot[3];
	reel* rptr = slot;
	symbol* sptr = placeholder;
	SymInput( sptr );

	SlotGen( rptr, sptr );

	return 0;
}

/******************************************************/
//END MAIN FUNCTION
//BEGIN FUNCTION DEFINITIONS
/******************************************************/

/******************************************************/
//Function: SymInput
//Purpose: Input symbols file
//Parameters: symbol pointer
/******************************************************/
void SymInput( symbol* sptr ){
	
	char symfile[20];
	cout << "Enter an input file: ";
	cin >> symfile;
	char correct[15] = "symbols";
	char* cptr = correct;
	char* symptr = symfile;

	if( !strcomp( cptr, symptr ) ){
		cout << "Wrong file" << endl;
		cout << "Enter 'symbols' " << endl;
		SymInput( sptr );
	}

	symbol* start = sptr;
	ifstream fin;
	fin.open(symfile);

	for(int i = 0; i < 6; i++){
		fin >> (*sptr).name;
		fin >> (*sptr).value;
		if( (*sptr).value > 0 ){
			(*sptr).bonus = 1;
		}
		else (*sptr).bonus = 0;
		sptr++;
	}

	sptr = start;

	fin.close();
}

/******************************************************/
//Function: SymCopy
//Purpose: Copy symbol properties to another symbol
//Parameters: destination and source symbols
/******************************************************/
void SymCopy( symbol* dest, symbol* source ){
	char* nptrdest = (*dest).name;
	char* nptrsource = (*source).name;
	strcopy( nptrdest, nptrsource );
	(*dest).value = (*source).value;
	(*dest).bonus = (*source).bonus;
}

/******************************************************/
//Function: MenuText
//Purpose: Display menu text
//Parameters: N/A
/******************************************************/
void MenuText(){
	cout << "Welcome to Cayler's Project 3" << endl;
	cout << "Enter a choice to navigate" << endl;
	cout << "1: Generate a new slot configuration" << endl;
	cout << "2: Print configuration" << endl;
	cout << "3: Check stop" << endl;
	cout << "4: Quit" << endl << endl;
}

/******************************************************/
//Function: MenuNav
//Purpose: Navigate through the text menu
//Parameters: choice and reel pointer
/******************************************************/
void MenuNav( reel* rptr, symbol* sptr ){

	MenuText();
	int choice;

	if(cin >> choice){

		switch (choice){
		case 1:
			SlotGen( rptr, sptr );
			break;
		case 2:
			PrintSlot( rptr, sptr );
			break;
		case 3:
			CheckStop( rptr, sptr );
			break;
		case 4:
			cout << "Thanks for checking out Cayler's Project 3" << endl;
			break;
		default:
			cout << "Input not recognized" << endl;
			MenuNav( rptr, sptr );
			return;
			break;
		}
	}
	else{
		cout << "Input not recognized" << endl;
		cin.clear();
	}
}

/******************************************************/
//Function: SlotGen
//Purpose: Populate Slot Machine
//Parameters: reel pointer
/******************************************************/
void SlotGen( reel* rptr, symbol* sptr ){

	srand((unsigned)time(NULL));

	symbol* symstart = sptr;
	reel* rstart = rptr;
	symbol* stopptr;

	for( int k = 0; k < 3; k++ ){

		stopptr = (*rptr).stop;

		for( int i = 0; i < 10; i++ ){
			int randsize = rand() % 6; //Calculates random distance from starting pointer
			
				for( int j = 0; j < randsize; j++ ){
					sptr++;
				}

			SymCopy( stopptr, sptr );

			stopptr++;
			sptr = symstart;
			(*rptr).payline = i;
		}
		rptr++;
	}

	rptr = rstart;

	rptr = rstart;
	sptr = symstart;

	cout << "Configuration generated" << endl << endl;
	
	MenuNav( rptr, sptr );
}

/******************************************************/
//Function: PrintSlot
//Purpose: Print slot configuration
//Parameters: reel pointer
/******************************************************/
void PrintSlot( reel* rptr, symbol* sptr ){

	cout << endl << "Slot Configuration" << endl;
	cout << "-------------------------------------" << endl;

	reel* rstart = rptr;
	symbol* nptr = (*rptr).stop;

	for(int k = 0; k < 10; k++ ){
		for( int i = 0; i < 3; i++){
			nptr = (*rptr).stop;
			for( int j = 0; j < k; j++){
				nptr++;
			}
			cout << (*nptr).name << ' ';
			rptr++;
		}
		cout << endl;
		rptr = rstart;
	}

	cout << endl << endl << endl;

	rptr = rstart;

	MenuNav( rptr, sptr );
}

/******************************************************/
//Function: SlotCheck
//Purpose: Check a stop at a location: row and column
//Parameters: reel pointer for slot config
/******************************************************/
void CheckStop( reel* rptr, symbol* sptr ){

	int row;
	int col;
	reel* rstart = rptr;

	cout << "Enter a row and column" << endl;
	cout << "Row: ";
	cin >> row;
	if( row < 1 || row > 10 ){
		cout << "Row must be 1 thru 10" << endl;
		CheckStop( rptr, sptr );
	}
	row--;

	cout << "Column: ";
	cin >> col;
	if( col < 1 || col > 3 ){
		cout << "Column must be 1 thru 3" << endl;
		CheckStop( rptr, sptr );
	}
	col--;

	for( int i = 0; i < col; i++ ){
		rptr++;
	}
	
	symbol* symptr = (*rptr).stop;
	for( int i = 0; i < row; i++ ){
		symptr++;
	}

	cout << endl << endl;

	cout << (*symptr).name << ' ';
	cout << (*symptr).value << ' ';
	cout << (*symptr).bonus << endl;

	cout << endl;

	rptr = rstart;

	MenuNav( rptr, sptr );
}

/******************************************************/
//Function: String copy
//Purpose: Copy a c-style string to a destination string
//Parameters: destination and source strings
/******************************************************/
void strcopy( char* dest, char* source ){
	char* deststart = dest;
	char* sourcestart = source;

	char sourceletter = (*source);
	
	while( sourceletter != '\0' ){
		(*dest) = sourceletter;
		dest++;
		source++;
		sourceletter = (*source);
	}
	(*dest) = '\0';	
}

/******************************************************/
//Function: String Compare
//Purpose: Return true for 2 strings that are equivalent and false if not
//Parameters: 2 c-style strings
/******************************************************/
bool strcomp( char* string1, char* string2 ){
	bool charcomp = true;
	char s1letter = (*string1);
	char s2letter = (*string2);
	char* s1start = string1;
	char* s2start = string2;

	while( s1letter != '\0' ){
		if( s1letter == s2letter ){
			string1++;
			string2++;

			s1letter = (*string1);
			s2letter = (*string2);
			if( s1letter == '\0' && s2letter == s1letter ){
				string1 = s1start;
				string2 = s2start;
				return true;
			}
		}
		else{
			string1 = s1start;
			string2 = s2start;
			return false;
		}
	}
}
