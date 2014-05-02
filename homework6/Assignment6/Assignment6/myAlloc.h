//
//  myAlloc.h
//  Assignment6
//
//  Created by Alex McCullough on 5/1/14.
//  Copyright (c) 2014 Alex McCullough. All rights reserved.
//

#ifndef Assignment6_myAlloc_h
#define Assignment6_myAlloc_h


typedef long Align;

union header{
	struct {
		union header *ptr;
		unsigned size;
	}s;
	Align x;
};

void *mymalloc(size_t len, char *file, int line);

void myfree(void *p);


#endif
