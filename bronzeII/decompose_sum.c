#include <stdio.h>

int my_atoi(const char *s);
int decompose(int num);

int main(void)
{
    char    buf[9] = {0, };
    int     num;
    int     den = 1000000;
    int     digits = 7;
    int     comp = 0;

	fgets(buf, 9, stdin);
    num = my_atoi(buf);
    while (den && !(num / den))
    {
        --digits;
        den /= 10;
    }
    comp = num - 9 * digits;
	if (comp < 0)
		comp = 0;
    while (comp < num)
    {
        if (decompose(comp) == num)
            break;
        ++comp;
    }
    printf("%d", comp != num ? comp : 0);
    return (0);
}

int my_atoi(const char *s)
{
    int     ret = 0;

    while (*s >= 48 && *s < 58)
        ret = ret * 10 + *s++ - 48;
    return (ret);
}

int decompose(int num)
{
    int     sum = num;

    while (num)
    {
        sum += num % 10;
        num /= 10;
    }
    return (sum);
}
