debug:
	g++ -c src/*.cpp -std=c++20 -m64 -g -Wall -I include
	g++ *.o -o bin/debug/template -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lGL
	./bin/debug/template

release:
	g++ -c src/*.cpp -sdt=c++20 -m64 -I include
	g++ *.o -o bin/release/template -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
	./bin/release/template

setup:
	mkdir -p bin/debug bin/release

clean:
	rm *.o bin/debug/template bin/release/template *.log
