main: funkcijos.o funkcijos_vector.o funkcijos_list.o funkcijos_deque.o
	g++ -o test main.cpp funkcijos.o funkcijos_vector.o funkcijos_list.o funkcijos_deque.o
funkcijos:
	g++ -c funkcijos.cpp 
funkcijos_vector:
	g++ -c funkcijos_vector.cpp
funkcijos_list:
	g++ -c funkcijos_list.cpp
funkcijos_deque:
	g++ -c funkcijos_deque.cpp
