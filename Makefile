build:
	gcc -Wall -std=c99 src/*.c -o renderer.out

run:
	./renderer.out

clean:
	rm ./renderer.out