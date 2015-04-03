all: project8

project8: classes.o project8main.cpp
	g++ classes.o project8main.cpp -o project8

classes.o: classes.h classes.cpp
	g++ -c classes.cpp

clean:
	rm -rf *.o project8 *~
