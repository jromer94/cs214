//
//  myAlloc.h
//  Assignment6
//
//  Created by Alex McCullough on 5/1/14.
//  Copyright (c) 2014 Alex McCullough. All rights reserved.
//

#ifndef Assignment6_myAlloc_h
#define Assignment6_myAlloc_h

typedef long long Align;

//a union to hold information for the pointers we have malloced
union header{
	struct {
		union header *ptr;
		unsigned size;
		int magic;
	}s;
	Align x;
};

//malloc function from the C book that is implememnted on a char array of 5000 bytes
void *mymalloc(size_t len, char *file, int line);

//free function based off of the C book, error checks with our magic number
void myfree(void *p, char *file, int line);

//calloc function uses malloc and then zeroes out all memory
void *mycalloc(size_t num, size_t size, char *file, int line);

#define malloc(x)		mymalloc(x, __FILE__, __LINE__)
#define free(x)			myfree(x, __FILE__, __LINE__)
#define calloc(x, y)		mycalloc(x, y, __FILE__, __LINE__)

#endif
