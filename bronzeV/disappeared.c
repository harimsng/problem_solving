#include <unistd.h>

static const char *tab = "0123456789";

int atoi(const char *s);
void putnbr(int n);


int main(void)
{
    char    buf[8] = {0, };
    int     num = 0;
    
    read(0, buf, 7);
    num = atoi(buf);
    num = (num + 4) / 5;
    putnbr(num);
    return (0);
}

int atoi(const char *s)
{
    int        ret = 0;
    
    while (*s >= '0' && *s <= '9')
        ret = 10 * ret + *s++ - '0';
    return (ret);
}

void putnbr(int n)
{
    if (n > 9)
        putnbr(n / 10);
    write(1, tab + n % 10, 1);
}
