//freqaddr hw1 cs 211

#include <stdio.h>

typedef struct {

	char memAdd[15];
	int occurences;

} memory; 


int main() {

	FILE *data; 
	fp = fopen("test.dat", "rb");


	int lines = 0; 

	while(EOF != (scanf("%*[^\n]"), scanf("%*c")))
		++lines;

	
	rewind(fp);

	memory memArr[lines];
	
	int hold;
	int memLoc = 0;	
	
	for(hold = 0; hold < lines; hold++) {
		int exist = 0; 
		char temp[15];
		fgets(temp, 15, fp);
		for(int i = 0; i < memLoc; i++){
			
			if( strcmp(temp, memArr[i].memAdd) == 0) {
				
				memArr[i].occurences++;
				exist = 1;	
				break;	
			
			}
	
		}		
		
		if(exist == 0) {

			memArr[memLoc].memAdd = temp;
			memArr[memLoc].occurences = 1;
			memLoc++;
		}
	} 
		

}

