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
struct outputNode *outputList = NULL;


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
		s->freq = 1;
		s->next = NULL;
        HASH_ADD_KEYPTR(hh, list, s->token, strlen(s->token), s);
    }
    else
	{
        if (strcmp(file, s->file) == 0)
		{
            s->freq++;
			check++;
        }
        else while (s->next != NULL){
			if (strcmp(file, s->next->file) == 0)
			{
				s->next->freq++;
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
			new->freq = 1;
			new->next = NULL;
		}
    }
}

void add_output_file(char* file){

    struct outputNode* temp;
    HASH_FIND_STR(outputList, file, temp);  

    if(temp == NULL){

        temp = malloc(sizeof(struct outputNode));
        temp->file = file;
        temp->freq = 1;
        HASH_ADD_KEYPTR(hh, outputList, temp->file, strlen(temp->file), temp);

    } else {

        temp->freq++; 

    }

}

void print_output_file(int type, int count){

    struct outputNode *temp;
    for(temp = outputList; temp != NULL; temp = temp->hh.next){

	if(type == 0){

        	printf("%s ", temp->file);

	} else {

		if(temp->freq == count){

			printf("%s ", temp->file);

		}

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
	sorter();
	
		for(s=list; s != NULL; s=s->hh.next) {
			fprintf(fp, "<list>\n");
			fprintf(fp, "%s\n", s->token);
			for (temp = s; temp != NULL; temp = temp->next){
				
				fprintf(fp, "%s %d ", temp->file, temp->freq);
				
			}
			fprintf(fp, "\n</list>\n");
		}
}



