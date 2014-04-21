//
//  main.c
//  Assignment5
//
//  Created by Alex McCullough on 4/14/14.
//  Copyright (c) 2014 Alex McCullough. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "index.h"
#include "uthash.h"
#include <pthread.h>

pthread_mutex_t a_mutex = PTHREAD_MUTEX_INITIALIZER;	
int time_to_exit = 0;
struct category_list *current_list = NULL;
int cat = 0;

char *read_input (char *s, int n)
{
	char *p;
	p = fgets (s, n, stdin);
	
	if (p != NULL)
	{
		size_t last = strlen (s) - 1;
		
		if (s[last] == '\n')
		{
			s[last] = '\0';
		}
	}
	return p;
}

void read_customers(FILE *ifp)
{
	char *full = NULL;
	char *name = NULL;
	char *customer_id = NULL;
	char *balance = NULL;
	char *address1 = NULL;
	char *address2 = NULL;
	char *address3 = NULL;
	size_t len = 0;
	
	
	while (!feof(ifp))
	{
		getline(&full, &len, ifp);
		full = strtok(full, "\n");
		
		char *temp;
		temp = full;
		
		name = strtok(temp, "|");
		customer_id = strtok(NULL, "|");
		balance = strtok(NULL, "|");
		address1 = strtok(NULL, "|");
		address2 = strtok(NULL, "|");
		address3 = strtok(NULL, "|");

		add_customer(name, customer_id, balance, address1, address2, address3);
		
	}
}

struct order_info *read_order(FILE *ifp){
	
	char *full = NULL;
	char *title = NULL;
	char *price = NULL;
	char *customer = NULL;
	char *category = NULL;
	size_t len = 0;
	struct order_info *s;

	
	if (!feof(ifp))
	{
		getline(&full, &len, ifp);
		full = strtok(full, "\n");
		
		char *temp;
		temp = full;
		
		title = strtok(temp, "|");
		price = strtok(NULL, "|");
		customer = strtok(NULL, "|");
		category = strtok(NULL, "|");
		
		add_order(title, price, customer, category);
	}
	else return NULL;
		
	
	s = malloc(sizeof(struct customer_info));
	
	s->title = malloc(strlen(title) + 1);
	strcpy(s->title, title);
	s->price = atof(price);
	s->customer = malloc(strlen(customer) + 1);
	strcpy(s->customer, customer);
	s->category = malloc(strlen(category) + 1);
	strcpy(s->category, category);
	s->next = NULL;
	return s;

}

void read_cat(FILE *ifp){
	char *category = NULL;
	size_t len = 0;
	
	while (!feof(ifp))
	{
		getline(&category, &len, ifp);
		category = strtok(category, "\n");
		
		add_cat(category);

		cat++;
	}
}


void *order_thread_function(void *arg) {
	
	FILE* orders = (FILE*) arg;

	printf("order thread started\n");	

	while(1){
		struct order_info* current = read_order(orders);
		if(current == NULL){
			
			printf("exiting orders thread\n");
			time_to_exit = 1;
			pthread_exit("exited order thread");
			
		}
		
		struct order_queue* cat_queue = get_queue(current->category);
	
		int wait = 0;
	
		while(1){
			
			pthread_mutex_lock(&a_mutex);
			if(cat_queue->total < 10){

				//printf("adding %s for user %s\n", current->title, current->customer);
				if(wait == 1){

					printf("producer resumes\n");
					wait = 0;

				}
				add_to_queue(cat_queue, current);
				pthread_mutex_unlock(&a_mutex);
				break;
				
			} else {

				if(wait == 0){

					printf("producer waits\n");
					wait = 1;

				}

			
			}
			pthread_mutex_unlock(&a_mutex);
			
		}
		
	}
	
	return 0;
}

void *category_thread_function(void* args) {
	
	char* category = (char*) args;

	//printf("category thread %s started \n", category);

	struct order_queue* queue = get_queue(category);

	int wait = 0;

	while(1){

		//printf("%d = total for %s \n", queue->total, category);

		pthread_mutex_lock(&a_mutex);
		if(queue->total > 0){

			if(wait == 1){
				printf("%s Consumer resumes\n", category);
				wait = 0;
			}
			purchase_book(queue);

		} else if(time_to_exit){
			
			pthread_mutex_unlock(&a_mutex);
			pthread_exit("exiting thread");

		} else {

			if(wait == 0){
				printf("%s Consumer waits\n", category);
				wait = 1;
			}
		}

		

		pthread_mutex_unlock(&a_mutex);	

	} 

	
	return 0;
}

int main(int argc, const char * argv[])
{

	if (argc != 5){				/////// CHANGE BACK TO 4, IT IS 5 FOR OUR TEST
		printf("Error: Incorrect number of arguements\n");
		return -1;
	}
	
	FILE *database;
	FILE *orders;
	FILE *categories;
	
	if ((database = fopen(argv[1], "r")) == NULL)
	{
		printf("Error opening database file\n");
		return -1;
	}
	read_customers(database);
	fclose(database);
	
	if ((orders = fopen(argv[2], "r")) == NULL)
	{
		printf("Error opening orders file\n");
		return -1;
	}
	
	if ((categories = fopen(argv[3], "r")) == NULL)
	{
		printf("Error opening database file\n");
		return -1;
	}
	read_cat(categories);
	
	pthread_t order_thread;
	void *thread_result;
	
	int order_thread_id = pthread_create(&order_thread, NULL, order_thread_function, (void*)orders);


	pthread_t cat_threads[cat];
	int loc = 0;
	
	struct order_queue* list = get_cat();

	while(list != NULL){

		pthread_t category_thread;
		int category_thread_id = pthread_create(&category_thread, NULL, category_thread_function, (void*)list->category);

		cat_threads[loc] = category_thread;
		loc++;

		list = list->hh.next;


	}

	pthread_join(order_thread, &thread_result);

	
	int i;
	
	for(i = 0; i < cat; i++){

		
		pthread_join(cat_threads[i], &thread_result);

	} 

	fclose(orders);
	fclose(categories);
	
	//////TEST
	
	FILE *test;
	test = fopen(argv[4], "w");
	print_report(test);
	fclose(test);
	return 0;

}




