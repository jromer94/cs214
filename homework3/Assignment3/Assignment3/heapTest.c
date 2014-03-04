//
//  heapTest.c
//  Assignment3
//
//  Created by Alex McCullough on 3/4/14.
//  Copyright (c) 2014 Alex McCullough. All rights reserved.
//

#include <stdio.h>
#include "indexer.h"


int main(int argc, char **argv){
	
	
	add_token("x", "file1");
	add_token("b", "file1");
	add_token("a", "file1");
	add_token("a", "file1");
	add_token("a", "file2");
	add_token("x", "file1");
	add_token("a", "file2");
	add_token("a", "file2");


	
	sorter();

	
	print_token();
	
	
	
}