#include <stdio.h>
#include <stdlib.h>

enum e_inst_keys
{
	PUSH_KEY = 'p' + 256 * 'u',
	POP_KEY = 'p' + 256 * 'o',
	TOP_KEY = 't' + 256 * 'o',
	SIZE_KEY = 's' + 256 * 'i',
	EMPTY_KEY = 'e' + 256 * 'm'
};

typedef struct
{
	unsigned int	*arr;
	size_t			cap;
	size_t			size;
}		t_darray;

static unsigned int	my_atoi(const char *s);
static void			push(t_darray *arr, char *buf);
static void			pop(t_darray *arr);
static void			top(t_darray *arr);
static void			size(t_darray *arr);
static void			empty(t_darray *arr);

int	main(void)
{
	t_darray			arr = {malloc(sizeof(int) * 128), 128, 0};
	enum e_inst_keys	key;
	int					test_len;
	char				buf[13] = {0, };

	fscanf(stdin, "%d\n", &test_len);
	while (test_len--)
	{
		fgets(buf, 13, stdin);
		key = buf[0] + 256 * buf[1];
		switch (key)
		{
			case PUSH_KEY:
				push(&arr, buf);
				break;
			case POP_KEY:
				pop(&arr);
				break;
			case TOP_KEY:
				top(&arr);
				break;
			case SIZE_KEY:
				size(&arr);
				break;
			case EMPTY_KEY:
				empty(&arr);
				break;
			default:
				fputs("ERROR: invalid instruction.\n", stdout);
		}
	}
}

static void	push(t_darray *arr, char *buf)
{
	unsigned int	num;
	unsigned int	*temp;

	while (*buf != ' ' && *buf)
		++buf;
	if (*buf == 0)
	{
		printf("ERROR: wrong input.\n");
		return ;
	}
	++buf;
	num = my_atoi(buf);
	if (arr->size + 1 == arr->cap)
	{
		temp = malloc(sizeof(int) * arr->cap * 2);	
		for (size_t i = 0; i < arr->size; ++i)
			temp[i] = arr->arr[i];
		arr->cap *= 2;
		free(arr->arr);
		arr->arr = temp;
	}
	arr->arr[arr->size++] = num;
}

static void	pop(t_darray *arr)
{
	if (arr->size == 0)
	{
		printf("-1\n");
		return ;
	}
	printf("%d\n", arr->arr[arr->size - 1]);
	--arr->size;
}

static void	top(t_darray *arr)
{
	if (arr->size == 0)
		printf("-1\n");
	else
		printf("%u\n", arr->arr[arr->size - 1]);
}

static void	size(t_darray *arr)
{
	printf("%zu\n", arr->size);
}

static void	empty(t_darray *arr)
{
	printf("%u\n", !arr->size);
}

static unsigned int	my_atoi(const char *s)
{
	unsigned int	num = 0;

	while (*s >= 48 && *s < 58)
		num = num * 10 + *s++ - 48;
	return (num);
}
