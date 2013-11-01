CC=gcc
CFLAGS=-Wall -Werror -pedantic -pedantic-errors

zad7b: test.o initapi.o randapi.o
	${CC} ${CFLAGS} -o zad7b test.o initapi.o randapi.o

test.o: randapi.h
	${CC} ${CFLAGS} -c test.c

initapi.o: initapi.c
	${CC} ${CFLAGS} -c initapi.c

randapi.o: randapi.c
	${CC} ${CFLAGS} -c randapi.c

clean:
	rm *.o zad7b

