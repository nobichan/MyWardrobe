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

typedef enum _E_TYPE_ {
	END = -1,
	KEYWORD = 0,
	ID,
	LITERAL,
	NUMERIC,
} E_TYPE;

E_TYPE gettoken(FILE *fpin, char *token);

int main(int argc, const char * argv[])
{
//	int		c;
	char	token[BUFSIZ] = "";
	E_TYPE	type;

	FILE	*fpin;

	if (1 == argc) {
		perror("no arg.");
		return -1;
	}
	else if (2 < argc) {
		perror("too many arg.");
		return -2;
	}
	else {
		fpin = fopen(argv[1], "r");
		if (NULL == fpin) {
			perror("can not open file.");
			return -3;
		}
	}

	while (1) {
		memset(token, 0x0a, sizeof(token));
		type = gettoken(fpin, token);
		switch (type) {
			case KEYWORD :
				break;
			case ID :
				break;
			case LITERAL :
				break;
			case NUMERIC :
				break;
			case END :
				return 0;
				break;
			default :
				return 0;
				break;
		}
	}

	return 0;
}

E_TYPE gettoken(FILE *fpin, char *token)
{
	int		c;
	int		tokenpos = 0;
	int		linepos = 0;

	while ((c = fgetc(fpin)) != EOF) {
		if (isgraph(c)) {
			// visible character
			if (ispunct(c)) {
				// token delimita
				printf("[%s] 1 \n", token);

				return ID;
//				if (':' == c) {
//					printf("|%c| ':' \n", c);
//					c = getchar();
//					if (':' == c) {
//						printf("|%c| '::' \n", c);
//						// class method declare
//					}
//					else {
//						ungetc(c, stdin);
//					}
//				}
//				else {
//					printf("|%c| SYM \n", c);
//					// iroiro na kigou
//				}
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

			return ID;
//			if (0x0a == c) {
//				printf("|%c| NL \n", c);
//				// NL
//				linepos++;
//			}
//			else {
//				printf("|%c| SPACE \n", c);
//				// other white space
//			}
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
	
	return END;
}



#if 0


		type = gettoken();
	}

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
printf("|%c| '::' \n", c);
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

#endif

