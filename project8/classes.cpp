/******************************************************/
//Name: Cayler Miley
//Program: classes.cpp
//Purpose: define classes for use in project8
//Extra Info: None
/******************************************************/
#include"classes.h"

using namespace std;

/******************************************************/
// CARD CLASS
/******************************************************/
/******************************************************/
// CONTSTRUCTORS
/******************************************************/
//DEFAULT
card:: card( string s, string r, string l, int ri ){
	suit = s;
	rank = r;
	location = location;
	rankint = ri;
}

//COPY
card:: card( const card& c ){
	suit = c.suit;
	rank = c.rank;
	location = c.location;
	rankint = c.rankint;
}

/******************************************************/
// DESTRUCTOR
/******************************************************/
card:: ~card(){
	suit = "suit";
	rank = "rank";
	location = "location";
}

/******************************************************/
// MEMBER FUNCTIONS
/******************************************************/
card& card:: operator=( const card& c ){
	if( this != &c ){
		suit = c.suit;
		rank = c.rank;
		location = c.location;
		rankint = c.rankint;
		return *this;
	}
}

bool card:: operator<( const card& c ){

	if( rankint == c.rankint ){
		if( c.suit == "spade" ){
			return true;
		}
		else if( c.suit == "diamond" && suit != "spade" ){
			return true;
		}
		else if( c.suit == "club" && suit == "heart" ){
			return true;
		}
		else return false;
	}
	else if( rankint < c.rankint ){
		return true;
	}
	else return false;

}

void card:: setlocation( string l ){
	location = l;
}

void card:: setrankint( int r ){
	rankint = r;
}

string card:: getlocation(){
	return location;
}

/******************************************************/
// FRIEND FUNCTIONS
/******************************************************/
ostream& operator<<( ostream& out, card& c ){
	out << c.suit << ' ' << c.rank << ' ' << c.location << ' ' << c.rankint << endl;
	return out;
}

ifstream& operator>>( ifstream& in, card& c ){
	in >> c.suit;
	in >> c.rank;
	c.setlocation( "Stock" );
	return in;
}

bool operator>( const card& c1, const card& c2 ){

	if( c1.rankint == c2.rankint ){
		if( c1.suit == "spade" ){
			return true;
		}
		else if( c1.suit == "diamond" && c2.suit != "spade" ){
			return true;
		}
		else if( c1.suit == "club" && c2.suit == "heart" ){
			return true;
		}
		else return false;
	}
	else if( c1.rankint > c2.rankint ){
		return true;
	}
	else return false;

}

/******************************************************/
// PLAYER CLASS
/******************************************************/
/******************************************************/
// CONTSTRUCTORS
/******************************************************/
//DEFAULT
player:: player( string n, card* hptr, float b ){
	name = n;
	hand = new card[5];
	if( hptr != NULL ){
		for( int i = 0; i < 5; i++ ){
			hand[i] = hptr[i];
		}
	}
	bet = b;
}

//COPY
player:: player( const player& p ){
	name = p.name;
	for( int i = 0; i < 5; i++ ){
		hand[i] = p.hand[i];
	}
	bet = p.bet;
}

/******************************************************/
// DESTRUCTOR
/******************************************************/
player:: ~player(){
	name = "name";
	delete[] hand;
	hand = NULL;
	bet = 0.0;
}

/******************************************************/
// MEMBER FUNCTIONS
/******************************************************/
player& player:: operator=( const player& p ){
	name = p.name;
	for( int i = 0; i < 5; i++ ){
		hand[i] = p.hand[i];
	}
	bet = p.bet;
	return *this;
}

void player:: setcard( card c, int numcard ){
	hand[numcard-1] = c;
}

void player:: setbet( float b ){
	bet = b;
}

string player:: getname(){
	return name;
}

/******************************************************/
// FRIEND FUNCTIONS
/******************************************************/
ostream& operator<<( ostream& out, player& p ){
	out << "Name: " << p.name << endl;
	out << "Cards" << endl;
	out << "------------------" << endl;
	card c;
	for( int i = 0; i < 5; i++ ){
		if( p.hand[i] > c ){
			cout << p.hand[i];
		}
	}
	cout << "Bet:" << p.bet << endl;
	cout << endl;
	return out;
}

ifstream& operator>>( ifstream& in, player& p ){

	string fname;
	string lname;
	in >> fname;
	in >> lname;

	p.name = fname + " " + lname;
	return in;
}
