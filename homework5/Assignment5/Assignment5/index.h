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
struct final_orders{
	char *title;
	double price;
	double balance;
	struct final_orders *next;
};

struct final_rejected{
	char *title;
	double price;
	struct final_rejected *next;
};

struct customer_info{
    char *name;
    char *customer_id;
    double balance;
    char *address1;
	char *address2;
	char *address3;
	struct final_orders *order_next;
	struct final_rejected *rejected_next;
    UT_hash_handle hh;
};

struct order_info{
	char *title;
	double price;
	char *customer;
	char *category;
	struct order_info *next;
	UT_hash_handle hh;
};

struct order_queue{
	char *category;
	int total;
	struct order_info *head;
	UT_hash_handle hh;  
};

struct category_list{
	char *category;
	struct category_list *next;
};

void cat_list(char *category, struct category_list *current_list);

void add_customer(char *name, char *customer_id, char *balance, char *address1, char *address2, char *address3);

void add_order(char *title, char *price, char *customer, char *category);

void add_cat(char *category);

struct order_queue *get_cat();

struct order_queue *get_queue(char *category);

void add_to_queue(struct order_queue *new_order, struct order_info *order);

void add_accepted(struct final_orders *accept_list, struct order_info *order, struct customer_info *s);

void add_rejected(struct final_rejected *reject_list, struct order_info *order);

void purchase_book(struct order_queue *order);

void print_customer_info();

void print_orders();

void print_cat();

void print_report(FILE *ofp);

#endif
