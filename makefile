all: main.o pages.o typing.o leaderboard.o
	gcc -o start main.o pages.o typing.o leaderboard.o

main.o: main.c pages.h typing.h leaderboard.h
	gcc -c -g main.c

pages.o: pages.c pages.h
	gcc -c -g pages.c

typing.o: typing.c typing.h
	gcc -c -g typing.c

leaderboard.o: leaderboard.c leaderboard.h
	gcc -c -g leaderboard.c

run:
	./start
