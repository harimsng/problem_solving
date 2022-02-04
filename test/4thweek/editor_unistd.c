#include <unistd.h>
#include <stdio.h>
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
	t_node	*cur_node;
	size_t	size;
}			t_dll;

static int	my_atoi(char **inst_ptr);
static void	string_to_list(char **p, t_dll *str_list);
static void	print_list(t_dll *str_list);

static void	push_at(char **inst_ptr, t_dll *str_list);
static void	move_left(char **inst_ptr, t_dll *str_list);
static void	move_right(char **inst_ptr, t_dll *str_list);
static void	delete_letter(char **inst_ptr, t_dll *str_list);

int	main(void)
{
	t_dll		str_list = {NULL, NULL, NULL, 0};
	char		buf[BUF_SIZE] = {0, };
	char		*inst_ptr = buf;
	size_t		inst_len;
	size_t		idx = 0;

	read(0, buf, BUF_SIZE - 1);
	string_to_list(&inst_ptr, &str_list);
	inst_len = my_atoi(&inst_ptr);
	fwrite(buf, 1, BUF_SIZE, stdout);
	while (idx < inst_len)
	{
		switch (*inst_ptr)
		{
			case 'P':
				push_at(&inst_ptr, &str_list);
				break;
			case 'L':
				move_left(&inst_ptr, &str_list);
				break;
			case 'D':
				move_right(&inst_ptr, &str_list);
				break;
			case 'B':
				delete_letter(&inst_ptr, &str_list);
				break;
			default:
	//			write(2, "wrong instruction.\n", 19);
				break;
		}
		++idx;
	}
	print_list(&str_list);
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

void	string_to_list(char **ptr, t_dll *str_list)
{
	char	*s = *ptr;
	t_node	*node;
	size_t	size = 1;

//	if (s == NULL || *s == 0)
//		return ;
	str_list->head = malloc(sizeof(t_node));
//	if (str_list->head == NULL)
//	{
//		perror("");
//		return ;
//	}
	*(str_list->head) = (t_node){NULL, NULL, *s++};
	node = str_list->head;
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
	str_list->tail = malloc(sizeof(t_node));
	node->next = str_list->tail;
	str_list->cur_node = str_list->tail;
	*(str_list->tail) = (t_node){NULL, node, 0};
	str_list->size = size;
	*ptr = s + 1;
}

void	push_at(char **inst_ptr, t_dll *str_list)
{
	t_node	*node = malloc(sizeof(t_node));

//	if (node == NULL)
//	{
//		perror("");
//		return ;
//	}
	if (str_list->cur_node != str_list->head)
	{
		str_list->cur_node->prev->next = node;
		node->prev = str_list->cur_node->prev;
		str_list->cur_node->prev = node;
	}
	else
	{
		node->next = str_list->head;
		str_list->head->prev = node;
		str_list->head = node;
		node->prev = NULL;
	}
	node->next = str_list->cur_node;
	++str_list->size;

	node->letter = (*inst_ptr)[2];
	*inst_ptr += 4;
}

void	move_left(char **inst_ptr, t_dll *str_list)
{
	*inst_ptr += 2;
	if (str_list->cur_node != str_list->head)
		str_list->cur_node = str_list->cur_node->prev;
}

void	move_right(char **inst_ptr, t_dll *str_list)
{
	*inst_ptr += 2;
	if (str_list->cur_node != str_list->tail)
		str_list->cur_node = str_list->cur_node->next;
}

void	delete_letter(char **inst_ptr, t_dll *str_list)
{
	t_node	*node;
	t_node	*del_node;

	*inst_ptr += 2;
	node = str_list->cur_node;
	if (node == str_list->head)
		return ;
	del_node = node->prev;
	node->prev = del_node->prev;
	if (del_node != str_list->head)
		node->prev->next = node;
	else
		str_list->head = node;
	--str_list->size;
	free(del_node);
}

void    print_list(t_dll *str_list)
{
	char	*buf = malloc(str_list->size);
	size_t	len = str_list->size;
	size_t	idx = 0;
    t_node  *node = str_list->head;

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
