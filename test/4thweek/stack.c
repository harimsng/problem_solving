#include <stdio.h>
#include <stdlib.h>

#define PUSH_FLAG ('p' + 256 * 'u')
#define POP_FLAG ('p' + 256 * 'o')
#define SIZE_FLAG ('s' + 256 * 'i')
#define EMPTY_FLAG ('e' + 256 * 'm')
#define TOP_FLAG ('t' + 256 * 'o')

typedef struct s_node
{
	struct s_node	*next;
	int				num;
}			t_node;

typedef struct
{
	t_node		*head;
	size_t		size;
}			t_linked_list;

static void	list_push(t_linked_list *list, int num);
static void	list_pop(t_linked_list *list);
static void	list_size(t_linked_list *list);
static void	list_empty(t_linked_list *list);
static void	list_top(t_linked_list *list);

int	main(void)
{
	t_linked_list	list;
	char			buf[12] = {0, };
	size_t			size;
	size_t			flag;

	list = (t_linked_list){NULL, 0};
	fscanf(stdin, "%zu\n", &size);
	while (fgets(buf, 12, stdin))
	{
		flag = buf[0] + 256 * buf[1];
		switch (buf[0] + 256 * buf[1])
		{
			case PUSH_FLAG:
				list_push(&list, atoi(buf + 5));
				break;	
			case POP_FLAG:
				list_pop(&list);
				break;	
			case SIZE_FLAG:
				list_size(&list);
				break;	
			case EMPTY_FLAG:
				list_empty(&list);
				break;	
			case TOP_FLAG:
				list_top(&list);
				break;	
			default:
				break;
		}
	}
	return (0);
}

void	list_push(t_linked_list *list, int num)
{
	t_node	*node;

	if (list->size == 0)
	{
		list->head = malloc(sizeof(t_node));	
		node = list->head;
		node->next = NULL;
		node->num = num;
		++list->size;
		return ;
	}
	node = malloc(sizeof(t_node));
	node->next = list->head;
	node->num = num;
	list->head = node;
	++list->size;
}

void	list_pop(t_linked_list *list)
{
	t_node	*node = list->head;

	if (node == NULL)
	{
		printf("-1\n");
		return ;
	}
	printf("%d\n", node->num);
	list->head = node->next;
	--list->size;
	free(node);
}

void	list_size(t_linked_list *list)
{
	printf("%zu\n", list->size);
}

void	list_empty(t_linked_list *list)
{
	if (list->size)
		printf("0\n");
	else
		printf("1\n");
}

void	list_top(t_linked_list *list)
{
	if (list->size == 0)
		printf("-1\n");
	else
		printf("%d\n", list->head->num);
}
