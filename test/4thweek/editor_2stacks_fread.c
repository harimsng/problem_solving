#include <stdio.h>

typedef struct
{
	char	stack[600001];
	size_t	size;
}		t_stack;

static size_t	my_strlen(char *s); 
static void		move_left(void);
static void		move_right(void);
static void		delete_left(void);
static void		push_left(void);

typedef void (*stack_func)(void);

static stack_func	inst_table[15] =
{
	delete_left,
	NULL,
	move_right,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	move_left,
	NULL,
	NULL,
	NULL,
	push_left,
};
static t_stack	left, right;
static char		*g_inst_ptr;

int	main(void)
{
	char	inst_buf[2000001] = {0, };
	size_t	inst_len = 0;
	size_t	idx = 0;

	g_inst_ptr = inst_buf;
	fscanf(stdin, "%s", left.stack);
	left.size = my_strlen(left.stack);
	fscanf(stdin, " %zu ", &inst_len);
	fread(inst_buf, 8, 250000, stdin);
//	fscanf(stdin, "%[^EOF]", inst_buf);
	while (idx < inst_len)
	{
		inst_table[(int)(*g_inst_ptr - 66)]();
		++idx;
	}
	fwrite(left.stack, 1, left.size, stdout);
	fwrite(right.stack + 600000 - right.size, 1, right.size, stdout);
	return (0);
}

static size_t	my_strlen(char *s)
{
	size_t	len = 0;

	while (s[len])
		++len;
	return (len);
}

static void	move_left(void)
{
	g_inst_ptr += 2;
	if (left.size == 0)
		return ;
	right.stack[599999 - right.size++] = left.stack[left.size - 1];
	left.stack[left.size - 1] = 0;
	--left.size;
}

static void	move_right(void)
{
	g_inst_ptr += 2;
	if (right.size == 0)
		return ;
	left.stack[left.size++] = right.stack[599999 - right.size + 1];
	right.stack[599999 - right.size + 1] = 0;
	--right.size;
}

static void	delete_left(void)
{
	g_inst_ptr += 2;
	if (left.size == 0)
		return ;
	left.stack[left.size-- - 1] = 0;
}

static void	push_left(void)
{
	left.stack[left.size++] = g_inst_ptr[2];
	g_inst_ptr += 4;
}
