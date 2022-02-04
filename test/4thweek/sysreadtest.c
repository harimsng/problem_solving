#include <time.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char		buf[1000001] = {0, };
	clock_t		start, end;
	FILE		*fd1, *fd2;
	int			idx = 0;

	fd1 = fopen("read1_2.txt", "r+");
	start = clock();
	while (fgets(buf, 1000001, fd1))
		continue ;
	end = clock();
	printf("input\n%fs\n", (double)(end - start) / CLOCKS_PER_SEC);

	fd2 = fopen("read2_2.txt", "r+");
	start = clock();
	while (idx < 10000)
	{
		fputs(buf, fd1);
		++idx;
	}
	end = clock();
	printf("output\n%fs\n", (double)(end - start) / CLOCKS_PER_SEC);

	start = clock();
	fwrite(buf, 1, 1000000, fd1);
	end = clock();
	printf("output at once\n%fs\n", (double)(end - start) / CLOCKS_PER_SEC);

	fclose(fd1);
	return (0);
}
