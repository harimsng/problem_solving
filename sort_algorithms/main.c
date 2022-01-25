#include <stdio.h>

void	merge_sort_32(void *base, size_t len);

int	main(void)
{
	int		arr[] =
	{
		5, 1, 3, 2, 7, 5, 9, 7, 8, 4, 6
	};
	int		len = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < len; ++i)
		printf("%d ", arr[i]);
	printf("\n");
	merge_sort_32(arr, (size_t)len);
	for (int i = 0; i < len; ++i)
		printf("%d ", arr[i]);
	printf("\n");
	return (0);
}
