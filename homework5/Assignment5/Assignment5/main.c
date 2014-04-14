//
//  main.c
//  Assignment5
//
//  Created by Alex McCullough on 4/14/14.
//  Copyright (c) 2014 Alex McCullough. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "uthash.h"

char *read_input (char *s, int n)
{
	char *p;
	p = fgets (s, n, stdin);
	
	if (p != NULL)
	{
		size_t last = strlen (s) - 1;
		
		if (s[last] == '\n')
		{
			s[last] = '\0';
		}
	}
	return p;
}

void read_data(FILE *ifp){
	
	
	
}


int main(int argc, const char * argv[])
{

	if (argc != 4){
		printf("Error: Incorrect number of arguements\n");
		return -1;
	}
	
	FILE *database;
	FILE *orders;
	FILE *categories;
	
	if ((database = fopen(argv[1], "r")) == NULL)
	{
		printf("Error opening database file\n");
		return -1;
	}

	
	
	
    return 0;
}

