#include <unistd.h>

void	putnbr(int num);

int	main(void)
{
	int		len = 0;
	int		count = 0;
	int		idx;
	char	buf[1000001] = {0, };

	len = read(0, buf, 1000000);
	if (buf[len - 1] == '\n')
	{
		buf[len - 1] = 0;
		--len;
	}
	idx = 0;
	while (idx < len)
	{
		if (buf[idx] != ' ' && (buf[idx + 1] == ' ' || buf[idx + 1] == 0))
			++count;
		++idx;
	}
	putnbr(count);
	return (0);
}

void	putnbr(int num)
{
	int		den = 1000000;
	int		idx;
	char	buf[8] = {0, };

	while (den && !(num / den))
		den /= 10;
	idx = 0;
	den += den == 0;
	while (den)
	{
		buf[idx] = num / den + 48;
		num %= den;
		den /= 10;
		++idx;
	}
	write(1, buf, idx);
}
