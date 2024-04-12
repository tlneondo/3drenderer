build:
	gcc -Wall -std=c99 src/*.c -lSDL2 -lSDL2main -o renderer.out

run:
	./renderer.out

clean:
	rm ./renderer.out