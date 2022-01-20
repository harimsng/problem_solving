#include <unistd.h>

int		my_atoi(const char *s);
void	put_uint(unsigned int num);

int	main(void)
{
	char	buf[6] = {0, };
	int		quantity;
	int		five;

	read(0, buf, 5);
	quantity = my_atoi(buf);
	five = quantity / 5;
	quantity -= five * 5;
	while (five && quantity % 3 != 0)
	{
		quantity += 5;
		--five;
	}
	if (quantity % 3 == 0)
		put_uint(five + quantity / 3);
	else
		write(1, "-1", 2);
	return (0);
}

int		my_atoi(const char *s)
{
	int		ret = 0;

	while (*s >= 48 && *s < 58)
		ret = ret * 10 + *s++ - 48;
	return (ret);
}

void	put_uint(unsigned int num)
{
	unsigned int	den = 1000;
	char			buf[5] = {0, };
	int				idx = 0;

	while (den && !(num / den))
		den /= 10;
	while (den)
	{
		buf[idx++] = num / den + 48;
		num %= den;
		den /= 10;
	}
	write(1, buf, idx);
}
