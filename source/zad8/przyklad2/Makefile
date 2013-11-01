CC=gcc
CFLAGS=-Wall -Werror -pedantic -pedantic-errors

zad8b: test.o initapi.o librandapi.a
	${CC} ${CFLAGS} -o zad8b test.o initapi.o librandapi.a

test.o: randapi.h
	${CC} ${CFLAGS} -c test.c

initapi.o: initapi.c
	${CC} ${CFLAGS} -c initapi.c

librandapi.a: randapi.o
	ar rcs librandapi.a randapi.o

randapi.o: randapi.c
	${CC} ${CFLAGS} -c randapi.c

clean:
	rm *.o *.a zad8b

