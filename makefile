cflags = -fPIC -c -g
CC = gcc



PRO: prepare lib2048.so buildexe

prepare:
	mkdir -p ./build ./build/lib

lib2048.so: lib2048.o debug.o
	$(CC) -shared -o ./build/lib/lib2048.so ./build/lib2048.o ./build/debug.o 

debug: lib2048.o debug.o
	 $(CC) -o debug ./build/lib2048.o ./build/debug.o

lib2048.o: so2048.c
	$(CC) $(cflags) so2048.c -o ./build/lib2048.o

debug.o: debug.c
	$(CC) $(cflags) debug.c -o ./build/debug.o

buildexe: setup.py
	python3 setup.py build

clean:
	rm -rf ./build/

