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

void read_file(FILE *ifp)
{
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
			add_token(key, temptok);
			temptok = strtok(NULL, " ");
			temptok = strtok(NULL, " ");
		}
		getline(&end, &len, ifp);
	}
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
	read_file(ifp);
	sorter();
	
	//start of test print (not needed for final thing)
	
	struct node *t;
	struct node *temp;
	
	for(t=list; t != NULL; t=t->hh.next) {
		printf("<list>\n");
		printf("%s\n", t->token);
		for (temp = t; temp != NULL; temp = temp->next){
			
			printf("%s ", temp->file);
			
		}
		printf("\n</list>\n");
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
		struct node *finalPrint;
		finalPrint = malloc(sizeof(finalPrint));
		struct node *outprint;
		outprint = finalPrint;
		int current = 0;
		struct node *s;
		s = malloc(sizeof(s));
		
		if (strcmp(temp, "so") == 0)
		{
			while (temp != NULL)
			{
				temp = strtok(NULL, " ");
				if (temp != NULL)
				{
					HASH_FIND_STR(list, temp, s);
					if (s==NULL)
					{
						break;
					}
					else
					{
						struct node *tempPrint;
						tempPrint = malloc(sizeof(tempPrint));
						
						for (tempPrint = s; tempPrint != NULL; tempPrint = tempPrint->next)
						{
							if (finalPrint->file == NULL)
							{
								finalPrint->file = tempPrint->file;
								current++;
							}
							else
							{
								struct node *tempCheck;
								tempCheck = malloc(sizeof(tempCheck));
								int equal = 0;
								for (tempCheck = outprint; tempCheck != NULL; tempCheck = tempCheck->next)
								{
									if (strcmp(tempPrint->file, tempCheck->file) == 0)
									{
										equal++;
										break;
									}

								}
								if (equal == 0)
								{
									if (current == 1)
									{
										finalPrint->next = tempPrint;
										current++;
									}
									else
									{
										
										for (int i = current; i > 1; i--)
										{
											finalPrint = finalPrint->next;
										}
										finalPrint->next = tempPrint;
										current++;
									}
								}
								
							}
														
						}
					}
				}
			}
			struct node *output;
			
			for (output = outprint; output != NULL; output = output->next)
			{
				printf("%s ", output->file);
			}
			q = 0;
		}
		
		else if (strcmp(temp, "sa") == 0)
		{
			while (temp != NULL)
			{
				temp = strtok(NULL, " ");
				if (temp != NULL)
				{
					HASH_FIND_STR(list, temp, s);
					if (s==NULL)
					{
						continue;
					}
					else{
						
						
						//
						
						
					}
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

