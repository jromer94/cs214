//
//  index.h
//  Assignment5
//
//  Created by Alex McCullough on 4/15/14.
//  Copyright (c) 2014 Alex McCullough. All rights reserved.
//

#ifndef Assignment5_index_h
#define Assignment5_index_h

#include "uthash.h"

struct node{
    char *name;
    char *customer_id;
    char *balance;
    char *address1;
	char *address2;
	char *address3;
    UT_hash_handle hh;         /* makes this structure hashable */
};

void add_token(char *name, char *customer_id, char *balance, char *address1, char *address2, char *address3);
void print_token();


#endif
