//
//  main.c
//  Assignment5
//
//  Created by Alex McCullough on 4/14/14.
//  Copyright (c) 2014 Alex McCullough. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "index.h"
#include "uthash.h"
#include <pthread.h>

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

void read_file(FILE *ifp)
{
	char *full = NULL;
	char *name = NULL;
	char *customer_id = NULL;
	char *balance = NULL;
	char *address1 = NULL;
	char *address2 = NULL;
	char *address3 = NULL;
	size_t len = 0;
	
	
	while (!feof(ifp))
	{
		getline(&full, &len, ifp);
		full = strtok(full, "\n");
		
		char *temp;
		temp = full;
		
		name = strtok(temp, "|");
		customer_id = strtok(NULL, "|");
		balance = strtok(NULL, "|");
		address1 = strtok(NULL, "|");
		address2 = strtok(NULL, "|");
		address3 = strtok(NULL, "|");

		add_token(name, customer_id, balance, address1, address2, address3);
		
	}
}


int main(int argc, const char * argv[])
{

	if (argc != 4){
		printf("Error: Incorrect number of arguements\n");
		return -1;
	}
	
	FILE *database;
//	FILE *orders;
//	FILE *categories;
	
	if ((database = fopen(argv[1], "r")) == NULL)
	{
		printf("Error opening database file\n");
		return -1;
	}
	
	read_file(database);


	print_token();
	
	
	
	
    return 0;
}


void *order_thread_function(void *arg) {

	

}
