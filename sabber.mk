# Compiler
#
CC = g++
#
# # Flags to the compiler

CFLAGS = -Wall
all: hw
hw: sabber.cpp
	${CC} ${CFLAGS} sabber.cpp -o sabber

clean:
	rm -rf sabber
