/******************************************************/
//SYMBOL CLASS
/******************************************************/
class symbol {
	public:
		symbol();
		symbol( char* nptr, int ); //parametrized constructor
		symbol( const symbol& ); //copy constructor
		~symbol(); //destructor
		void getname( char* ) const;
		void setname( char* );
		int getvalue() const;
		void setvalue( int );
		bool getbonus();
		void print() const;
		void copy( symbol );
	private:
		char* name;
		int value;
		bool bonus;		
};

/******************************************************/
//REEL CLASS
/******************************************************/
class reel {
	public:
		reel();
		reel( const reel& );
		~reel();
		void setreel( symbol* );
		void printr() const;
		symbol spin();
		symbol getstop( int );
		int getpayline();
	private:
		symbol* stop;
		int payline;
};
