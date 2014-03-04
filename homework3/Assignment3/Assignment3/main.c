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



int main(int argc, char **argv) {
	
    FILE *ifp, *ofp;
    
    ofp = fopen(argv[1], "w");
    if(ofp == NULL)
    {
        perror("Error in opening output file");
        return -1;
    }
    ifp = fopen(argv[2], "r");
    if(ifp == NULL)
    {
        perror("Error in opening input file");
        return -1;
    }
    

    
    
    
    fclose(ifp);
    fclose(ofp);
}