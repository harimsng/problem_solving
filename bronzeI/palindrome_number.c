#include <stdio.h>

void	check_palindrome(char *left);

static const char	*ans = "yes\0no\0";

int	main(void)
{
	char	buf[7] = {0, };

	fgets(buf, 7, stdin);
	while (buf[0] + buf[1] != 58)
	{
		check_palindrome(buf);
		fgets(buf, 7, stdin);
	}
	return (0);
}

void	check_palindrome(char *left)
{
	char	*right = left;

	while (*right >= 48 && *right < 58)
		++right;
	--right;
	while ((left < right) + (*left == *right) == 2)
	{
		++left;
		--right;
	}
	fprintf(stdout, "%s\n", ans + 4 * (left < right));
}
