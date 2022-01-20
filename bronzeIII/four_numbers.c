#include <unistd.h>

typedef unsigned long long int	uint64_t;

int			my_atoi(char **ptr);
uint64_t	get_len(uint64_t num);
void		put_llu(uint64_t num);

int	main(void)
{
	char		buf[33] = {0, };
	char		*ptr = buf;
	uint64_t	a, b, c, d;
	uint64_t	blen, dlen;
	
	read(0, buf, 32);
	a = my_atoi(&ptr);
	b = my_atoi(&ptr);
	blen = get_len(b);
	b = a * blen + b;
	c = my_atoi(&ptr);
	d = my_atoi(&ptr);
	dlen = get_len(d);
	d = c * dlen + d;
	put_llu(b + d);
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

uint64_t	get_len(uint64_t num)
{
	uint64_t	den = 1000000;

	while (den && !(num / den))
		den /= 10;
	return (den * 10);
}

void	put_llu(uint64_t num)
{
	char		buf[21] = {0, };
	uint64_t	den = 10000000000000000000ULL;
	int			idx = 0;

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
