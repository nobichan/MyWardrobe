//
//  main.c
//  scanner
//
//  Created by USER on 2013/09/07.
//  Copyright (c) 2013年 USER. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, const char * argv[])
{
	int		c;
	char	token[BUFSIZ] = "";
	int		tokenpos = 0;
	int		linepos = 0;

	while ((c = getchar()) != EOF) {
		if (isgraph(c)) {
			// visible character
			if (ispunct(c)) {
				// token delimita
				printf("[%s] 1 \n", token);
				memset(token, 0x0a, sizeof(token));
				if (':' == c) {
					printf("|%c| ':' \n", c);
					c = getchar();
					if (':' == c) {
						// class method declare
					}
					else {
						ungetc(c, stdin);
					}
				}
				else {
					printf("|%c| SYM \n", c);
					// iroiro na kigou
				}
			}
			else if (isalpha(c)) {
				printf("|%c| ALPHABET \n", c);
				// alpha beta
				token[tokenpos] = c;
				tokenpos++;
			}
			else if (isdigit(c)) {
				printf("|%c| NUMERIC \n", c);
				// numbers
				token[tokenpos] = c;
				tokenpos++;
			}
			else {
				printf("|%c| OTHER 1 \n", c);
			}
		}
		else if (isspace(c)) {
			// token delimita
			printf("[%s] 2 \n", token);
			memset(token, 0x0a, sizeof(token));

			if (0x0a == c) {
				printf("|%c| NL \n", c);
				// NL
				linepos++;
			}
			else {
				printf("|%c| SPACE \n", c);
				// other white space
			}
		}
		else if (iscntrl(c)) {
			printf("|%c| CNTRL \n", c);
			// NULL ??
		}
		else {
			printf("|%c| OTHER 2 \n", c);
			// arienai
		}
	}
	
	return 0;
}

