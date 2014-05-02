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

struct checker inList= {NULL, NULL};

union header *head = NULL;


void *mymalloc(size_t len, char *file, int line){
	
	union header *prev;
	union header *p;
	
	unsigned blocks;
	printf("made it in\n");
	
	blocks = (unsigned)(len + sizeof(union header)-1)/sizeof(union header) + 1;
	
	if ((prev = head) == NULL){
		prev = (union header*)&myblock[0];
		head = (union header*)&myblock[0];
		head->s.ptr = (union header*)&myblock[0];
		head->s.size = prev->s.size = sizeof(myblock)/15.5;
		printf("head was null\n");
	}
	
	for (p = prev->s.ptr; ; prev = p, p=p->s.ptr){
		printf("for loop, blocks = %u\ns.size = %d\n", blocks, p->s.size);
		if (p->s.size >= blocks) {
			if (p->s.size == blocks) {
				prev->s.ptr = p->s.ptr;
				printf("size equal\n");
			}
			else{
				p->s.size -= blocks;
				p += p->s.size;
				p->s.size = blocks;
				printf("size smaller than blocks left\n");
			}
		
		head = prev;
		return (void *)(p + 1);
			
		}
	
	if (p == head) {
		printf("Not enough memory\n");
		return NULL;
		}
	}
		
}

void myfree(void* mem, char* file, int line){

	
	union header *bp, *p;
	
	bp = (union header*)mem - 1;
	
	for (p = head; !(bp > p && bp < p->s.ptr); p = p->s.ptr) {
		if (p >= p->s.ptr && (bp > p || bp < p->s.ptr)) {
			printf("added first\n");
			break;
		}
	}

	if (bp + bp->s.size == p->s.ptr){
		bp->s.size += p->s.ptr->s.size;
		bp->s.ptr = p->s.ptr->s.ptr;
		printf("added upper\n");
	}
	else bp->s.ptr = p->s.ptr;
	
	if (p + p->s.size == bp) {
		p->s.size += bp->s.size;
		p->s.ptr = bp->s.ptr;
		printf("added lower\n");
	}
	else p->s.ptr = bp;
	
	head = p;
}
