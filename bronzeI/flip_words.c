#include <stdio.h>

void	flip_words(char *buf);
void	swap(char *a, char *b);
size_t	my_strlen(const char *s);

int	main(void)
{
	char	buf[1002] = {0, };

	while (fgets(buf, 1002, stdin))
	{
		flip_words(buf);
		fputs(buf, stdout);
	}
	return (0);
}

void	flip_words(char *buf)
{
	char	*left, *right;

	while (*buf)
	{
		left = buf;
		right = buf;
		while (*right != ' ' && *right != '\n')
			++right;
		buf = right + 1;
		--right;
		while (left < right)
			swap(left++, right--);
	}
}

void	swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
