#include <stdio.h>

typedef struct
{
	char	stack[600001];
	size_t	size;
}		t_stack;

size_t	my_strlen(const char *s);

static t_stack	left, right;

int	main(void)
{
	char	*ptr;
	size_t	inst_len;
	
	fscanf(stdin, "%s", left.stack);
	left.size = my_strlen(left.stack);
	fscanf(stdin, "

	ptr = left.stack;
	while (*ptr != '\n')
		++ptr;
	while (*ptr != '\n')
		ptr++ = 0;
	ptr = 0;
}
