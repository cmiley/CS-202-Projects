/******************************************************/
//Name: Cayler Miley
//Program: triangle.cpp
//Purpose: Demonstrate use of existing header files and overloaded operators
//Extra Info: None
/******************************************************/
#include "triangle.h"

using namespace std;

/******************************************************/
// TRIANGLE CLASS
/******************************************************/
/******************************************************/
// CONTSTRUCTORS
/******************************************************/
//DEFAULT
triangle:: triangle(int b, int h){
	base = b;
	height = h;
	area = (.5)*b*h;
}

//COPY
triangle:: triangle(const triangle &t){
	base = t.base;
	height = t.height;
	area = t.area;
}

/******************************************************/
// DESTRUCTOR
/******************************************************/
triangle:: ~triangle(){
	base = 0;
	height = 0;
	area = 0;
}

/******************************************************/
// MEMBER FUNCTIONS
/******************************************************/
/******************************************************/
//Function: triangle copy using '=' operator
//Purpose: copy triangle
//Parameters: constant triangle reference
/******************************************************/
triangle& triangle:: operator=(const triangle &t){
	if( this != &t ){
		base = t.base;
		height = t.height;
		area = t.area;
		return *this;
	}
}

/******************************************************/
//Function: check equality with '==' operator
//Purpose: check if two triangles are equal
//Parameters: constant triangle reference
/******************************************************/
bool triangle:: operator==(const triangle &t) const{
	bool b = 0;
	bool h = 0;
	bool a = 0;

	if(t.base == base){
		b = true;
	}
	if(t.height == height){
		h = true;
	}
	if(t.area == area && area == (.5)*base*height){
		a = true;
	}

	if(b && h && a){
		return true;
	}
	else return false;
}

/******************************************************/
//Function: add two triangles with '+' operator
//Purpose: add triangles to result in new triangle
//Parameters: 2 constant triangle references
/******************************************************/
triangle operator+(const triangle &t1, const triangle &t2){
	int b = t1.base+t2.base;
	int h = t1.height+t2.height;
	triangle t(b,h);
	return t;
}

/******************************************************/
//Function: send members of triangle to output stream using '<<' operator
//Purpose: output members of a triangle to the console
//Parameters: output stream reference and triangle reference
/******************************************************/
ostream& operator<<(ostream &cout, triangle &t){
	cout << "Base: " << t.base << ' ';
	cout << "Height: " << t.height << ' ';
	cout << "Area: " << t.area << ' ';
}

/******************************************************/
//Function: input triangle from file stream using '>>' operator
//Purpose: readin a triangle from a file
//Parameters: input file stream reference and triangle reference
/******************************************************/
ifstream& operator>>(ifstream &fin, triangle &t){
	fin >> t.base;
	fin >> t.height;
	t.area = (.5)*t.base*t.height;
}
