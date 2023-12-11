main: $(wildcard src/*.cpp)
	g++ -g $(wildcard src/*.cpp) -o main.out