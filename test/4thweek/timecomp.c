#include <unistd.h>
#include <time.h>
#include <stdio.h>

int	main(void)
{
	clock_t		start, end;
//	double		seconds;

	start = clock();
	execve("editor_fwrite.sh", NULL, NULL);
	end = clock();
	printf("fwrite: %lfs\n", (double)(end - start) / CLOCKS_PER_SEC);
	start = clock();
	execve("editor_fprintf.sh", NULL, NULL);
	end = clock();
	printf("fprintf: %lfs\n", (double)(end - start) / CLOCKS_PER_SEC);
	return (0);
}
