//
//  myAlloc.c
//  Assignment6
//
//  Created by Alex McCullough on 5/1/14.
//  Copyright (c) 2014 Alex McCullough. All rights reserved.
//

#include <stdio.h>
#include "myAlloc.h"

static char myblock[5000];
int test = 1;

union header *head = NULL;


void *mymalloc(size_t len, char *file, int line){
	
	union header *prev;
	union header *p;
	
	unsigned blocks;
	
	blocks = (unsigned)(len + sizeof(union header)-1)/sizeof(union header) + 1;
	
	if ((prev = head) == NULL && test == 1){
		prev = (union header*)&myblock[0];
		head = (union header*)&myblock[0];
		head->s.ptr = (union header*)&myblock[0];
		head->s.size = prev->s.size = (sizeof(myblock)/sizeof(union header));
		test--;
	} else if(head == NULL){
		
		printf("Memory full. Cannot allocate enough memory in %s at line %d\n", file, line);
		return NULL;
	}
	
	for (p = prev->s.ptr; ; prev = p, p=p->s.ptr){
		if (p->s.size >= blocks) {
			if (p->s.size == blocks) {
				if(prev->s.ptr == p->s.ptr){
					
					prev = NULL;
					
				}
				else prev->s.ptr = p->s.ptr;
			}
			else{
				p->s.size -= blocks;
				p += p->s.size;
				p->s.size = blocks;
			}
		
			p->s.magic = 60666;
			head = prev;
			return (void *)(p + 1);
		}
	
	if (p == head) {
		printf("Not enough memory to allocate in %s at line %d\n", file, line);
		return NULL;
		}
	}
}

void myfree(void* mem, char* file, int line){

	
	union header *bp, *p;
	
	bp = (union header*)mem - 1;
	
	if (mem == NULL || bp->s.magic != 60666) {
		printf("Invalid free in %s at line %d\n", file, line);
		return;
	}
	else bp->s.magic = 0;
	
	if (head == NULL){
		
		head = bp;
		return;
		
	}
	
	for (p = head; !(bp > p && bp < p->s.ptr); p = p->s.ptr) {
		if (p >= p->s.ptr && (bp > p || bp < p->s.ptr)) {
			break;
		}
	}

	if (bp + bp->s.size == p->s.ptr){
		bp->s.size += p->s.ptr->s.size;
		bp->s.ptr = p->s.ptr->s.ptr;
	}
	else bp->s.ptr = p->s.ptr;
	
	if (p + p->s.size == bp) {
		p->s.size += bp->s.size;
		p->s.ptr = bp->s.ptr;
	}
	else p->s.ptr = bp;
	
	head = p;
}

void *mycalloc(size_t num, size_t size, char *file, int line){
	int i;	
	char *p;
	p = mymalloc(num*size, file, line);
	
	if (p == NULL) {
		return p;
	}
	else for (i = 0; i < num*size; i++) {
		p[i] = 0;
	}
	return p;
}


#define malloc(x)		mymalloc(x, __FILE__, __LINE__)
#define free(x)			myfree(x, __FILE__, __LINE__)
#define calloc(x, y)	mycalloc(x, y, __FILE__, __LINE__)

