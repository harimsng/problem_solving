#include <stdio.h>

int	main(void)
{
	char	buf[1000000] = {0, };
	int		temp;

	fscanf(stdin, "%s", buf);
	fprintf(stdout, "%s\n", buf);
	fscanf(stdin, " %d ", &temp);
	fprintf(stdout, "%d\n", temp);
	fscanf(stdin, "%[^\0]", buf);
	fprintf(stdout, "\n...\n");
	fread(buf, 1, 1000000, stdin);
	fwrite(buf, 1, 1000000, stdout);
	
	return (0);
}
