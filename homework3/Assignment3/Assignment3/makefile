all: index

index: main.o indexer.o
    gcc -o index main.o indexer.o

main.o: main.c uthash.h indexer.h
    gcc -c index main.c

indexer.o: indexer.c indexer.h uthash.h
    gcc -c index indexer.c

clean :
	rm -rf index main.o indexer.o