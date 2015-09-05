#include <stdio.h>
#include <stdlib.h>

static char *strcpy(char *dest, const char *src)
{
	char *res = dest;

	while ((*dest++ = *src++));
	*dest = '\0';

	return res;
}

int main(int argc, char *argv[])
{
	char *dest, *src;
	unsigned int n = 0;

	if (argc != 2) {
		printf("Enter a string to copy\n");
		return -1;
	}

	while (argv[1][n++]) ;
	n++;

	dest = malloc(n);
	if (!dest) {
		printf("Memory allocation failed\n");
		return -1;
	}

	if (dest != strcpy(dest, argv[1])) {
		printf("String copy failed\n");
		return -1;
	}

	printf("INPUT : %s\n", argv[1]);
	printf("OUTPUT: %s\n", dest);

	free(dest);

	return 0;
}
