# currently just compiles and runs main.cpp and GameManager.cpp

all:
	g++ -std=c++11 -Wall -Wextra -Iinclude main.cpp src/GameManager.cpp -o program
	./program

.PHONY: all