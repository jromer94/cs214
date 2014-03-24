//
//  main.c
//  Assignment4
//
//  Created by Alex McCullough on 3/24/14.
//  Copyright (c) 2014 Alex McCullough. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{

	if (argc !=2){
		printf("Error, incorrect number of arguements");
		return -1;
	}
		
	
	FILE *ifp;
	
	if ((ifp = fopen(argv[1], "r")) == NULL){
		printf("Error opening input file");
		return -1;
	}
	
	int q = 1;
	
	while (q !=0) {
		
	
		
		
	
		
		
	}
	
	fclose(ifp);
}

