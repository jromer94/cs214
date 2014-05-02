//
//  main.c
//  Assignment6
//
//  Created by Alex McCullough on 4/28/14.
//  Copyright (c) 2014 Alex McCullough. All rights reserved.
//

#include <stdio.h>
#include "myAlloc.h"




int main(int argc, const char * argv[])
{
	int a = 5;
	int *h = &a;

	mymalloc(1000, NULL, 0);
	printf("DONE\n");
	mymalloc(1000, NULL, 0);
	printf("DONE\n");
	mymalloc(1000, NULL, 0);
	printf("DONE\n");
	void* big = mymalloc(1000, NULL, 0);
	printf("DONE\n");
	mymalloc(500, NULL, 0);
	mymalloc(300, NULL, 0);
	mymalloc(280, NULL, 0);

	myfree(big, NULL, 0);
	
	void* hello = mymalloc(sizeof(h), NULL, 0);
	myfree(hello, NULL, 0);
	printf("first free\n");

	hello = mymalloc(sizeof(h), NULL, 0);
	myfree(hello, NULL, 0);
	printf("second free\n");

	big = mymalloc(1000, NULL, 0);
	printf("added");
	
	mymalloc(280, NULL, 0);

	
}

