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
#include "uthash.h"
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


void hashFile(FILE fp, char* file){

	char* string;

        while(1){

                fpos_t* pos = (fpos_t*) malloc(sizeof(fpos_t));

                fgetpos(fp, pos);

                int temp = fgetc(fp);

                if(isalnum(temp)){

                        fsetpos(fp, pos);

                        fscanf(fp, "%m[a-zA-Z0-9]", &string);

			addToken(string, file);
                        //printf("%s\n", string);



                }


                if(feof(fp))

                        break;

                }
	

}
