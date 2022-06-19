#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int				num;
	struct s_node	*next;
}			t_node;

typedef struct s_list
{
	t_node		*head;
	int			size;
}			t_list;

int		my_atoi(char **p);
int		my_strlen(char *s);
void	insert_at(t_list *list, int who, int num);
void	print_list(t_list *list);

int	main(void)
{
	t_list	list = {malloc(sizeof(t_node)), 1};
	char	buf[405] = {0, };
	char	*buf_ptr = buf;
	char	*out_ptr;
	int		who = 2;
	int		test_len;

	list.head->num = 1;
	fscanf(stdin, "%[^EOF]", buf);
	test_len = my_atoi(&buf_ptr) + 1;
	out_ptr = buf_ptr;
	my_atoi(&buf_ptr);
	while (who < test_len)
	{
		insert_at(&list, who, my_atoi(&buf_ptr));
		++who;
	}
	print_list(&list);
}

void	insert_at(t_list *list, int who, int num)
{
	int		list_idx = who - num - 1;
	t_node	*node = list->head;
	t_node	*temp;

	++list->size;
	if (list_idx == 0)
	{
		node = malloc(sizeof(t_node));
		node->next = list->head;
		node->num = who;
		list->head = node;
		return ;
	}
	while (--list_idx)
		node = node->next;
	temp = node->next;
	node->next = malloc(sizeof(t_node));
	node = node->next;
	node->num = who;
	node->next = temp;
}

void	print_list(t_list *list)
{
	int		size = list->size;
	char	buf[401] = {0, };
	char	*buf_ptr = buf;
	t_node	*node = list->head;

	while (size--)
	{
		sprintf(buf_ptr, "%d ", node->num);
		while (*buf_ptr >= 48 && *buf_ptr < 58)
			++buf_ptr;
		++buf_ptr;
		node = node->next;
	}
	fprintf(stdout, "%s", buf);
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

int	my_strlen(char *s)
{
	int	len = 0;

	while (s[len])
		++len;
	return (len);
}
