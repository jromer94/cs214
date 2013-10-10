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
	printf("lolofdfdasfd/n");

	FILE *data; 
	data = fopen(argv[2], "r");
	printf("lolofdfdasfd/n");
	int top;
	top = atoi(argv[1]);

	struct 	memory *root;
	root = malloc(sizeof(struct memory));
	struct memory *current;
	char temp[15];	
	int order = 0;
	root->occurences = 0;
	printf("lolofdfdasfd/n");

	while(NULL != fgets(temp, 15, data)) {

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
		
		if(exist == 0) {
			
			struct memory *new = malloc(sizeof(struct memory));
			order++;
			strcpy(new->memAdd,temp);
			new->occurences = 0;
			new->next = 0;
			new->fileLoc = order;
			current->next = new;			

		}
	} 
	
		
	if(top > order) {

		printf("number of arguments exceeds total number of unique addresses /n");
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
		
			while(current->next != 0) {

				if(current->occurences >= max->occurences && current->fileLoc < max->fileLoc){

					prevMax=prev;
					max=current;			

				}
			
				prev=current;
				current=current->next;

			}

			if(max == prevMax){

				printf("stuff goes here");
				root=root->next;	

			} else {

				printf("stuff goes here");
				prevMax->next=max->next;

			}


		}

	} else {

		while(root->next != 0){

			current = root;
			prev = root;
			max = root;
			prevMax = root;		
		
			while(current->next != 0) {

				if(current->occurences >= max->occurences && current->fileLoc < max->fileLoc){

					prevMax=prev;
					max=current;			

				}
			
				prev=current;
				current=current->next;

			}

			if(max == prevMax){

				printf("stuff goes here");
				root=root->next;	

			} else {

				printf("stuff goes here");
				prevMax->next=max->next;

			}


		}

		printf("stuff goes here");
	}

	return 0;
	
}

