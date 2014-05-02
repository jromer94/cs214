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
	void* hi = NULL;
	free(hi);

	void* big = malloc(4968);
	malloc(1000);
	
	
	free(big+1000);
	free(big);
	
	
	malloc(1000);
	
	calloc(2000, 2);

	
	}

