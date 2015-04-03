all: project5

project5: project5.cpp symbol.o caylerstring.o
	g++ project5.cpp symbol.o caylerstring.o -o project5

symbol.o: symbol.cpp
	g++ -c symbol.cpp

caylerstring.o: caylerstring.cpp
	g++ -c caylerstring.cpp

clean: 
	rm -rf  *.o  project5
