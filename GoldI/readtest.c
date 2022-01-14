#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int	main(void)
{
	char	buf[10] = {0, };

	read(0, buf, 9);
	write(1, buf, 10);
	printf("%s\n", strerror(errno));
	return (0);
}
