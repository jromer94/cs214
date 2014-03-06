//
//  main.c
//  Assignment3
//
//  Created by Alex McCullough on 3/3/14.
//  Copyright (c) 2014 Alex McCullough. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "uthash.h"		// found at uthash FILL THIS IN123801204729318749327143218473219874982314

#include "indexer.h"
#include <dirent.h>


// the hashFile function takes in a file pointer and string of file name in order to tokenize the
// contents of the file.  it also calls add_token to add the tokens into our hashmap and sorted list
void hashFile(FILE *fp, char* file){

	char* string;
	int i;
	string = malloc(sizeof(3));
	while(1)
	{

		fpos_t* pos = (fpos_t*) malloc(sizeof(fpos_t));

		fgetpos(fp, pos);

		int temp = fgetc(fp);

		if(isalnum(temp))
		{
			fsetpos(fp, pos);

			fscanf(fp, "%m[a-zA-Z0-9]", &string);
			for(i = 0; string[i]; i++){
				string[i] = tolower(string[i]);
			}

			add_token(string, file);
			free(string);

		}

		if(feof(fp))
			break;
	}
	fclose(fp);
}


// openDirent is a recursive function which opens the directories and all files/directories within it

void openDirent(DIR *directory, struct dirent* directfile, char* currdir, FILE* ifp){
			
	while ((directfile = readdir(directory)) != NULL) {
		
		char* combined = malloc(strlen(currdir) + strlen(directfile->d_name) + 2);
		strcpy(combined, currdir);
		strcat(combined, "/");
		strcat(combined, directfile->d_name);
		printf("combined: %s\n", combined, directfile->d_name);
		if(directfile->d_name[0] == '.'){
					
			continue;	
		}

		DIR* direct;
		
		direct = opendir(combined);
		if (direct == NULL)
        {

		ifp = fopen(combined, "r");
		hashFile(ifp, combined);
        } else {

		openDirent(direct, directfile, combined, ifp);
	
	}
		
		free(combined);	
		

	}

}

int main(int argc, char **argv) {

    FILE *ofp, *ifp;
	DIR *directory;
	struct dirent* directfile;

    ofp = fopen(argv[1], "w");
    if(ofp == NULL)
    {
        printf("Error in opening output file\n");
        return -1;
    }
	else fprintf(ofp, "%s", print_token());
	
	directory = opendir(argv[2]);
	if (directory == NULL)
	{
		if ((ifp = fopen(argv[2], "r")) == NULL)
		{
			printf("Error in opening input file\n");
			return -1;
		}
		else if ((ifp = fopen(argv[2], "r")) != NULL){
			hashFile(ifp, argv[2]);
			sorter();
			print_token();

			return 1;
		}
        printf("Error in opening input directory\n");
        return -1;
    }

	openDirent(directory, directfile, argv[2], ifp);
	print_token();
	/*while ((directfile = readdir(directory)) != NULL) {
		printf("%s", directfile->d_name);
		ifp = fopen(directfile->d_name, "r");
		if (ifp == NULL)
        {
            printf("Error in opening input file\n");
			return -1;
        }
		hashFile(ifp, directfile->d_name);
		sorter();
		print_token();
	}*/
    closedir(directory);
    
    fclose(ofp);
}
