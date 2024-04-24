build:
	gcc -Wall -std=c99 src/*.c -lSDL2 -lSDL2main -o renderer.out

brun:
	gcc -Wall -std=c99 src/*.c -lSDL2 -lSDL2main -o renderer.out && ./renderer.out

build debug:
	gcc -g -Wall -std=c99 src/*.c -lSDL2 -lSDL2main -o renderer.out && ./renderer.out

build debugRun:
	gcc -g -Wall -std=c99 src/*.c -lSDL2 -lSDL2main -o renderer.out && gdb ./renderer.out

run:
	./renderer.out

clean:
	rm ./renderer.out