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

struct customer_info{
    char *name;
    char *customer_id;
    char *balance;
    char *address1;
	char *address2;
	char *address3;
    UT_hash_handle hh;         /* makes this structure hashable */
};

struct order_info{
	char *title;
	char *price;
	char *customer;
	char *category;
	UT_hash_handle hh;
};

void add_customer(char *name, char *customer_id, char *balance, char *address1, char *address2, char *address3);

void add_order(char *title, char *price, char *customer, char *category);

void print_customer_info();

void print_orders();

void print_report(FILE *ofp);

#endif
