#include <stdio.h>

void func1();
void func2(char c);

int	main(void)
{
	char	a = 'a';

	func1(a);
	func2(a);
	return (0);
}

void func1(void)
{
	printf("1\n");
}

void func2(char c)
{
	
	printf("2\n");
}
