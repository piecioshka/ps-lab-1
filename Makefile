CC = gcc
CFLAGS = -Wall -Werror -pedantic -pedantic-errors
TARGET = bin/
SRC = source/
Z1 = zad1/
Z2 = zad2/
Z3 = zad3/
Z4 = zad4/
Z5 = zad5/
Z10 = zad10/
Z11 = zad11/

zad1:
	${CC} ${CFLAGS} ${SRC}${Z1}main.c ${SRC}${Z1}func.c -o ${TARGET}${Z1}main.o

zad2:
	${CC} ${CFLAGS} ${SRC}${Z2}main.c -o ${TARGET}${Z2}main.o

zad3:
	${CC} ${CFLAGS} ${SRC}${Z3}main.c -o ${TARGET}${Z3}main.o

zad4:
	${CC} ${CFLAGS} ${SRC}${Z4}main.c -o ${TARGET}${Z4}main.o

zad5:
	${CC} ${CFLAGS} ${SRC}${Z5}main.c -o ${TARGET}${Z5}main.o

zad10:
	${CC} ${SRC}${Z10}who1.c -o ${TARGET}${Z10}who1.o

zad11:
	${CC} ${CFLAGS} ${SRC}${Z11}main.c -o ${TARGET}${Z11}main.o

