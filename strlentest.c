#include <time.h>
#include <string.h>
#include <stdio.h>

size_t	my_strlen(char *s);

int	main(void)
{
	char	buf[1000001] = {0, };
	clock_t	start, end;
	double	time1, time2;

	memset(buf, 0xffffffff, 1000000);
	start = clock();
	printf("%zu ", my_strlen(buf));
	end = clock();
	time1 = (double)(end - start) / CLOCKS_PER_SEC;

	start = clock();
	printf("%zu ", strlen(buf));
	end = clock();
	time2 = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\ntime1 = %f\ntime2 = %f\n", time1, time2);
	return (0);
}

size_t	my_strlen(char *s)
{
	size_t	len = 0;

	while (s[len])
		++len;
	return (len);
}
