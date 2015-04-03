/******************************************************/
//Name: Cayler Miley
//Program: Project.cpp
//Purpose: Demonstrate slot machine configurations using classes and separate header files
//Extra Info: Include labstring.h and symbol.h (makefile for easy compilation)
/******************************************************/

#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include"caylerstring.h"
#include"symbol.h"

using namespace std;

/******************************************************/
//FUNCTION PROTOTYPES
/******************************************************/

void SymInput( symbol* );
void MenuText();
void MenuNav( symbol*, symbol* );
void SlotGen( symbol*, symbol* );
void PrintSlot( symbol*, symbol* );
void CheckStop( symbol*, symbol* );

/******************************************************/
//BEGIN MAIN FUNCTION
/******************************************************/
int main(){

	symbol* fptr = new symbol[6];
	SymInput( fptr );

	symbol* slotptr = new symbol[10];
	SlotGen( slotptr, fptr );

	delete[] fptr;
	delete[] slotptr;

	fptr = NULL;
	slotptr = NULL;

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
	
	char* symfile;
	symfile = new char[20];
	cout << "Enter an input file: ";
	cin >> symfile;

	ifstream fin;
	fin.open(symfile);

	int num = 0;
	bool bonus = 0;

	if( fin ){
		for( int i = 0; i < 6; i++ ){
			char* tmp = new char[20];
			fin >> tmp;
			(*sptr).setname(tmp);
			fin >> num;
			(*sptr).setvalue(num);
			if( num > 0 ){
				(*sptr).setbonus(1);
			}
			else{
				(*sptr).setbonus(0);
			}
			sptr++;
		}
	}
	else {
		cout << "No input file found" << endl;
		SymInput( sptr );
	}

	fin.close();
}

/******************************************************/
//Function: MenuText
//Purpose: Display menu text
//Parameters: N/A
/******************************************************/
void MenuText(){
	cout << endl;
	cout << "-----------------------------" << endl;
	cout << "Welcome to Cayler's Project 5" << endl;
	cout << "Enter a choice to navigate" << endl;
	cout << "1: Generate a new slot configuration" << endl;
	cout << "2: Print configuration" << endl;
	cout << "3: Check stop" << endl;
	cout << "4: Quit" << endl;
	cout << "-----------------------------" << endl;
}

/******************************************************/
//Function: MenuNav
//Purpose: Navigate through the text menu
//Parameters: choice and reel pointer
/******************************************************/
void MenuNav( symbol* slotconfig, symbol* sptr ){

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
			cout << "Thanks for checking out Cayler's Project 5" << endl;
			break;
		default:
			cout << "Input not recognized" << endl;
			MenuNav( slotconfig, sptr );
			return;
			break;
		}
	}
	else{
		cout << "Input not recognized" << endl;
		cin.clear();
	}
}

void SlotGen( symbol* slotptr, symbol* sptr){
	
	srand((unsigned)time(NULL));
	symbol* symstart = sptr;
	symbol* slotstart = slotptr;
	int randsize = 0;

	for( int i = 0; i < 10; i++ ){
		randsize = rand() % 6;
		
		for( int j = 0; j < randsize; j++ ){
			sptr++;
		}
		
		char* nptr = new char[20];
		(*sptr).getname( nptr );
		int value = (*sptr).getvalue();
		bool bonus = (*sptr).getbonus();
		(*slotptr).setname(nptr);
		(*slotptr).setvalue(value);
		(*slotptr).setbonus(bonus);

		sptr = symstart;
		slotptr++;
	}

	slotptr = slotstart;
	sptr = symstart;

	cout << "-----------------------" << endl;
	cout << "Slot Machine Configured" << endl;
	cout << "-----------------------" << endl;
	
	MenuNav( slotptr, sptr );
}

void PrintSlot( symbol* slotptr, symbol* sptr){

	symbol* slotstart = slotptr;

	cout << "-----------------------" << endl;
	cout << "  Slot Configuration   " << endl;
	cout << "-----------------------" << endl;
	
	for( int i = 0; i < 10; i++ ){
		(*slotptr).print();
		slotptr++;
	}

	slotptr = slotstart;

	MenuNav( slotptr, sptr );

}

void CheckStop( symbol* slotptr, symbol* sptr){

	cout << "-----------------------" << endl;
	cout << "       Check Stop      " << endl;
	cout << "-----------------------" << endl;

	symbol* slotstart = slotptr;
	
	int stopnum = 0;	
	cout << "Enter stop number: ";
	cin >> stopnum;

	if( stopnum < 1 || stopnum > 10 ){
		cout << "Stop must be a number from 1-10" << endl;
		CheckStop( slotptr, sptr );
	}
	else {
		cout << endl;
		cout << "Stop #" << stopnum << ":" << endl;

		for ( int i = 0; i < stopnum-1; i++ ){
			slotptr++;
		}

		(*slotptr).print();

		slotptr = slotstart;

		MenuNav(slotptr, sptr);
	}
}
