all: main.o pages.o typing.o
	gcc -o start main.o pages.o typing.o

main.o: main.c pages.h typing.h
	gcc -c -g main.c

pages.o: pages.c pages.h
	gcc -c -g pages.c

typing.o: typing.c typing.h
	gcc -c -g typing.c

run:
	./start
