#include <unistd.h>

int	main(void)
{
	char			buf[11] = {0, };
	long long int	num = 0;
	int				idx = 0;

	read(0, buf, 3);
	buf[1] = ((buf[0] - 48) % (buf[2] - 48)) + 48;
	buf[0] = ((buf[0] - 48) / (buf[2] - 48)) + 48;
	num = (1000000000LL * (buf[1] - 48)) / (buf[2] - 48);
	buf[1] = '.';
	while (idx < 9)
	{
		buf[10 - idx] = num % 10 + 48;
		num /= 10;
		++idx;
	}
	write(1, buf, 11);
	return (0);
}
