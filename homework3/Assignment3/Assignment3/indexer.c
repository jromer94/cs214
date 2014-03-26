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



// ALL COMMENTS ON FUNCTIONS IN INDEXER.H

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
		s->next = NULL;
        HASH_ADD_KEYPTR(hh, list, s->token, strlen(s->token), s);
    }
    else
	{
        if (strcmp(file, s->file) == 0)
		{
			check++;
        }
        else while (s->next != NULL){
			if (strcmp(file, s->next->file) == 0)
			{
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
			new->next = NULL;
		}
    }
}

int token_compare(struct node *a, struct node *b){
	return strcmp(a->token,b->token);
	
}

void sorter(){
    HASH_SORT(list, token_compare);
}

void print_token(FILE *fp){
	struct node *s;
	struct node *temp;
	
		for(s=list; s != NULL; s=s->hh.next) {
			fprintf(fp, "%s\n", s->token);
			for (temp = s; temp != NULL; temp = temp->next){
				
				fprintf(fp, "%s ", temp->file);
				
			}
			fprintf(fp, "\n");
		}
}



