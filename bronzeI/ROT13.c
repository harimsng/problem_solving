#include <unistd.h>

int	main(void)
{
	char	buf[102] = {0, };
	int		idx = 0, len;

	len = read(0, buf, 102);
	while (idx < len)
	{
		if (buf[idx] >= 65 && buf[idx] <= 90)
			buf[idx] += 13 - 26 * (buf[idx] >= 78);
		else if (buf[idx] >= 97 && buf[idx] <= 122)
			buf[idx] += 13 - 26 * (buf[idx] >= 110);
		++idx;
	}
	write(1, buf, len);
	return (0);
}
