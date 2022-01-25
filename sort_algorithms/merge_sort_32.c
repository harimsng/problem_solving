#include <stdlib.h>

void	merge_sort_split(int *from, size_t left, size_t right, int *to);
void	merge_sort_join(int *from, size_t left, size_t right, int *to);

void	merge_sort_32(void *base, size_t len)
{
	int	*temp = malloc(len * sizeof(int));
	int	*array = base;

	if (len < 2)
		return ;
	for (size_t i = 0; i < len; ++i)
		temp[i] = array[i];
	merge_sort_split(temp, 0, len - 1, array);
	free(temp);
}

void	merge_sort_split(int *from, size_t left, size_t right, int *to)
{
	size_t		mid = (left + right) / 2;

	if (left >= right)
		return ;
	merge_sort_split(to, left, mid, from);
	merge_sort_split(to, mid + 1, right, from);
	merge_sort_join(from, left, right, to);
}

void	merge_sort_join(int *from, size_t left, size_t right, int *to)
{
	size_t		mid = (left + right) / 2 + 1;
	size_t		idx = left, jdx = mid;
	size_t		kdx = left;
	
	++right;
	while ((mid - idx) && (right - jdx))
	{
		if (from[idx] > from[jdx])
			to[kdx++] = from[jdx++];
		else
			to[kdx++] = from[idx++];
	}
	if (jdx != right)
		idx = jdx;
	while (kdx < right)
		to[kdx++] = from[idx++];
}
