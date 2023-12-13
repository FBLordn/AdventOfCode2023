main: $(wildcard src/*.cpp)
	g++ -O3 $(wildcard src/*.cpp) -o main.out