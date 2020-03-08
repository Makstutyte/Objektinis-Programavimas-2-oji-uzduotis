main: funkcijos.o
	g++ -o test main.cpp funkcijos.o
funkcijos:
	g++ -c funkcijos.cpp