/******************************************************/
//Name: Cayler Miley
//Program: Project6.cpp
//Purpose: Demonstrate slot machine configurations using classes and separate header files
//Extra Info: Include caylerstring.h and classes.h (makefile for easy compilation)
/******************************************************/
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include"classes.h"

using namespace std;

/******************************************************/
//FUNCTION PROTOTYPES
/******************************************************/
void InFile( reel*, symbol* );
void MenuText();
void MenuNav( reel*, symbol* );
void SlotGen( reel*, symbol* );
void PrintSlot( reel*, symbol* );
void CheckStop( reel*, symbol* );
void Spin( reel*, symbol* );


/******************************************************/
//BEGIN MAIN FUNCTION
/******************************************************/
int main(){

		srand( time(NULL) );

	symbol* filesym = new symbol[6];
	reel* slotmech = new reel[3];
	InFile(slotmech, filesym);

	MenuNav(slotmech, filesym);

	delete[] slotmech;
	delete[] filesym;
	filesym = NULL;
	slotmech = NULL;


	return 0;
}

/******************************************************/
//END MAIN FUNCTION
//BEGIN FUNCTION DEFINITIONS
/******************************************************/

/******************************************************/
//Function: InFile
//Purpose: Input symbols file
//Parameters: reel pointer and symbol pointer
/******************************************************/
void InFile( reel* rptr, symbol* sourcesym ){
	char* filename = new char[20];
	cout << "Enter file name: ";

	cin >> filename;
	ifstream fin;
	fin.open(filename);
	if( fin ){
		char* tmp = new char[20];
		for( int i = 0; i < 6; i++ ){
			fin >> tmp;
			sourcesym[i].setname(tmp);
			int val = 0;
			fin >> val;
			sourcesym[i].setvalue(val);
		}
		
		for( int i = 0; i < 3; i++){
			rptr[i].setreel( sourcesym );
		}
		delete[] tmp;
		fin.close();
		delete[] filename;
		tmp = filename = NULL;
	}
	else {
		cout << "File not found" << endl;
		InFile(rptr, sourcesym);
	}
}

/******************************************************/
//Function: MenuText
//Purpose: Display menu text
//Parameters: N/A
/******************************************************/
void MenuText(){
	cout << endl;
	cout << "-----------------------------" << endl;
	cout << "Welcome to Cayler's Project 6" << endl;
	cout << "Enter a choice to navigate" << endl;
	cout << "1: Generate a new slot configuration" << endl;
	cout << "2: Print configuration" << endl;
	cout << "3: Check stop" << endl;
	cout << "4: Spin to win" << endl;
	cout << "5: Quit" << endl;
	cout << "-----------------------------" << endl;
}

/******************************************************/
//Function: MenuNav
//Purpose: Navigate through the text menu
//Parameters: choice and reel pointer
/******************************************************/
void MenuNav( reel* slotconfig, symbol* sptr ){

	cin.clear();

	MenuText();
	int choice;

	if(cin >> choice){

		switch (choice){
		case 1:
			SlotGen( slotconfig, sptr );
			break;
		case 2:
			PrintSlot( slotconfig, sptr );
			break;
		case 3:
			CheckStop( slotconfig, sptr );
			break;
		case 4:
			Spin( slotconfig, sptr );
			break;
		case 5:
			cout << "Thanks for checking out Cayler's Project 6" << endl;
			break;
		default:
			cout << "Input not recognized" << endl;
			MenuNav( slotconfig, sptr );
			return;
			break;
		}
	}
	else{
		cin.clear();
		cout << "Input not recognized" << endl;
		MenuNav(slotconfig, sptr);
	}
}

/******************************************************/
//Function: SlotGen
//Purpose: Generate a slot machine configuration
//Parameters: reel pointer and symbol pointer
/******************************************************/
void SlotGen( reel* slotconfig, symbol* sourcefile ){
	for( int i = 0; i < 3; i++){
			slotconfig[i].setreel( sourcefile );
	}
	MenuNav(slotconfig, sourcefile);
}

/******************************************************/
//Function: PrintSlot
//Purpose: Print entire slot configuration
//Parameters: reel configuration and symbol pointer
/******************************************************/
void PrintSlot( reel* slotconfig, symbol* sourcefile ){
	char* tmp = new char[20];

	cout << "-----------------------------" << endl;	

	for( int i = 0; i < 10; i++ ){
		for( int j = 0; j < 3; j++ ){
			symbol s = slotconfig[j].getstop(i);
			s.getname(tmp);
			cout << tmp << ' ';
		}
		cout << endl;
	}

	cout << "-----------------------------" << endl;
	MenuNav(slotconfig, sourcefile);
}

/******************************************************/
//Function: CheckStop
//Purpose: Check the symbol at a specific stop
//Parameters: reel and symbol pointers
/******************************************************/
void CheckStop( reel* slotconfig, symbol* sourcefile ){
	symbol s;
	cout << "-----------------------------" << endl;
	cout << "Enter a row: ";
	int row = 0;
	if( cin >> row ){
		if( row > 10 || row < 1 ){
			cout << "Enter a row from 1-10" << endl;
			CheckStop(slotconfig, sourcefile);
			return;
		}
		else{
			row--;
			int col = 0;
			cout << "Enter a column: ";
			if( cin >> col ){
				if( col > 3 || col < 1 ){
					cout << "Column must be from 1-3" << endl;
					CheckStop(slotconfig, sourcefile);	
					return;
				}
				else {
					col--;
					symbol s;
					s.copy( slotconfig[col].getstop(row) );
					s.print();
					cout << "-----------------------------" << endl;
					MenuNav(slotconfig, sourcefile);
				}
			}
			else {
				cin.clear();
				cout << "Input not recognized" << endl;
				CheckStop(slotconfig, sourcefile);
				return;
			}
		}
	}
	else {
		cin.clear();
		cout << "Input not recognized" << endl;
		CheckStop(slotconfig, sourcefile);
		return;
	}
}

/******************************************************/
//Function: Spin
//Purpose: Spin reels and display paylines for each
//Parameters: reel and symbol pointers
/******************************************************/
void Spin( reel* rptr, symbol* sptr ){
	symbol* s = new symbol[3];
	char* tmp = new char[20];

	cout << "-----------------------------" << endl;
	
	for( int i = 0; i < 3; i++ ){
		s[i].copy(rptr[i].spin());
		s[i].getname(tmp);
		cout << tmp << ' ';
		cout << "PayL: " << rptr[i].getpayline()+1 << ' ';
	}

	cout << endl;
	cout << "-----------------------------" << endl;

	MenuNav(rptr, sptr);
}
