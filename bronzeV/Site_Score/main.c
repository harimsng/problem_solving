#include <unistd.h>

int    atoi(char *str);
void   putnbr(int num);

static const char    *tab = "0123456789";

int    main(void)
{
    char    buf[18] = {0, };
    int     tickets;
    int     idx;
    
    read(0, buf, 18);
    tickets = 56 * atoi(buf);
    while (buf[idx] != ' ') ++idx;
    tickets += 24 * atoi(buf + ++idx);
    while (buf[idx] != ' ') ++idx;
    tickets += 14 * atoi(buf + ++idx);
    while (buf[idx] != ' ') ++idx;
    tickets += 6 * atoi(buf + ++idx);
    putnbr(tickets);
    return (0);
}

int    atoi(char *str)
{
    int    ret;
    
    ret = 0;
    while (*str > 47 && *str < 58)
        ret = 10 * ret + *str++ - 48;
    return (ret);
}

void   putnbr(int num)
{
    if (num > 10)
        putnbr(num / 10);
    write(1, tab + num % 10, 1);
}
