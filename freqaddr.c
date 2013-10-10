#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct memory{

	char memAdd[15];
	int occurences;
	int fileLoc;
	struct memory *next;
	

}; 


int main(int argc, char **argv) {
	
	if(argc != 4){

		fprintf(stderr, "incorrect number of command line arguments");	
		return 1;

	}

	FILE *data; 
	data = fopen(argv[3], "r");
	if(!data){

		fprintf(stderr, "file not found");	
		return 1;

	}
	int top;
	top = atoi(argv[2]);

	struct 	memory *root;
	root = malloc(sizeof(struct memory));
	struct memory *current;
	char temp[15];	
	int order = 0;
	root->occurences = 0;

	while(NULL != fgets(temp, 15, data)) {
		if(strcmp(temp,"\n") == 0)
			continue;
		char *test;
		test = strstr(temp, "\n");
		if(test) {

			strncpy(test, "\0", 1);
	
		}	
		printf("%s \n",temp);
		int exist = 0; 
		if(root->occurences == 0){

			order++;
			root->next = 0;
			strcpy(root->memAdd,temp);
			root->occurences = 1;
			root->fileLoc = order;
			current = root;
			continue;

		}
		current = root;
		
		while(current->next != 0){
			
			if( strcmp(temp, current->memAdd) == 0) {
				
				current->occurences++;
				exist = 1;	
				break;	
			
			}
			current = current->next;
	
		}		
		if( strcmp(temp, current->memAdd) == 0 && exist == 0) {
				
				current->occurences++;
				exist = 1;	
			
		}
	

	
		if(exist == 0) {
			
			struct memory *new = malloc(sizeof(struct memory));
			order++;
			strcpy(new->memAdd,temp);
			new->occurences = 1;
			new->next = 0;
			new->fileLoc = order;
			current->next = new;			

		}
	} 
	current = root;
	while(current->next != 0){
		printf("TEST %s :%d\n", current->memAdd, current->occurences);
		current = current->next;

	}	
	current = root;	
	if(top > order) {

		fprintf(stderr, "number of arguments exceeds total number of unique addresses");

		return 1;
	}
	struct memory *prev;
	struct memory *max;
	struct memory *prevMax;

	if(top != 0){		
	int i;
		for(i = 0; i < top; i++) { 

			current = root;
			prev = root;
			max = root;
			prevMax = root;		
		
			while(current != 0) {

				if(current->occurences >  max->occurences){

					prevMax=prev;
					max=current;			

				}
			
				prev=current;
				current=current->next;

			}

			if(max == prevMax){

				printf("%s :%i\n",max->memAdd,max->occurences);
				root=root->next;	

			} else {

				printf("%s :%i\n",max->memAdd,max->occurences);
				prevMax->next=max->next;

			}


		}

	} else {

		while(root->next != 0){

			current = root;
			prev = root;
			max = root;
			prevMax = root;		
		
			while(current != 0) {

				if(current->occurences > max->occurences){

		
					prevMax=prev;
					max=current;			

				}
			
				prev=current;
				current=current->next;

			}

			if(max == prevMax){

				printf("%s :%i\n",max->memAdd,max->occurences);
				root=root->next;	

			} else {

				printf("%s :%i\n",max->memAdd,max->occurences);
				prevMax->next=max->next;

			}


		}
		printf("%s :%i\n",root->memAdd,root->occurences);

	}

	return 0;
	
}

