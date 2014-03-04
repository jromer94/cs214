//
//  indexer.h
//  Assignment3
//
//  Created by Alex McCullough on 3/3/14.
//  Copyright (c) 2014 Alex McCullough. All rights reserved.
//

#ifndef Assignment3_indexer_h
#define Assignment3_indexer_h
#include "uthash.h"

struct node{
    char* token;
    char* file;
    int freq;
    struct node *next;
	struct node *prev;
    UT_hash_handle hh;         /* makes this structure hashable */
};


struct node *list;

void add_token(char *token, char *file);

void print_token();

int token_compare(struct node *a, struct node *b);

void sorter();

#endif
