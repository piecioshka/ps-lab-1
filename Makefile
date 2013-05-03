SHELL = /bin/bash

CC = gcc
CFLAGS = -Wall --pedantic

TARGET = bin/
SRC = source/

zad1:
	${CC} ${CFLAGS} -c ${SRC}zad1/main.c -o ${TARGET}zad1/main.o
 
all:
	zad1
	
break:
	@echo "------------------------------------------------------------"

clean:
	find ${TARGET} -name "*.o" | xargs rm -rf

.PHONY: all clean
