#include <unistd.h>

int	main(void)
{
	char	buf[3];
	int		num = 0;

	read(0, buf, 3);
	num = buf[0] - buf[2];
	if (num < 0)
	{
		buf[0] = '-';
		buf[1] = (- num) + 48;
		write(1, buf, 2);
	}
	else
	{
		buf[0] = num + 48;
		write(1, buf, 1);
	}
	return (0);
}
