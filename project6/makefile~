all: project6

project6: project6.cpp classes.o caylerstring.o
	g++ project6.cpp classes.o caylerstring.o -o project6

classes.o: classes.cpp
	g++ -c classes.cpp

caylerstring.o: caylerstring.cpp
	g++ -c caylerstring.cpp

clean:
	rm -rf *.o project6
