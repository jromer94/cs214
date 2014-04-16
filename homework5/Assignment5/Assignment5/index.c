//
//  index.c
//  Assignment5
//
//  Created by Alex McCullough on 4/15/14.
//  Copyright (c) 2014 Alex McCullough. All rights reserved.
//

#include <stdio.h>
#include "uthash.h"
#include "index.h"


struct node *list = NULL;

void add_token(char *name, char *customer_id, char *balance, char *address1, char *address2, char *address3){
    struct node *s;
	
    
    HASH_FIND_STR(list, name, s);  /* id already in the hash? */
    if (s==NULL) {
        s = malloc(sizeof(struct node));
		s->name = malloc(strlen(name) + 1);
		strcpy(s->name, name);
		s->customer_id = malloc(strlen(customer_id) + 1);
		strcpy(s->customer_id, customer_id);
		s->balance = malloc(strlen(balance) + 1);
		strcpy(s->balance, balance);
		s->address1 = malloc(strlen(address1) + 1);
        strcpy(s->address1, address1);
		s->address2 = malloc(strlen(address2) + 1);
        strcpy(s->address2, address2);
		s->address3 = malloc(strlen(address3) + 1);
        strcpy(s->address3, address3);
        HASH_ADD_KEYPTR(hh, list, s->name, strlen(s->name), s);
    }
}



void print_token(){
	
	struct node *s;
	
	for(s=list; s != NULL; s=s->hh.next) {
		printf("%s ", s->name);
		printf("%s ", s->customer_id);
		printf("%s ", s->balance);
		printf("%s ", s->address1);
		printf("%s ", s->address2);
		printf("%s ", s->address3);
		printf("%s ", s->address3);


	}
}



