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

void hashFile(FILE *fp, char* file){
	
	char* string;
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
			printf("%s yes", string);

			add_token(string, file);

		}
		
		if(feof(fp))
			break;
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
	
	while ((directfile = readdir(directory)) != NULL) {
		ifp = fopen(directfile->d_name, "r");
		if (ifp == NULL)
        {
            printf("Error in opening input file\n");
			return -1;
        }
		printf("here one\n");
		hashFile(ifp, directfile->d_name);
		sorter();
		print_token();
	}
    closedir(directory);
    
    fclose(ofp);
}
