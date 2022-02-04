#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	main(void)
{
	int		fd1, fd2;
	char	buf1[1000000] = {0, };
	char	buf2[1000000] = {0, };
	int		len1, len2;
	int		count = 0;

	fd1 = open("editor.ou9", O_RDONLY);
	fd2 = open("out9_unistd", O_RDONLY);
	len1 = read(fd1, buf1, 1000000);
	len2 = read(fd2, buf2, 1000000);
	for (int i = 0, j = 0; i < len1 && j < len2; ++i, ++j)
	{
		if (buf1[i] != buf2[j])
		{
			printf("diff at %d\n", i);
			++count;
			if (strncmp(buf1 + i + 1, buf2 + j, 10) == 0)
				++i;
			else if (strncmp(buf1 + i, buf2 + j + 1, 10) == 0)
				++j;
			else
				printf("continuous diff \n%.20s\n%.20s\n", buf1 + i, buf2 + j);
		}
	}
}
