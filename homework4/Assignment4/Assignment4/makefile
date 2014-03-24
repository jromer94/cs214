all: search

search: search.o
	gcc -o search search.c search.h

search.o: search.c search.h
	gcc -c search search.h
	
clearn:
	rm -f search.o search