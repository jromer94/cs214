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

	mymalloc(1000, NULL, 0);
	printf("DONE\n");
	mymalloc(1000, NULL, 0);
	printf("DONE\n");
	mymalloc(1000, NULL, 0);
	printf("DONE\n");
	mymalloc(1000, NULL, 0);
	printf("DONE\n");
	mymalloc(500, NULL, 0);
	mymalloc(360, NULL, 0);

	
	
}

