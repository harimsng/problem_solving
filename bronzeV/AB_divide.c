#include <unistd.h>

int main(void)
{
    long long    a, b;
    char         buf[12] = {0, };
    
    read(0, buf, 1);
    a = buf[0] - '0';
    read(0, buf, 2);
    b = buf[1] - '0';
    a *= 1000000000;
    a /= b;
    for (int i = 1, den = 1000000000; i < 11; ++i)
	{
        buf[i] = a / den + '0';
		a %= den;
		den /= 10;
	}
    buf[0] = buf[1];
    buf[1] = '.';
    write(1, buf, 11);
    return (0);
}
