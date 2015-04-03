#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class card {
	public:
		card( string = "suit", string = "rank", string = "location", int = 0 );
		card( const card& );
		~card();
		card& operator=( const card& );
		bool operator<( const card& );
		void setlocation( string );
		void setrankint( int );
		string getlocation();

		friend ostream& operator<<( ostream&, card& );
		friend ifstream& operator>>( ifstream&, card& );
		friend bool operator>( const card&, const card& );
	private:
		string suit;
		string rank;
		string location;
		int rankint;
};

class player {
	public:
		player( string = "first last", card* = NULL, float = 0.0 );
		player( const player& );
		~player();
		player& operator=( const player& );
		void setcard( card, int );
		void setbet( float );
		string getname();

		friend ostream& operator<<( ostream&, player& );
		friend ifstream& operator>>( ifstream&, player& );
	private:
		string name;
		card* hand;
		float bet;		
};
