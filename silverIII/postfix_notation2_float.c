#include <stdio.h>

static float	recur(char *buf_ptr);
static char		*find_block(char *ptr);

float	*var_ptr;

int	main(void)
{
	int		operands;
	float	variables[26] = {0, };
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
	printf("%.2f", recur(ptr));
	return (0);
}

static float	recur(char *buf_ptr)
{
	if (*buf_ptr >= 65 && *buf_ptr <= 90)
		return (var_ptr[*buf_ptr - 65]);
	switch (*buf_ptr)
	{
		case '+':
			return (recur(find_block(buf_ptr)) + recur(buf_ptr - 1));
		case '-':
			return (recur(find_block(buf_ptr)) - recur(buf_ptr - 1));
		case '*':
			return (recur(find_block(buf_ptr)) * recur(buf_ptr - 1));
		case '/':
			return (recur(find_block(buf_ptr)) / recur(buf_ptr - 1));
		default:
			break;
	}
	return (0);
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
