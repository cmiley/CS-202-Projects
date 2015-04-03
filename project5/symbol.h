/******************************************************/
//Name: Cayler Miley
//Program: symbol.h
//Purpose: Header file for symbol class use
//Extra Info: None
/******************************************************/
class symbol {
	private:
		char* name;
		int value;
		bool bonus;
	public:
		symbol();
		symbol( char*, int, bool );
		void setname( char* );
		void getname( char* );
		void setvalue( int );
		int getvalue();
		void setbonus( bool );
		bool getbonus();	
		void print();	
		~symbol();
};
