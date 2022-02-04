#include <stdio.h>
#include <stdlib.h>

#define INIT_MAX (100002)

#ifdef DFLAG
# define	DEBUG(M, ...) fprintf(stdout, "%s:%s:%d: " M "\n",\
		__FILE__, __func__, __LINE__, ##__VA_ARGS__)
#else
# define	DEBUG(M, ...)
#endif

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

static void		string_to_list(t_dll *list, char *str);
static void		move_left(t_dll *list);
static void		move_right(t_dll *list);
static void		delete_left(t_dll *list);
static void		push_left(t_dll *list, char letter);
static void		print_list(t_dll *list);

int	main(void)
{
	t_dll	list = (t_dll){NULL, NULL, NULL, 0};
	char	buf[INIT_MAX + 1] = {0, };
	char	*inst_buf;
	char	*inst_ptr;
	size_t	idx = 0, inst_len;

	fscanf(stdin, "%[^\n]", buf);
	string_to_list(&list, buf);
	fscanf(stdin, " %zu ", &inst_len);
	inst_buf = malloc(4 * inst_len);
	inst_ptr = inst_buf;
	fscanf(stdin, "%[^EOF]", inst_buf);
	while (idx < inst_len)
	{
		switch (*inst_ptr)
		{
			case 'L':
				move_left(&list);
				inst_ptr += 2;
				break;
			case 'D':
				move_right(&list);
				inst_ptr += 2;
				break;
			case 'B':
				delete_left(&list);
				inst_ptr += 2;
				break;
			case 'P':
				push_left(&list, inst_ptr[2]);
				inst_ptr += 4;
				break;
			default:
				fprintf(stdout, "wrong instruction.");
				break;
		}
		++idx;
	}
	print_list(&list);
	free(inst_buf);
}

static void		string_to_list(t_dll *list, char *str)
{
	size_t		idx = 0;
	t_node		*node;

	list->head = malloc(sizeof(t_node));
	*list->head = (t_node){NULL, NULL, str[idx++]};
	node = list->head;
	while (str[idx] != '\n')
	{
		node->next = malloc(sizeof(t_node));
		node->next->prev = node;
		node = node->next;
		node->letter = str[idx];
		++idx;
	}
	list->tail = malloc(sizeof(t_node));
	*list->tail = (t_node){NULL, node, 0};
	node->next = list->tail;
	list->cur = list->tail;
	list->size = idx;
}

static void		move_left(t_dll *list)
{
	if (list->cur == list->head)
		return ;
	list->cur = list->cur->prev;
}

static void		move_right(t_dll *list)
{
	if (list->cur == list->tail)
		return ;
	list->cur = list->cur->next;
}

static void		delete_left(t_dll *list)
{
	t_node	*del_node;

	if (list->cur == list->head)
		return ;
	else if (list->cur->prev == list->head)
	{
		free(list->head);
		list->cur->prev = NULL;
		--list->size;
		list->head = list->cur;
		return ;
	}
	del_node = list->cur->prev;
	del_node->prev->next = list->cur;
	list->cur->prev = del_node->prev;
	free(del_node);
	--list->size;
}

static void		push_left(t_dll *list, char letter)
{
	t_node	*new_node = malloc(sizeof(t_node));

	new_node->letter = letter;
	++list->size;
	DEBUG("list->size : %zu", list->size);
	if (list->cur == list->head)
	{
		new_node->prev = NULL;
		new_node->next = list->head;
		if (list->head != NULL)
			list->head->prev = new_node;
		list->head = new_node;
		return ;
	}
	new_node->prev = list->cur->prev;
	new_node->next = list->cur;
	list->cur->prev->next = new_node;
	list->cur->prev = new_node;
}

static void		print_list(t_dll *list)
{
	t_node		*node = list->head;
	char		*buf = malloc(list->size + 1);
	size_t		idx = 0;
	size_t		size = list->size;

	while (idx < size)
	{
		buf[idx] = node->letter;
		node = node->next;
		free(node->prev);
		++idx;
	}
	buf[idx] = EOF;
	fprintf(stdout, "%s", buf);
	free(list->tail);
	free(buf);
}
