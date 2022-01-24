#include <unistd.h>

int	main(void)
{
	char	test[33];
	int		idx = 0;

	while (idx < 33)
	{
		test[idx] = idx;
		++idx;
	}
	test[32] = 127;
	write(1, test, 33);
	return (0);
}
