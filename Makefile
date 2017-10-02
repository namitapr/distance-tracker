all: hw3q5

hw3q5: LLDeque.o hw3q5.cpp
	g++ -g -Wall -std=c++11 LLDeque.cpp hw3q5.cpp -o hw3q5

LLDeque.o: LLDeque.h LLDeque.cpp
	g++ -g -Wall -std=c++11 -c LLDeque.cpp -o LLDeque.o

clean:
	rm LLDeque.o hw3q5