.PHONY: clean all

CFLAGS=-Wall -std=c99 -O3

all: cat cp


cat: cat.c
	gcc -o cat $(CFLAGS) $^

cp: cp.c
	gcc -o cp $(CFLAGS) $^

clean:
	rm -f cat cp

