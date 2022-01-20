#include <unistd.h>

int		my_atoi(char **ptr);
void	my_putnbr(int num);
int		bin_coef(int n, int k);

int	main(void)
{
	char	buf[6] = {0, };
	char	*ptr = buf;
	int		up, down;

	read(0, buf, 5);
	up = my_atoi(&ptr);
	down = my_atoi(&ptr);
	my_putnbr(bin_coef(up, down));
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
	int		idx = 0;
	int		den = 1000000000;

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

int		bin_coef(int n, int k)
{
	int		idx = 0;
	int		ret = 1;
	
	if (k > n / 2)
		k = n - k;
	while (idx < k)
	{
		ret *= n;
		--n;
		++idx;
	}
	while (k)
	{
		ret /= k;
		--k;
	}
	return (ret);
}
