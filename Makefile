CC = gcc
CFLAGS = -Wall -Werror -pedantic -pedantic-errors
TARGET = bin/
SRC = source/

zad1:
	${CC} ${CFLAGS} ${SRC}$@/main.c ${SRC}$@/func.c -o ${TARGET}$@/main.o

zad2:
	${CC} ${CFLAGS} ${SRC}$@/main.c -o ${TARGET}$@/main.o

zad3:
	${CC} ${CFLAGS} ${SRC}$@/main.c -o ${TARGET}$@/main.o

zad4:
	${CC} ${CFLAGS} ${SRC}$@/main.c -o ${TARGET}$@/main.o

zad5:
	${CC} ${CFLAGS} ${SRC}$@/main.c -o ${TARGET}$@/main.o

zad10:
	${CC} ${SRC}$@/who1.c -o ${TARGET}$@/who1.o

zad11:
	${CC} ${CFLAGS} ${SRC}$@/main.c -o ${TARGET}$@/main.o

