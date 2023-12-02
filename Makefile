main: $(wildcard src/*.cpp)
	g++ $(wildcard src/*.cpp) -o main.out