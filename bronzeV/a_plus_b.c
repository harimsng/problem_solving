#include <unistd.h>

int	main(void)
{
	char	buf[3];
	int		num = 0;
	
	read(0, buf, 3);
	num = buf[0] + buf[2] - 96;
	buf[0] = num / 10 + 48;
	buf[1] = num % 10 + 48;
	write(1, buf + (buf[0] == 48), 1 + (buf[0] != 48));
	return (0);
}
