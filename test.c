#include <stdio.h>

typedef struct
{
	char	buf[9];
	int		size;
}	t_buf;

void	init(t_buf *buf);

int	main(void)
{
	t_buf	buf;
	unsigned long long int	*ptr = (unsigned long long int *)buf.buf;

	init(&buf);
	printf("%llu %d\n", *ptr, buf.size);
	return (0);
}

void	init(t_buf *buf)
{
	unsigned long long int	*ptr = (unsigned long long int *)buf->buf;

	*ptr = 10238124712497;
	printf("%llu %d\n", *ptr, buf->size);
	*buf = (t_buf){{0, }, 0};
	printf("%llu %d\n", *ptr, buf->size);
}
