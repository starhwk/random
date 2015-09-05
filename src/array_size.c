#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(arr)	sizeof(arr) / sizeof(arr[0])

static int array[128];

int main(int argc, char *argv[])
{
	printf("array_size = %lu\n", ARRAY_SIZE(array));

	return 0;
}
