#include <stdio.h>

int main(void)
{
	char c = 'a';
	printf("Hello World %d\n", c);
	c = 'a';
	printf("Hello World %d\n", c);

	int a = {10, 5, 100, 7};

	char str[6] = {'h', 'e', 'l', 'l', 'o', 0};
	// equivalent to:
	// char str[6] = "hello";
	// the array length is optional:
	// char str[0] = "hello";

	int i = 0;
	while (str[i] != 0)
	{
		printf("%c", str[i]);
	}

	return 0;
}
