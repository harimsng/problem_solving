#include <stdio.h>

#ifdef DEBUG_FLAG
# define DEBUG(M, ...) printf("%s: %s: %d [ " M " ]\n",\
	__FILE__, __func__, __LINE__, ##__VA_ARGS__)
#else
# define DEBUG(M, ...)
#endif

static double	recur(char *buf_ptr);
static char		*find_block(char *ptr);

double	*var_ptr;

int	main(void)
{
	int		operands;
	double	variables[26] = {0, };
	char	buf[102] = {0, };
	char	*ptr = buf;

	var_ptr = variables;
	fscanf(stdin, "%d\n", &operands);
	fgets(buf, 102, stdin);
	for (int i = 0; i < operands; ++i)
		fscanf(stdin, "%f", variables + i);
	while (*ptr)
		++ptr;
	ptr -= 1 + (ptr[-1] == '\n');
	DEBUG("operands = %d", operands);
	for (int i = 0; i < operands; ++i)
		DEBUG("variables = %f", variables[i]);
	DEBUG("str = %s, ptr = %s", buf, ptr);
	printf("%.2f", recur(ptr));
	return (0);
}

static double	recur(char *buf_ptr)
{
	if (*buf_ptr >= 65 && *buf_ptr <= 90)
		return (var_ptr[*buf_ptr - 65]);
	switch (*buf_ptr)
	{
		case '+':
			return (recur(find_block(buf_ptr)) + recur(buf_ptr - 1));
			break;
		case '-':
			return (recur(find_block(buf_ptr)) - recur(buf_ptr - 1));
			break;
		case '*':
			return (recur(find_block(buf_ptr)) * recur(buf_ptr - 1));
			break;
		case '/':
			return (recur(find_block(buf_ptr)) / recur(buf_ptr - 1));
			break;
		default:
			break;
	}
	return (1);
}

static char	*find_block(char *ptr)
{
	int		count = 1;

	--ptr;
	while (count)
	{
		if (*ptr >= 42 && *ptr <= 47)
			++count;
		else
			--count;
		--ptr;
	}
	return (ptr);
}
