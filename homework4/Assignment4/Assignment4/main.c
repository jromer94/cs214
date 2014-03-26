//
//  main.c
//  Assignment4
//
//  Created by Alex McCullough on 3/24/14.
//  Copyright (c) 2014 Alex McCullough. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "indexer.h"
#include "uthash.h"

#define BUFFER	100

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


int main(int argc, const char * argv[])
{

	if (argc !=2)
	{
		printf("Error, incorrect number of arguements");
		return -1;
	}
		
	
	FILE *ifp;
	
	if ((ifp = fopen(argv[1], "r")) == NULL)
	{
		printf("Error opening input file");
		return -1;
	}
	
	char *start = NULL;
	char *end = NULL;
	char *key = NULL;
	char *file = NULL;
	size_t len = 0;
	size_t len2 = 0;
	
	while (!feof(ifp))
	{
		getline(&start, &len, ifp);
		getline(&key, &len, ifp);
		key = strtok(key, "\n");
		getline(&file, &len2, ifp);
		file = strtok(file, "\n");
		char *temptok;
		temptok = file;
		temptok= strtok(file, " ");
		while (temptok != NULL)
		{
			if (temptok != NULL)
			{
				add_token(key, temptok);
			}
			temptok = strtok(NULL, " ");

		}
		getline(&end, &len, ifp);
	}
		
	//start of test print (not needed for final thing)
	sorter();
	
	struct node *s;
	struct node *temp;
	
	for(s=list; s != NULL; s=s->hh.next) {
		printf("%s\n", s->token);
		for (temp = s; temp != NULL; temp = temp->next){
			
			printf("%s ", temp->file);
			
		}
		printf("\n");
	}
	
	//end of test print (not needed for final thing)
	
	int q = 1;
	char input_line[BUFFER];
	char *input;
	
	while (q !=0)
	{
		printf("Enter search inquiry or q to quit:\n");
		fflush (stdout);
		input = read_input(input_line, BUFFER);
		
		char* temp;
		temp = input;
		temp = strtok(input, " ");
		
		if (strcmp(temp, "sa") == 0)
		{
			while (temp != NULL)
			{
				temp = strtok(NULL, " ");
				if (temp != NULL)
				{
					//search for temp in hash
				}
			}
			q = 0;
		}
		
		else if (strcmp(temp, "so") == 0)
		{
			while (temp != NULL)
			{
				temp = strtok(NULL, " ");
				if (temp != NULL)
				{
					//search for temp in hash
				}
			}
			q = 0;
		}
	
					
		else if (strcmp(input, "q\0") == 0)
		{
			q = 0;
		}
	}
	
	
	fclose(ifp);
}

