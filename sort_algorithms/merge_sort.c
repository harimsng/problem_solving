#include <stdlib.h>

void	merge_sort_split(void *from, size_t left, size_t right, void *to);
void	merge_sort_join(void *from, size_t left, size_t right, void *to);

static size_t	g_width;
static int		(*g_cmp)(const void *, const void *);

void	merge_sort(void *base, size_t len, size_t width, int (*cmp)(const void *, const void *))
{
	void	*temp = malloc(len * width);

	g_width = width;
	g_cmp = cmp;
	if (len < 2)
		return ;

	for (int i = 0; i < len; ++i)
		merge_sort_memcpy(base, temp, len * width);
	merge_sort_split(temp, 0, len - 1, base);
	free(temp);
}

void	merge_sort_split(void *from, size_t left, size_t right, void *to)
{
	size_t		mid = (left + right) / 2;

	if (left >= right)
		return ;
	merge_sort_split(to, left, mid, from);
	merge_sort_split(to, mid + 1, right, from);
	merge_sort_join(from, left, right, to);
}

void	merge_sort_join(void *from, size_t left, size_t right, void *to)
{
	size_t		mid = (left + right) / 2;
	size_t		idx = left, jdx = mid + 1;
	size_t		kdx = left;
	
	while (idx <= mid && jdx <= right)
	{
		if (g_cmp(from + g_width * idx, from + g_width * jdx) > 0)
			merge_sort_memcpy(to + g_width * kdx++, from + g_width * jdx++, g_width);
		else
			merge_sort_memcpy(to + g_width * kdx++, from + g_width * idx++, g_width);
	}
}

void	merge_sort_memcpy(void *dst, const void *src, size_t size)
{
	if (g_width == 1)
		
}
