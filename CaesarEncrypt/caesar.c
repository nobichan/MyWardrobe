#include <stdio.h>
#define	DEC	0	// DECODE mode
#define	ENC	1	// ENCODE mode
extern void usage(void);
main(int argc, char *argv[])
{
	int c = 0;
	int i = 0;
	int shift = 0;
	char token[BUFSIZ] = "";
	int conv = DEC;	// mode
	if (argc == 1 || argc > 3) {
		usage();
		exit(-1);
	}
	if (argv[1][0] == '-') {
		if (argv[1][1] == 'd') {
			conv = DEC;
		}
		else if (argv[1][1] == 'e') {
			conv = ENC;
			shift = atoi(argv[2]);
		}
	}
	else {
		usage();
		exit(-1);
	}
	if (conv == DEC) {
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
	else if (conv == ENC) {
		int a = atoi(argv[2]);
		if (a >= 0) {
			printf("+%d ", a);
		}
		else {
			printf("%d ", a);
		}
		while ((c = getchar()) != EOF) {
			if (('A' <= c && c <= 'Z') ||
				('a' <= c && c <= 'z')) {
				c += shift;
				if (( 'Z' < c && c < 'a') ||
					(c < 'A')) {
					c += ('Z' - 'A' + 1);
				}
			}
			putchar(c);
		}
	}
}
void usage(void)
{
	printf("caesar <parameter> < textfile\n");
	printf("caesar -d < textfile     : decode text file.\n");
	printf("caesar -e num < textfile : encode text file.\n");
	printf("       num : shift num.\n");
}

