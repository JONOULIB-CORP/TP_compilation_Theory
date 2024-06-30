all: parser

parser: exo14.o utils.o
	gcc -o parser exo14.o utils.o -lfl

exo14.o: exo14.c exo14.h
	gcc -c exo14.c

exo14.c: exo14.lex
	flex -o exo14.c exo14.lex

utils.o: utils.c utils.h
	gcc -c utils.c

clean:
	rm -f *.o parser exo14.c
