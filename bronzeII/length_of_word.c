#include <stdio.h>

int	main(void)
{
	char	buf[102] = {0, };
	int		len = 0;

	fgets(buf, 102, stdin);
	while (buf[len])
		++len;
	len -= buf[len - 1] == '\n';
	printf("%d", len);
	return (0);
}
