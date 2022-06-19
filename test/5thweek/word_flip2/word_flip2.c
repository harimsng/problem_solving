#include <unistd.h>

void	flip(char *, size_t, size_t);

int	main(void)
{
	char	buffer[100002] = {0, };
	char	*ptr = buffer;
	size_t	start, end;
	ssize_t	len;

	len = read(0, buffer, 100000);
	if (buffer[len - 1] == '\n')
	{
		buffer[len - 1] = 0;
		--len;
	}
	start = 0;
	while (*ptr)
	{
		if (*ptr == '<')
		{
			end = ptr - buffer;
			flip(buffer, start, end);
			while (*ptr != '>')
				++ptr;
			start = ptr + 1 - buffer;
		}
		else if (*ptr == ' ')
		{
			end = ptr - buffer;
			flip(buffer, start, end);
			start = end + 1;
		}
		++ptr;
	}
	if (ptr[-1] != '>')
		flip(buffer, start, ptr - buffer);
	write(1, buffer, len);
	return (0);
}

void	flip(char *buf, size_t start, size_t end)
{
	char	temp;

	if (end == 0)
		return ;
	--end;
	while (start < end)
	{
		temp = buf[start];
		buf[start] = buf[end];
		buf[end] = temp;
		++start;
		--end;
	}
}
