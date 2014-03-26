//
//  main.c
//  Assignment4
//
//  Created by Alex McCullough on 3/24/14.
//  Copyright (c) 2014 Alex McCullough. All rights reserved.
//

#include <stdio.h>
#include <string.h>

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
		
	
	/*FILE *ifp;
	
	if ((ifp = fopen(argv[1], "r")) == NULL)
	{
		printf("Error opening input file");
		return -1;
	}
	*/
	
	//read into memory
	
	int q = 1;
	char line[BUFFER];
	char *input;
	
	while (q !=0)
	{
		printf("Enter search inquiry or q to quit:\n");
		fflush (stdout);
		input = read_input(line, BUFFER);
		
		char* temp;
		temp = input;
		temp = strtok(input, " ");
		
		if (strcmp(temp, "sa") == 0)
		{
			while (temp != NULL)
			{
				temp = strtok(NULL, " ");
				if (temp != NULL){
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
				if (temp != NULL){
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
	
	//fclose(ifp);
}

