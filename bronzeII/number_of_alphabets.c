#include <unistd.h>

void	putnbr(int num);
int		tolower(int c);

int	main(void)
{
	char	tab[26] = {0, };
	char	buf[102] = {0, };
	int		idx = 0, len;

	len = read(0, buf, 100);
	if (buf[len - 1] == '\n')
		--len;
	while (idx < len)
		++tab[tolower(buf[idx++]) - 97];
	idx = 0;
	while (idx < 26)
		putnbr(tab[idx++]);
	return (0);
}

void	putnbr(int num)
{
	char	buf[12] = {'0', };
	int		idx = 0;
	int		den = 1000000000;
	
	den -= den * (num == 0);
	while (den && !(num / den))
		den /= 10;
	while (den)
	{
		buf[idx++] = num / den + 48;
		num %= den;
		den /= 10;
	}
	buf[idx + !idx] = ' ';
	write(1, buf, idx + !idx + 1);
}

int		tolower(int c)
{
	return (c + 32 * (c >= 65 && c <= 90));
}
