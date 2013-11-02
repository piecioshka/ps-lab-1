CC=gcc
CFLAGS=-Wall -Werror -pedantic -pedantic-errors -fPIC

zad9: test.o initapi.o librandapi.so
	${CC} -L /Users/piecioshka/projects/ps-lab-1/source/zad9/przyklad2/ ${CFLAGS} -o zad9 test.o initapi.o -lrandapi

test.o: randapi.h
	${CC} ${CFLAGS} -c test.c

initapi.o: initapi.c
	${CC} ${CFLAGS} -c initapi.c

librandapi.so: randapi.o
	${CC} -shared -o librandapi.so randapi.o

randapi.o: randapi.c
	${CC} ${CFLAGS} -c randapi.c

clean:
	rm *.o *.so zad9

