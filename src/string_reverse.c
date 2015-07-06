#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_reverse_in(char *string)
{
	unsigned int i, len = strlen(string);

	for (i = 0; i < len / 2; i++) {
		string[i] = string[i] ^ string[len - 1 - i];
		string[len - 1 - i] = string[i] ^ string[len - 1 - i];
		string[i] = string[i] ^ string[len - 1 - i];
	}
}

char *string_reverse(char *string)
{
	unsigned int i, len = strlen(string);
	char *dest = malloc(len + 1);

	for (i = 0; i < len; i++)
		dest[len - 1 - i] = string[i];

	dest[len] = '\0';

	return dest;
}

void string_reverse_done(char *string)
{
	free(string);
}

int main(int argc, char *argv[])
{
	char *output;

	if (argc != 2) {
		printf("Enter a string to copy\n");
		return -1;
	}

	printf("Input: %s\n", argv[1]);
	string_reverse_in(argv[1]);
	printf("Reverse:  %s\n", argv[1]);
	output = string_reverse(argv[1]);
	printf("Another reverse:  %s\n", output);

	string_reverse_done(output);

	return 0;
}
