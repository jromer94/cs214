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
			//do everything we need for the file we are in
			return 1;
		}
        printf("Error in opening input directory\n");
        return -1;
    }
	
	while ((directfile = readdir(directory))) {
		ifp = fopen(directfile->d_name, "r");
		if (ifp == NULL)
        {
            printf("Error in opening input file\n");
			return -1;
        }
		
		//do everything we need for the file at we are currently in
		fclose(ifp);
	}
    
    
    fclose(ofp);
}