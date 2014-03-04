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

struct node{
    char* token;
    char* file;
    int freq;
    struct node *next;
    UT_hash_handle hh;         /* makes this structure hashable */
};


struct node *list = NULL;

void add_token(char *token, char *file){
    struct node *s;
    
    HASH_FIND_STR(list, token, s);  /* id already in the hash? */
    if (s==NULL) {
        s = malloc(sizeof(struct node));
        strcpy(s->token, token);
        strcpy(s->file, file);
        HASH_ADD_KEYPTR(hh, list, s->token, strlen(s->token), s);
    }
    else {
        if (strcmp(file, s->file) == 0){
            s->freq++;
        }
        else while (s->next != NULL){
			if (strcmp(file, s->next->file) == 0)
			{
				s->next->freq++;
				break;
			}
			else s = s->next;
        }
		struct node *new;
		new = malloc(sizeof(struct node));
		strcpy(new->token, token);
		strcpy(new->file, file);
		s->next = new;
		HASH_ADD_KEYPTR(hh, s, new->token, strlen(s->token), new);
    }
}


