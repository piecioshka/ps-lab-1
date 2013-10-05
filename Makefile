SHELL = /bin/bash
CC = gcc
CFLAGS = -Wall --pedantic
TARGET = bin/
SRC = source/
Z1 = zad1/
Z2 = zad2/

zad1:
	${CC} ${CFLAGS} ${SRC}${Z1}main.c ${SRC}${Z1}func.c -o ${TARGET}${Z1}main.o

zad2:
	${CC} ${CFLAGS} ${SRC}${Z2}main.c ${SRC}${Z2}func.c -o ${TARGET}${Z2}main.o

