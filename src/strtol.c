#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

static long int strtol(const char *nptr, const char **endptr, int base)
{
	long int ret = 0;
	bool neg = false;

	if (*nptr == '-') {
		neg = true;
		nptr++;
	}

	while (*nptr != '\0') {
		long int temp;

		if (*nptr >= 'A')
			temp = *nptr - 'a' + 10;
		else
			temp = *nptr - '0';

		if (temp >= base) {
			ret = LLONG_MAX;
			goto out;
		} else if (temp < 0) {
			ret = LLONG_MIN;
			goto out;
		}


		ret *= base;
		ret += temp;
		nptr++;
	}

	if (neg)
		ret *= -1;

out:
	if (endptr)
		*endptr = nptr;

	return ret;

}

int main(int argc, char *argv[])
{
	const char *temp;

	if (argc != 3) {
		printf("Enter a string & base\n");
		return -1;
	}

	printf("Input string = %s\n", argv[1]);
	printf("Input base = %s\n", argv[2]);
	printf("Output integer = %ld\n", strtol(argv[1], &temp,
				strtol(argv[2], &temp, 10)));
	printf("Invalid = %s\n", temp);

	return 0;
}
