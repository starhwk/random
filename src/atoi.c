#include <stdbool.h>
#include <stdio.h>

static int atoi(const char *nptr)
{
	int ret = 0;
	bool neg = false;

	if (*nptr == '-') {
		neg = true;
		nptr++;
	}

	while (*nptr != '\0') {
		ret *= 10;
		ret += *nptr++ - '0';
	}

	if (neg)
		ret *= -1;

	return ret;
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Enter an integer string\n");
		return -1;
	}

	printf("Input string = %s\n", argv[1]);
	printf("Output integer = %d\n", atoi(argv[1]));

	return 0;
}
