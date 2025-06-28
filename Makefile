debug:
	g++ -c src/*.cpp -std=c++20 -m64 -g -Wall -I include
	g++ *.o -o bin/debug/template -lSDL2 -lSDL2_image -lSDL2_ttf
	./bin/debug/template

clean:
	rm *.o bin/debug/template bin/release/template