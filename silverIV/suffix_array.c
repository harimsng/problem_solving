#include <unistd.h>
#include <stdlib.h>

int		my_strcmp(const void *p1, const void *p2);
void	my_strcpy(char *dst, const char *src, int len);
int		my_strlen(const char *s);

int	main(void)
{
	int		len, idx = 0, jdx = 0;
	char	str[1002] = {0, };
	char	**str_arr;
	char	*buf;

	len = read(0, str, 1001);
	if (str[len - 1] == '\n')
		str[len-- - 1] = 0;
	str_arr = malloc(sizeof(char *) * len);
	buf = malloc((len + 1) * len);
	while (idx < len)
	{
		my_strcpy(buf + jdx, str + idx, len + 1);
		str_arr[idx] = buf + jdx;
		jdx += len + 1;
		buf[jdx - 1] = '\n';
		++idx;
	}
	qsort(buf, (size_t)len, len + 1, my_strcmp);
	write(1, buf, (len + 1) * len);
	return (0);
}

int	my_strcmp(const void *p1, const void *p2)
{
	const char *s1 = (const char *)p1;
	const char *s2 = (const char *)p2;

	while (*s1 == *s2 && *s1 * *s2 != 0)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	my_strcpy(char *dst, const char *src, int len)
{
	while (*src && len--)
		*dst++ = *src++;
	while (len--)
		*dst++ = 27;
}

int		my_strlen(const char *s)
{
	int		len = 0;
	while (s[len])
		++len;
	return (len);
}
