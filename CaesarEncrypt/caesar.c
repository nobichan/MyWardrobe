#include <stdio.h>

main(int argc, char *arcv[])
{
	int c = 0;
	int i = 0;
	int shift = 0;
	char token[BUFSIZ] = "";
	while ((c = getchar()) != ' ') {
		token[i++] = c;
	}
	shift = atoi(&(token[1]));
	if (token[0] == '-') {
		shift *= -1;
	}
	while ((c = getchar()) != EOF) {
		if (('A' <= c && c <= 'Z') ||
			('a' <= c && c <= 'z')) {
			c -= shift;
			if (('Z' < c && c < 'a') ||
				(c < 'A')){
				c += ('Z' - 'A' + 1);
			}
		}
		putchar(c);
	}
}

