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
	
	add_token("a", "file3");
	add_token("a", "file3");
	add_token("a", "file3");
	
		
	add_token("x", "file1");
	add_token("x", "file1");
	add_token("x", "file1");

	
	add_token("x", "file3");
	add_token("x", "file3");
	add_token("x", "file3");
	add_token("x", "file3");

	add_token("b", "file1");
	
	add_token("a", "file1");
	add_token("a", "file1");
	
	
	add_token("a", "file5");
	add_token("a", "file5");
	add_token("a", "file5");
	add_token("a", "file5");
	add_token("a", "file5");
	add_token("a", "file5");

	
	add_token("a", "file7");
	add_token("a", "file7");
	add_token("a", "file7");
	add_token("a", "file7");
	add_token("a", "file7");
	add_token("a", "file7");
	add_token("a", "file7");

	add_token("a", "file9");
	add_token("a", "file10");
	add_token("a", "file10");

	
	sorter();

	
	print_token();
	
	
	
}