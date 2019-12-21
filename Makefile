.PHONY: all clean test

CFLAGS := -std=c11 -Wall -O3

all: sha0

clean:
	rm -f *.o sha0

test: all
	./sha0 sha0

sha0: main.o sha0.o
	$(CC) $(CFLAGS) -o $@ $^

.c.o:
	$(CC) -c $(CFLAGS) -o $@ $<
