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
#include <string.h>

/*
 * Tokenizer type.  You need to fill in the type as part of your implementation.
 */

struct TokenizerT_ {
    char* deliminator;
    char* ts;
};

typedef struct _Token {
	
	char* ts;
	struct _Token* next;	


} Token;

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

	free(tk);
	return;

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

	int i;	
	int j;
	
	for(i = 0; i < strlen(tk->ts); i++){


		for(j = 0; j < strlen(tk->deliminator); j++){
			
			
			if (tk->deliminator[j] == '\\'){
                		if (tk->deliminator[j + 1] == 'n' || tk->deliminator[j + 1] == 't' || tk->deliminator[j + 1] == 'v' || tk->deliminator[j + 1] == 'v' || tk->deliminator[j + 1] == 'b' || tk->deliminator[j + 1] == 'r' || tk->deliminator[j + 1] == 'f' || tk->deliminator[j + 1] == 'a' || tk->deliminator[j + 1] == '\\' || tk->deliminator[j + 1] == '\"'){

					if(tk->deliminator[j] == tk->ts[i] && tk->deliminator[j + 1] == tk->ts[i + 1]){

						j = -2; 
						break;
					
					}


                		}
            		}else if(tk->ts[i] == tk->deliminator[j]){

				j = -1;
				break;

			}
			j++;

		}	

		if(tk->ts[i] == '\\'){

			if (tk->ts[i + 1] == 'n' || tk->ts[i + 1] == 't' ||  tk-> ts[i + 1]== 'v' || tk-> ts[i + 1]== 'v' || tk-> ts[i + 1]== 'b' || tk-> ts[i + 1]== 'r' || tk-> ts[i + 1]== 'f' || tk-> ts[i + 1]== 'a' || tk-> ts[i + 1]== '\\' || tk->ts[i + 1] == '\"'){

			i++;
			
			}

		}

		if(j == -1){

			break;
		
		}
		if(j == -2){

			break;		

		}

	}

	if(i == strlen(tk->ts)){

		char* ret;
		ret = tk->ts;
		tk->ts = 0;
		return ret;
	
	} else { 
	
		char* ret;
		printf("%d\n", j);
		ret = malloc( (i + 1) * sizeof(char));
		strncpy(ret, tk->ts, i);
		ret[i] = '\0';
		char* temp;
		tk->ts = &tk->ts[i - j];
		return ret;


	}    
	return 0;
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
    
	TokenizerT* token;
	token = TKCreate(argv[1], argv[2]);

	Token* head = malloc(sizeof(Token));
	Token* current = head;

	while(token->ts != 0){

		current->ts = TKGetNextToken(token);
		current->next = malloc(sizeof(token));
		current = current->next;
		current->ts = 0;
	
	} 

	current = head;
	while(current->ts != 0){

		if(strcmp(current->ts,"") != 0){
			
			printf("%s\n", current->ts);
		
		}
		
		current = current->next;	

	}
    
   if (strcmp(token->deliminator, "") == 0){
        int i;
        for (i = 0; i < strlen(token->ts); i++){
            if (token->ts[i] == '\\'){
                i++;
                if (token->ts[i] == 'n'){
                    printf("[0x0a]");
                }
                else if (token->ts[i] == 't'){
                    printf("[0x09]");
                }
                else if (token->ts[i] == 'v'){
                    printf("[0x0b]");
                }
                else if (token->ts[i] == 'b'){
                    printf("[0x08]");
                }
                else if (token->ts[i] == 'r'){
                    printf("[0x0d]");
                }
                else if (token->ts[i] == 'f'){
                    printf("[0x0c]");
                }
                else if (token->ts[i] == 'a'){
                    printf("[0x07]");
                }
                else if (token->ts[i] == '\\'){
                    printf("[0x5c]");
                }
                else if (token->ts[i] == '\"'){
                    printf("[0x22]");
                }
            }
            else (printf("%c", token->ts[i]));
        }
     }

	
		
    return 0;
}

