#include <stdio.h>
#include <string.h>

typedef struct
{
	char	stack[600001];
	size_t	size;
}		t_stack;

int	main(void)
{
	t_stack	left, right;
	char	inst_buf[2000001] = {0, };
	char	*inst_ptr;
	size_t	inst_len = 0;
	size_t	idx = 0;

	inst_ptr = inst_buf;
	fscanf(stdin, "%s", left.stack);
	left.size = strlen(left.stack);
	fscanf(stdin, " %zu ", &inst_len);
	fscanf(stdin, "%[^EOF]", inst_buf);
	while (idx < inst_len)
	{
		switch (*inst_ptr)
		{
			case 'L':
				inst_ptr += 2;
				if (left.size == 0)
					break ;
				right.stack[599999 - right.size++] = left.stack[left.size - 1];
				left.stack[left.size - 1] = 0;
				--left.size;
				break;
			case 'D':
				inst_ptr += 2;
				if (right.size == 0)
					break ;
				left.stack[left.size++] = right.stack[599999 - right.size + 1];
				right.stack[599999 - right.size + 1] = 0;
				--right.size;
				break;
			case 'B':
				inst_ptr += 2;
				if (left.size == 0)
					break ;
				left.stack[left.size-- - 1] = 0;
				break;
			case 'P':
				left.stack[left.size++] = inst_ptr[2];
				inst_ptr += 4;
				break;
			default:
				fprintf(stderr, "wrong instruction.\n");
		}
		++idx;
	}
	fprintf(stdout, "%s", left.stack);
	fprintf(stdout, "%s", right.stack + 600000 - right.size);
	return (0);
}
