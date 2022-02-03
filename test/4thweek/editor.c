#include <stdio.h>
#include <stdlib.h>

#define INIT_MAX (100010)

#ifdef DFLAG
# define	DEBUG(M, ...) fprintf(stderr, "%s:%s:%d: " M "\n",\
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
	t_dll	list;
	char	buf[INIT_MAX + 1] = {0, };
	char	*inst_buf;
	char	*inst_ptr;
	size_t	idx = 0, inst_len;

	list = (t_dll){NULL, NULL, NULL, 0};
	fgets(buf, INIT_MAX + 1, stdin);
	string_to_list(&list, buf);
	fscanf(stdin, "%zu\n", &inst_len);
	inst_buf = malloc(4 * inst_len + 1);
	inst_ptr = inst_buf;
	fscanf(stdin, "%[^\0]", inst_buf);
	DEBUG("inst_buf = %s", inst_buf);
	DEBUG("inst_len = %zu", inst_len);
	while (idx < inst_len)
	{
		DEBUG("%zuth loop: %c", idx, *inst_ptr);
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
				break;
		}
		DEBUG("%zuth loop ends", idx);
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
		DEBUG("transition %zu %c %hhd", idx, str[idx], str[idx]);
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
	DEBUG("move_right %c", list->cur->letter);
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
	DEBUG("cur addr: %p", list->cur);
	DEBUG("head addr: %p", list->head);
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

	DEBUG("list size: %zu", size);
	DEBUG("print starts");
	while (idx < size)
	{
		DEBUG("print %zuth loop", idx);
		buf[idx] = node->letter;
		++idx;
		DEBUG("print %zuth loop mid", idx);
		node = node->next;
		free(node->prev);
	}
	buf[idx] = 0;
	fprintf(stdout, "%s", buf);
	free(buf);
	DEBUG("print ends");
}
