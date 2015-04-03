/******************************************************/
//Name: Cayler Miley
//Program: classes.cpp
//Purpose: Definitions for symbol and reel classes
//Extra Info: None
/******************************************************/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include"caylerstring.h"
#include"classes.h"

using namespace std;

/******************************************************/
// SYMBOL
/******************************************************/
/******************************************************/
// CONTSTRUCTORS
/******************************************************/
//DEFAULT
symbol:: symbol(){
	name = NULL;
	value = 0;
	bonus = false;
}

//PARAMETERIZED
symbol:: symbol( char* nptr, int val ){
	strcopy(name, nptr);
	value = val;
	if( val > 0 ){
		bonus = true;
	}
	else bonus = false;
}	

//COPY
symbol:: symbol( const symbol &s ){
	strcopy(name, s.name);
	value = s.value;
	if( s.value > 0 ){
		bonus = true;
	}
	else bonus = false;
}

/******************************************************/
// DESTRUCTOR
/******************************************************/
symbol:: ~symbol(){
	delete[] name;
	name = NULL;
	value = 0;
	bonus = false;
}

/******************************************************/
// MEMBER FUNCTIONS
/******************************************************/
/******************************************************/
//Function: getname
//Purpose: return the name of the symbol class
//Parameters: char* destination
/******************************************************/
void symbol:: getname( char* dest )  const {
	strcopy( dest, name );
}

/******************************************************/
//Function: setname
//Purpose: set name in the symbol class
//Parameters: char* source
/******************************************************/
void symbol:: setname( char* n ){
	int l = strlen(n);
	name = new char[l+1];
	strcopy(name, n);
}

/******************************************************/
//Function: getvalue
//Purpose: return the value of the symbol class
//Parameters: N/A
/******************************************************/
int symbol:: getvalue() const {
	return value;
}

/******************************************************/
//Function: setvalue
//Purpose: set the value of the symbol class
//Parameters: number
/******************************************************/
void symbol:: setvalue( int num ){
	value = num;
	if( value > 0 ){
		bonus = true;
	}
	else bonus = false;
}

/******************************************************/
//Function: getbonus
//Purpose: return the bonus value
//Parameters: N/A
/******************************************************/
bool symbol:: getbonus(){
	return bonus;
}

/******************************************************/
//Function: print
//Purpose: print all members of the symbol class
//Parameters: N/A
/******************************************************/
void symbol:: print() const {
	cout << "Name: " << name << ' ';
	cout << "Value: " << value << ' ';
	cout << "Bonus: " << bonus << endl;
}

/******************************************************/
//Function: copy
//Purpose: copy a symbol after it has been initialized
//Parameters: N/A
/******************************************************/
void symbol:: copy( symbol s ){
	int l = strlen(s.name);
	name = new char[l+1];
	char* tmp = new char[20];
	s.getname(tmp);
	strcopy(name, tmp);
	value = s.value;
	bonus = s.bonus;
	delete[] tmp;
}

/******************************************************/
// REEL
/******************************************************/
/******************************************************/
// CONTSTRUCTORS
/******************************************************/
//DEFAULT
reel:: reel(){
	stop = NULL;
	payline = 1;
}

//COPY
reel:: reel( const reel &r ){
	stop = new symbol[10];
	for( int i = 0; i < 10; i++ ){
		stop[i].copy(r.stop[i]);
	}
	payline = r.payline;
}

/******************************************************/
// DESTRUCTOR
/******************************************************/
reel:: ~reel(){
	delete[] stop;
	stop = NULL;
	payline = 0;
}

/******************************************************/
// MEMBER FUNCTIONS
/******************************************************/
/******************************************************/
//Function: SetReel
//Purpose: Set each reel to random symbols
//Parameters: symbol pointer
/******************************************************/
void reel:: setreel( symbol* symsource ){
	int random = 0;
	char* tmp = new char[20];
	stop = new symbol[10];
	for( int i = 0; i < 10; i++ ){
		random = rand() % 6;
		symsource[random].getname(tmp);
		stop[i].setname(tmp);
		stop[i].setvalue( symsource[random].getvalue() );
	}
	delete[] tmp;
}

/******************************************************/
//Function: Spin
//Purpose: simulate spinning a reel by randomly picking a symbol in the array and changing the payline accordingly
//Parameters: N/A
/******************************************************/
symbol reel:: spin(){
	int randsize = rand() % 10;
	payline = randsize;
	return getstop(randsize);
}

/******************************************************/
//Function: printr
//Purpose: print the entire reel
//Parameters: N/A
/******************************************************/
void reel:: printr() const {
	for( int i = 0; i < 10; i++ ){
		stop[i].print();
	}
	cout << "Payline: " << payline << endl;
}

/******************************************************/
//Function: getstop
//Purpose: find a stop in the symbol array
//Parameters: an integer to determine the element of the array
/******************************************************/
symbol reel:: getstop( int size ){
	symbol s;
	char* tmp = new char[20];
	stop[size].getname(tmp);
	int val = stop[size].getvalue();
	s.setname(tmp);
	s.setvalue(val);
	delete[] tmp;
	return s;
}

/******************************************************/
//Function: getpayline
//Purpose: return the current payline
//Parameters: N/A
/******************************************************/
int reel:: getpayline(){
	return payline;
}
