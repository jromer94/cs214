//
//  indexer.c
//  Assignment3
//
//  Created by Alex McCullough on 3/3/14.
//  Copyright (c) 2014 Alex McCullough. All rights reserved.
//

#include <stdio.h>
#include "uthash.h"
#include "indexer.h"




struct node *list = NULL;

void add_token(char *token, char *file){
    struct node *s;
	int check = 0;
    
    HASH_FIND_STR(list, token, s);  /* id already in the hash? */
    if (s==NULL) {
        s = malloc(sizeof(struct node));
		s->token = malloc(strlen(token) + 1);
		s->file = malloc(strlen(file) + 1);
        strcpy(s->token, token);
        strcpy(s->file, file);
		s->freq = 1;
		s->next = NULL;
        HASH_ADD_KEYPTR(hh, list, s->token, strlen(s->token), s);
    }
    else
	{
        if (strcmp(file, s->file) == 0)
		{
            s->freq++;
			check++;
        }
        else while (s->next != NULL){
			if (strcmp(file, s->next->file) == 0)
			{
				s->next->freq++;
				check++;
				break;
			}
			else
				s = s->next;
        }
		if (check == 0)
		{
			struct node *new;
			new = malloc(sizeof(struct node));
			new->token = malloc(strlen(token) + 1);
			new->file = malloc(strlen(file) + 1);
			strcpy(new->token, token);
			strcpy(new->file, file);
			s->next = new;
			new->freq = 1;
			new->next = NULL;
		}
    }
}

void print_token(){
	struct node *s;
	struct node *temp;
	int counter = 0;
		
		for(s=list; s != NULL; s=s->hh.next) {
			printf("<list> %s \n", s->token);
			for (temp = s; temp != NULL; temp = temp->next){
				sortList(temp);
				
				printf("%s %d ", temp->file, temp->freq);
				counter++;
				if (counter == 5)
					printf("\n");
			}
			printf("\n</list> \n");
		}
}

int token_compare(struct node *a, struct node *b){
	return strcmp(a->token,b->token);
	
}

void sorter(){
    HASH_SORT(list, token_compare);
}

void sortList(struct node *head){
	
	struct node *current;
	current = head;
	struct node *largest;
	largest = head;

	if (head->next != NULL)
	{
		while (current != NULL)
		{
			if (current->freq > largest->freq)
			{
				largest = current;
				largest->freq = current->freq;
				largest->file = current->file;
			}
			current = current->next;
		}
		current = head;
		head->file = largest->file;
		head->freq = largest->freq;
		largest->file = current->file;
		largest->freq = current->freq;
		
		sortList((head->next));
	}
}


