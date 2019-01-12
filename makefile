all: main.o pages.o
	gcc -o start main.o pages.o

main.o: main.c pages.h
	gcc -c -g main.c

pages.o: pages.c pages.h
	gcc -c -g pages.c

run:
	./start
