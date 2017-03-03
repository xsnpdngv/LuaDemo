# @file    Makefile
# @build   recipe to make Lua demo
# @author  Tamas Dezso
# @date    March 3, 2017

CC   = gcc
LD   = gcc

CFLAGS = -Wall -g
LDFLAGS =
LDLIBS += -llua -lm -ldl

.PHONY: all
all: lua_demo

.PHONY: clean
clean:
	- rm -f lua_demo *.o
