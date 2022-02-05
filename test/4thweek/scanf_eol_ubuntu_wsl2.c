#include <stdio.h>

int	main(void)
{
	char	buf[100] = {0, };
	
	fprintf(stdout, "%d\n", fscanf(stdin, "%[^\0]", buf));
	return (0);
}
