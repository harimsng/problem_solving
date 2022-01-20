#include <stdio.h>

int my_atoi(const char *s);
int decompose(int num);

int main(void)
{
//    char    buf[9] = {0, };
    int     num;
    int     den = 1000000;
    int     digits = 7;
    int     comp = 0;
	int		comp2 = 0;
    
/*	fgets(buf, 9, stdin);
    num = my_atoi(buf);
    while (den && !(num / den))
    {
        --digits;
        den /= 10;
    }
    if (num > 9)
        comp = num - 9 * (digits - 1);
    else
    {
        printf("%d", num);
        return (0);
    }
*/	num = 1;
	while (num <= 1000000)
	{
		den = 1000000;
		digits = 7;
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
		comp2 = 1;
		while (comp2 < num)
		{
			if (decompose(comp2) == num)
				break;
			++comp2;
		}
		if (comp != comp2)
			printf("wrong %d > %d != %d\n", num, comp, comp2);
		if (num % 10000 == 0)
			printf("%d\n", num);
		++num;
	}
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
