#include <stdio.h>

int	get_what(int c);

int	main(void)
{
	char	buf[102] = {0, };
	char	*ptr;
	int		count[4];

	while (fgets(buf, 102, stdin))
	{
		ptr = buf;
		count[0] = 0;
		count[1] = 0;
		count[2] = 0;
		count[3] = 0;
		while (*ptr != '\n')
			++count[get_what(*ptr++)];
		printf("%d %d %d %d\n", count[0], count[1], count[2], count[3]);
	}
	return (0);
}

int	get_what(int c)
{
	return ((c >= 65 && c <= 90)
			+ 2 * (c >= 48 && c <= 57)
			+ 3 * (c == 32));
}
