//
//  tokenizer.c
//  CS214
//
//  Created by Alex McCullough on 1/30/14.
//  Copyright (c) 2014 Alex McCullough. All rights reserved.
//

/*
 * tokenizer.c
 */

#include <stdio.h>

/*
 * Tokenizer type.  You need to fill in the type as part of your implementation.
 */

struct TokenizerT_ {
    char* deliminator;
    char* ts;
};

typedef struct TokenizerT_ TokenizerT;

/*
 * TKCreate creates a new TokenizerT object for a given set of separator
 * characters (given as a string) and a token stream (given as a string).
 *
 * TKCreate should copy the two arguments so that it is not dependent on
 * them staying immutable after returning.  (In the future, this may change
 * to increase efficiency.)
 *
 * If the function succeeds, it returns a non-NULL TokenizerT.
 * Else it returns NULL.
 *
 * You need to fill in this function as part of your implementation.
 */

TokenizerT *TKCreate(char *separators, char *ts) {
    TokenizerT *token = malloc(sizeof(TokenizerT));
    
    token->deliminator = separators;
    token->ts = ts;
    
    return token;
}

/*
 * TKDestroy destroys a TokenizerT object.  It should free all dynamically
 * allocated memory that is part of the object being destroyed.
 *
 * You need to fill in this function as part of your implementation.
 */

void TKDestroy(TokenizerT *tk) {
}

/*
 * TKGetNextToken returns the next token from the token stream as a
 * character string.  Space for the returned token should be dynamically
 * allocated.  The caller is responsible for freeing the space once it is
 * no longer needed.
 *
 * If the function succeeds, it returns a C string (delimited by '\0')
 * containing the token.  Else it returns 0.
 *
 * You need to fill in this function as part of your implementation.
 */

char *TKGetNextToken(TokenizerT *tk) {
    
    return NULL;
}

/*
 * main will have two string arguments (in argv[1] and argv[2]).
 * The first string contains the separator characters.
 * The second string contains the tokens.
 * Print out the tokens in the second string in left-to-right order.
 * Each token should be printed on a separate line.
 */

int main(int argc, char **argv) {
    
	if (argc != 3){
		printf("Error: Command line should have 2 arguments. ./tokenizer <separator(s)> <token(s)>.");
		return -1;
	}
    
    printf("%s", TKCreate(argv[1], argv[2])->ts);
    
    /*if (strcmp(argv[1], "")){
        int i;
        for (i = 0; i < sizeof(argv[2]); i--){
            
        }
    }*/
	
	
    return 0;
}

