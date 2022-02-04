#include <unistd.h>

int	main(void)
{
	char	buf[1000000] = {0, };
//	int		temp;

	read(0, buf, 1000000);
	write(1, buf, 1000000);
/*	fgets(buf, 1000000, stdin);
	fputs(buf, stdout);
	fscanf(stdin, "%d\n", &temp);
	fprintf(stdout, "%d\n", temp);
	fscanf(stdin, "%1000000s", buf);
	fprintf(stdout, "\n...\n");
//	fread(buf, 1, 1000000, stdin);
	fwrite(buf, 1, 1000000, stdout);
	*/
	return (0);
}
