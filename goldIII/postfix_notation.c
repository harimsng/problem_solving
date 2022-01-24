#include <stdio.h>

void	get_block(char *ret_ptr, char *buf_ptr);

int	main(void)
{
	char	buf[102] = {0, };
	char	ret[102] = {0, };
	char	*buf_ptr = buf;
	char	*ret_ptr = ret;
	int		flag;

	fgets(stdin, buf, 102);
	while (*buf_ptr)
	{
		if (*buf_ptr == '*' || *buf_ptr == '/')
	}
	while (*buf_ptr)
	{
		if (*buf_ptr >= 65 && *buf_ptr <= 90)
			*ret_ptr++ = *buf_ptr;
		else if (*buf_ptr >= 42 && *buf_ptr <= 47)
			get_block(ret_ptr, buf_ptr);
	}
}

void	get_block(char *ret_ptr, char *buf_ptr)
{

}
