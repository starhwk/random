#include <stdio.h>
#include <stdlib.h>

static void *memcpy(void *dest, const void *src, size_t n)
{
	void *res = dest;

	while (n--)
		*(char *)dest++ = *(char *)src++;

	return res;
}

int main(int argc, char *argv[])
{
	int *dest, *res;
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

	if (dest != memcpy(dest, argv[1], n)) {
		printf("Memory copy failed\n");
		return -1;
	}

	printf("INPUT : %s\n", argv[1]);
	printf("OUTPUT: %s\n", dest);

	free(dest);

	return 0;
}
