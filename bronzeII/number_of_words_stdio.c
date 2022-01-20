#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		len = 0;
	int		count = 0;
	int		idx;
	char	buf[1000001] = {0, };

    
	fgets(buf, 1000001, stdin);
	len = strlen(buf);
	printf("len = %d\n", len);
	printf("[%s]\n", buf);
	if (buf[len - 1] == '\n')
		buf[len - 1] = 0;
	printf("[%s]\n", buf);
	idx = 0;
	printf("[");
	while (idx < len)
	{
		printf("%c", buf[idx]);
		if (buf[idx] != ' '
            && (buf[idx + 1] == ' ' || buf[idx + 1] == 0))
		{
			printf("|%hhd_%hhd|", buf[idx], buf[idx + 1]);
			++count;
		}
		++idx;
	}
	printf("]\n");
	printf("%d", count);
	return (0);
}
