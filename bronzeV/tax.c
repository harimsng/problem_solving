#include <unistd.h>

int    atoi(char *s);
void   putnbr(int n);

static const char    *tab = "0123456789";

int    main(void)
{
    char    buf[9] = {0, };
    int     num;
    
    read(0, buf, 8);
    num = atoi(buf);
    putnbr(num * 0.78);
    write(1, " ", 1);
    putnbr(num * 0.956);
}

int    atoi(char *s)
{
    int    ret = 0;
    
    while (*s != '\n')
        ret = 10 * ret + *s++ - 48;
    return (ret);
}

void   putnbr(int n)
{
    if (n > 9)
        putnbr(n / 10);
    write(1, tab + n % 10, 1);
}
