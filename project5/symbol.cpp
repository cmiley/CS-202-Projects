/******************************************************/
//Name: Cayler Miley
//Program: symbol.cpp
//Purpose: Definitions for symbol class
//Extra Info: None
/******************************************************/
#include<iostream>
#include"symbol.h"
#include"caylerstring.h"

/******************************************************/
// CONTSTRUCTORS
/******************************************************/
//DEFAULT
symbol:: symbol(void){
	name = NULL;
	value = 0;
	bonus = 0;
}

//PARAMETERIZED
symbol:: symbol( char* nptr, int num, bool bon ){
	setname( nptr );
	setvalue( num );
	setbonus( bon );
}

/******************************************************/
//Function: setname
//Purpose: set name element of symbol class to char* parameter
//Parameters: char* nptr
/******************************************************/
void symbol:: setname( char* nptr ){
	char* tmp = new char[15];
	strcopy( tmp, nptr );
	int len = strlen( tmp );
	name = new char[len+1];
	strcopy( name, nptr );
}

/******************************************************/
//Function: getname
//Purpose: return the name of the symbol class
//Parameters: char* destination
/******************************************************/
void symbol:: getname( char* dest ){
	strcopy( dest, name );
}

/******************************************************/
//Function: setvalue
//Purpose: set the bonus value for element the symbol class
//Parameters: number int
/******************************************************/
void symbol:: setvalue( int num ){
	value = num;
}

/******************************************************/
//Function: getvalue
//Purpose: return the bonus value of the symbol class element
//Parameters: N/A
/******************************************************/
int symbol:: getvalue(){
	return value;
}

/******************************************************/
//Function: setbonus
//Purpose: set the bonus boolean value of the symbol class
//Parameters: bool
/******************************************************/
void symbol:: setbonus( bool bon ){
	bonus = bon;
}

/******************************************************/
//Function: getvalue
//Purpose: return the boolean bonus of the symbol class element
//Parameters: N/A
/******************************************************/
bool symbol:: getbonus(){
	return bonus;
}

/******************************************************/
//Function: print
//Purpose: print all elements of the symbol class
//Parameters: N/A
/******************************************************/
void symbol:: print(){
	cout << name << ' ' << value << ' ' << bonus << ' ' << endl;
}

/******************************************************/
// DESTRUCTOR
/******************************************************/
symbol:: ~symbol(){
	delete[] name;
	setvalue( 0 );	
	setbonus( 0 );
}
