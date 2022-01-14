#include <unistd.h>

int     atoi(char *str);
void    putnbr(int num);

static const char    *tab = "0123456789";

int main(void)
{
    char    buf[11] = {0, };
    int     ret = 0;
    int     idx = 0;
    
    for (int i = 0; i < 6; ++i)
    {
        idx = 0;
        while (read(0, buf + idx, 1) > 0 && buf[idx] >= '0' && buf[idx] <= '9')
            ++idx;
        buf[idx] = 0;
        ret += atoi(buf);
    }
    putnbr(5 * ret);
    return (0);
}

int atoi(char *str)
{
    int    ret = 0;
    
    while (*str)
        ret = 10 * ret + *str++ - '0';
    return (ret);
}

void    putnbr(int num)
{
    if (num > 9)
        putnbr(num / 10);
    write(1, tab + num % 10, 1);
}
