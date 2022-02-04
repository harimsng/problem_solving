#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_STR_SIZE (100002)

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	char			letter;
}			t_node;

typedef struct
{
	t_node	*head;
	t_node	*tail;
	t_node	*cur;
	size_t	size;
}			t_dll;

static void	string_to_list(char *s, t_dll *list);
static void	print_list(t_dll *list);
static void	push_at(char **inst_ptr, t_dll *list);
static void	move_left(char **inst_ptr, t_dll *list);
static void	move_right(char **inst_ptr, t_dll *list);
static void	delete_letter(char **inst_ptr, t_dll *list);

int	main(void)
{
	t_dll		list = {NULL, NULL, NULL, 0};
	char		buf[MAX_STR_SIZE] = {0, };
	char		*inst_buf, *inst_ptr;
	size_t		inst_len;
	size_t		idx = 0;

	fscanf(stdin, "%[^\n]", buf);
	string_to_list(buf, &list);
	fscanf(stdin, " %zu ", &inst_len);
	inst_buf = malloc(inst_len * 4);
	inst_ptr = inst_buf;
	assert(fscanf(stdin, "%[^\0]", inst_buf) == 1);
	while (idx < inst_len)
	{
		switch (*inst_ptr)
		{
			case 'P':
				push_at(&inst_ptr, &list);
				break;
			case 'L':
				move_left(&inst_ptr, &list);
				break;
			case 'D':
				move_right(&inst_ptr, &list);
				break;
			case 'B':
				delete_letter(&inst_ptr, &list);
				break;
			default:
				fprintf(stdout, "wrong instruction.\n");
				break;
		}
		++idx;
	}
	print_list(&list);
	return (0);
}

void	string_to_list(char *s, t_dll *list)
{
	t_node	*node;
	size_t	size = 1;

	list->head = malloc(sizeof(t_node));
	*(list->head) = (t_node){NULL, NULL, *s++};
	node = list->head;
	while (*s != 0)
	{
		node->next = malloc(sizeof(t_node));
		*(node->next) = (t_node){NULL, node, *s++};
		node = node->next;
		++size;
	}
	list->tail = malloc(sizeof(t_node));
	node->next = list->tail;
	list->cur = list->tail;
	*(list->tail) = (t_node){NULL, node, 0};
	list->size = size;
}

void	push_at(char **inst_ptr, t_dll *list)
{
	t_node	*node = malloc(sizeof(t_node));

	if (list->cur != list->head)
	{
		list->cur->prev->next = node;
		node->prev = list->cur->prev;
		list->cur->prev = node;
	}
	else
	{
		node->next = list->head;
		list->head->prev = node;
		list->head = node;
		node->prev = NULL;
	}
	node->next = list->cur;
	++list->size;

	node->letter = (*inst_ptr)[2];
	*inst_ptr += 4;
}

void	move_left(char **inst_ptr, t_dll *list)
{
	*inst_ptr += 2;
	if (list->cur != list->head)
		list->cur = list->cur->prev;
}

void	move_right(char **inst_ptr, t_dll *list)
{
	*inst_ptr += 2;
	if (list->cur != list->tail)
		list->cur = list->cur->next;
}

void	delete_letter(char **inst_ptr, t_dll *list)
{
	t_node	*node;
	t_node	*del_node;

	*inst_ptr += 2;
	node = list->cur;
	if (node == list->head)
		return ;
	del_node = node->prev;
	node->prev = del_node->prev;
	if (del_node != list->head)
		node->prev->next = node;
	else
		list->head = node;
	--list->size;
	free(del_node);
}

void	print_list(t_dll *list)
{
	char	*buf = malloc(list->size + 1);
	size_t	len = list->size;
	size_t	idx = 0;
	t_node  *node = list->head;

	while (idx < len)
	{
		buf[idx] = node->letter;
		node = node->next;
		free(node->prev);
		++idx;
	}
	fwrite(buf, 1, idx, stdout);
	free(buf);
	free(node);
}
