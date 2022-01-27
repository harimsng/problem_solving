#include <stdio.h>

int	verify_VPS(char *buf);

static const char	*answer[2] = {"YES\n", "NO\n"};

int	main(void)
{
	int		len;
	char	buf[52] = {0, };

	fscanf(stdin, "%d\n", &len);
	while (fgets(buf, 52, stdin))
		fputs(answer[verify_VPS(buf)], stdout);
	return (0);
}

int	verify_VPS(char *buf)
{
	static int	a;
	int		stack = 0;

	if (a != BUFFER_SIZE)
		
	while (*buf != '\n' && stack <= 0)
		stack += 2 * (*buf++ - 40) - 1;
	a = addr;
	return (stack != 0);
}
