#include <unistd.h>

int		my_atoi(char **ptr);
void	my_putnbr(int num);

int	main(void)
{
	char	buf[34] = {0, };
	char	*ptr = buf;
	int		down, up, top;
	int		days = 1;

	read(0, buf, 33);
	up = my_atoi(&ptr);
	down = my_atoi(&ptr);
	top = my_atoi(&ptr);
	top -= up;
	days += top / (up - down) + !!(top % (up - down));
	my_putnbr(days);
	return (0);
}

int	my_atoi(char **ptr)
{
	char	*s = *ptr;
	int		ret = 0;
	
	while (*s >= 48 && *s < 58)
		ret = ret * 10 + *s++ - 48;
	*ptr = s + 1;
	return (ret);
}

void	my_putnbr(int num)
{
	char	buf[11] = {0, };
	int		den = 1000000000;
	int		idx = 0;

	while (den && !(num / den))
		den /= 10;
	while (den)
	{
		buf[idx] = num / den + 48;
		num %= den;
		den /= 10;
		++idx;
	}
	write(1, buf, idx);
}
