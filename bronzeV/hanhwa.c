#include <unistd.h>

int atoi(char *s);
void putnbr(int n);

static const char   *tab = "0123456789";

int main(void)
{
    int    m, k;
    int    i = 0;
    char   buf[23] = {0, };

    read(0, buf, 22);
    while (buf[i] != ' ') ++i;
    m = atoi(buf + i++ + 1);
    while (buf[i] && buf[i] != ' ') ++i;
    k = atoi(buf + i + 1);
    putnbr(k / m);
        write(1, " ", 1);
    putnbr(k % m);
}

int atoi(char *s)
{
    int ret = 0;

    while(*s >= 48 && *s <= 57)
        ret = 10 * ret + *s++ - 48;
    return (ret);
}

void putnbr(int n)
{
    if (n >= 10)
        putnbr(n / 10);
    write(1, tab + n % 10, 1);
}
