#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int rle_encode(const char *string)
{
	printf("Input: %s\n", string);
	printf("Output: ");
	while (*string) {
		const char *curr;
		char encoded[2];
		unsigned int count = 1;

		if (('a' > *string || 'z' < *string) &&
				('A' > *string || 'Z' < *string)) {
			printf("\nOnly char input %s\n", string);
			return -EINVAL;
		}

		curr = string;
		while (*curr == *++string)
			count++;

		encoded[0] = *curr;
		encoded[1] = '\0';
		printf("%d%s", count, encoded);
	}
	printf("\n");

	return 0;
}

int main(int argc, char *argv[])
{
	const char *input;
	char *output;

	if (argc != 2) {
		printf("Enter a string to encode\n");
		return -1;
	}

	return rle_encode(argv[1]);
}
