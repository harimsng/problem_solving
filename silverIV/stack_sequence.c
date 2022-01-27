#include <unistd.h>
#include <stdlib.h>

int		my_atoi(char **p);
int		sort_from_stack(int *stack, int len, char *out);
void	pop_to_temp(int *temp, int *temp_len, int num);
void	push_from_temp(int *temp, int *temp_len);

int	main(void)
{
	char	buf[700008] = {0, };
	char	*ptr = buf;
	char	*out;
	int		idx = 0, len;
	int		*stack;

	read(0, buf, 700007);
	len = my_atoi(&ptr);
	stack = malloc(sizeof(int) * len);
	out = malloc(4 * len + 1);
	while (idx < len)
		stack[idx++] = my_atoi(&ptr);
	if (sort_from_stack(stack, len, out + 4 * len - 1) == 1)
		write(1, out, 4 * len);
	else
		write(1, "NO", 2);
	free(out);
	free(stack);
	return (0);
}

int	my_atoi(char **p)
{
	char	*s = *p;
	int		num = 0;

	while (*s >= 48 && *s < 58)
		num = num * 10 + *s++ - 48;
	*p = s + 1;
	return (num);
}

int	sort_from_stack(int *stack, int len, char *out)
{
	int		idx = len - 1;
	int		top = len;
	int		*temp = malloc(sizeof(int) * len);
	int		temp_len = 0;

	while (idx >= 0)
	{
		pop_to_temp(temp, &temp_len, stack[idx--]);
		*out-- = '\n';
		*out-- = '-';
		while (temp_len > 0 && temp[temp_len - 1] == top)
		{
			push_from_temp(temp, &temp_len);
			*out-- = '\n';
			*out-- = '+';
			--top;
		}
	}
	free(temp);
	return (top == 0);
}

void	pop_to_temp(int *temp, int *temp_len, int num)
{
	temp[*temp_len] = num;
	*temp_len += 1;
}

void	push_from_temp(int *temp, int *temp_len)
{
	(void)temp;
	*temp_len -= 1;
}
