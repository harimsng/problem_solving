#include <unistd.h>
#include <stdlib.h>

#define MAX_STR_SIZE (100001)
#define MAX_INST (500000 * 4 + 1)
#define INST_DIGIT (7)
#define BUF_SIZE (MAX_STR_SIZE + INST_DIGIT + MAX_INST)

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

static int	my_atoi(char **inst_ptr);
static void	string_to_list(char **p, t_dll *list);
static void	print_list(t_dll *list);

static void	push_at(char **inst_ptr, t_dll *list);
static void	move_left(char **inst_ptr, t_dll *list);
static void	move_right(char **inst_ptr, t_dll *list);
static void	delete_letter(char **inst_ptr, t_dll *list);

int	main(void)
{
	t_dll		list = {NULL, NULL, NULL, 0};
	char		buf[BUF_SIZE] = {0, };
	char		*inst_ptr = buf;
	size_t		inst_len;
	size_t		idx = 0;

	read(0, buf, BUF_SIZE - 1);
	string_to_list(&inst_ptr, &list);
	inst_len = my_atoi(&inst_ptr);
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
				write(2, "wrong instruction.\n", 19);
				break;
		}
		++idx;
	}
	print_list(&list);
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

void	string_to_list(char **ptr, t_dll *list)
{
	char	*s = *ptr;
	t_node	*node;
	size_t	size = 1;

//	if (s == NULL || *s == 0)
//		return ;
	list->head = malloc(sizeof(t_node));
//	if (list->head == NULL)
//	{
//		perror("");
//		return ;
//	}
	*(list->head) = (t_node){NULL, NULL, *s++};
	node = list->head;
	while (*s != '\n')
	{
		node->next = malloc(sizeof(t_node));
//		if (node->next == NULL)
//		{
//			perror("");
//			return ;
//		}
		*(node->next) = (t_node){NULL, node, *s++};
		node = node->next;
		++size;
	}
	list->tail = malloc(sizeof(t_node));
	node->next = list->tail;
	list->cur = list->tail;
	*(list->tail) = (t_node){NULL, node, 0};
	list->size = size;
	*ptr = s + 1;
}

void	push_at(char **inst_ptr, t_dll *list)
{
	t_node	*node = malloc(sizeof(t_node));

//	if (node == NULL)
//	{
//		perror("");
//		return ;
//	}
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

void    print_list(t_dll *list)
{
	char	*buf = malloc(list->size);
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
	write(1, buf, len);
	free(buf);
	free(node);
}
