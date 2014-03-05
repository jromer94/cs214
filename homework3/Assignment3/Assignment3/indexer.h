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
    UT_hash_handle hh;         /* makes this structure hashable */
};


struct node *list;

// add_token function takes in a string token (which we use as the key to our hashtable) and
// a string filename.  It creates a node in the hashtable if the token(key) was never used before
// or if the token/key was found before but in a different file.  If the token/key and the file it
// came from is already in the hashtable it updates the frequency
void add_token(char *token, char *file);

// print_token function prints all the nodes in the hashtable sorted in alphabetic order
void print_token();

// compare function for the tokens in order to sort the hashtable nodes in alphabetic order
int token_compare(struct node *a, struct node *b);

// sorts the hashtable nodes in alphabetic order
void sorter();

void sortList(struct node *head);

#endif
