SHELL = /bin/bash
CC = gcc
CFLAGS = -Wall --pedantic
TARGET = bin/
SRC = source/
SRC_ZAD1 = ${SRC}zad1/

zad1:
	${CC} ${CFLAGS} ${SRC_ZAD1}/main.c ${SRC_ZAD1}func.c -o ${TARGET}zad1/main.o
