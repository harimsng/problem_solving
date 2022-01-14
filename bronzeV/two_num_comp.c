#include <unistd.h>

int atoi(char *s);

int main(void)
{
    int    a, b;
    int    idx;
    char   buf[7] = {0, };
    char   ret[5] = "><==";
    
    idx = 0;
    while (read(0, buf + idx, 1) && buf[idx] != ' ')
        ++idx;
    a = atoi(buf);
    idx = 0;
    while (read(0, buf + idx, 1))
        ++idx;
    buf[idx] = 0;
    b = atoi(buf);
    write(1, ret + (a < b) + 2 * (a == b), 1 + (a == b));
    return (0);
}

int atoi(char *s)
{
    int		ret;
	int		nsign;
    
	nsign = *s == '-';
	s += nsign;
	ret = 0;
    while (*s >= 48 && *s <= 57)
        ret = 10 * ret + *s++ - 48;
    return (ret * (1 - 2 * nsign));
}
