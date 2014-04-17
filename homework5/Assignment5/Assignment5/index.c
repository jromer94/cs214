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


struct customer_info *list = NULL;
struct order_info *orders = NULL;

void add_customer(char *name, char *customer_id, char *balance, char *address1, char *address2, char *address3){
    struct customer_info *s;
	
    
    HASH_FIND_STR(list, name, s);  /* id already in the hash? */
    if (s==NULL) {
        s = malloc(sizeof(struct customer_info));
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

void add_order(char *title, char *price, char *customer, char *category){
	
	struct order_info *s;
	
	s = malloc(sizeof(struct customer_info));

	s->title = malloc(strlen(title) + 1);
	strcpy(s->title, title);
	s->price = malloc(strlen(price) + 1);
	strcpy(s->price, price);
	s->customer = malloc(strlen(customer) + 1);
	strcpy(s->customer, customer);
	s->category = malloc(strlen(category) + 1);
	strcpy(s->category, category);
	HASH_ADD_KEYPTR(hh, orders, s->title, strlen(s->title), s);
	
}


void print_customer_info(){
	
	struct customer_info *s;
	
	for(s=list; s != NULL; s=s->hh.next) {
		printf("%s ", s->name);
		printf("%s ", s->customer_id);
		printf("%s ", s->balance);
		printf("%s ", s->address1);
		printf("%s ", s->address2);
		printf("%s ", s->address3);
		printf("\n");


	}
}

void print_orders(){
	
	struct order_info *s;
	
	for(s=orders; s != NULL; s=s->hh.next) {

		printf("%s ", s->title);
		printf("%s ", s->price);
		printf("%s ", s->customer);
		printf("%s ", s->category);
		printf("\n");
	}
}


void print_report(FILE *ofp){
	struct customer_info *s;
	
	for (s=list; s != NULL; s=s->hh.next){
		fprintf(ofp, "=== BEGIN CUSTOMER INFO ===\n");
		fprintf(ofp, "### BALANCE ###\n");
		fprintf(ofp, "Customer Name: %s\n", s->name);
		fprintf(ofp, "Customer ID number: %s\n", s->customer_id);
		fprintf(ofp, "Remaining credit balance after all purchases: %s\n", s->balance);
		fprintf(ofp, "### SUCCESSFUL ORDERS ###\n");
		
		//PUT IN ALL ORDERS
		
		fprintf(ofp, "=== END CUSTOMER INFO ===\n");
	}
	
	
}


