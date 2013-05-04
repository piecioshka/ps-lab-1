SHELL = /bin/bash

CC = gcc
CFLAGS = -Wall --pedantic

TARGET = bin/
SRC = source/

zad1:
	${CC} -c ${SRC}zad1/func.c ${TARGET}zad1/func.o
	ar rcs libhello.a libhello.o
	${CC} ${CFLAGS} ${SRC}zad1/main.c -o ${TARGET}zad1/main.o
 
all:
	zad1 break;
	
break:
	@echo "------------------------------------------------------------"

clean:
	find ${TARGET} -name "*.o" | xargs rm -rf

.PHONY: all clean
