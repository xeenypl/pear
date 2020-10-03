run-test: test
	./test

test: test.o pear.o
	$(CC) -o test test.o pear.o

test.o: test.c pear.h
	$(CC) -c test.c

pear.o: pear.c pear.h
	$(CC) -c pear.c
