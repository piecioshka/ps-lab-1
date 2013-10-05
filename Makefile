SHELL = /bin/bash
CC = gcc
CFLAGS = -Wall --pedantic
TARGET = bin/
SRC = source/
Z1 = zad1/
Z2 = zad2/
Z3 = zad3/
Z4 = zad4/

zad1:
	${CC} ${CFLAGS} ${SRC}${Z1}main.c ${SRC}${Z1}func.c -o ${TARGET}${Z1}main.o

zad2:
	${CC} ${CFLAGS} ${SRC}${Z2}main.c -o ${TARGET}${Z2}main.o

zad3:
	${CC} ${CFLAGS} ${SRC}${Z3}main.c -o ${TARGET}${Z3}main.o

zad4:
	${CC} ${CFLAGS} ${SRC}${Z4}main.c -o ${TARGET}${Z4}main.o

