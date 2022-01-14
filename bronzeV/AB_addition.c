#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    char              buf[20002] = {0, };
    int               len1, len2, len3;
    unsigned char     *num1, *num2;

    read(0, buf, 20001);
    for (len1 = 0; buf[len1] != ' '; ++len1) continue ;
    for (len2 = 0; buf[len1 + 1 + len2]; ++len2) continue ;
    len3 = len1 > len2 ? len1 : len2;
    num1 = (unsigned char *)malloc(sizeof(unsigned char) * (len3 + 1));
    num2 = (unsigned char *)malloc(sizeof(unsigned char) * (len3 + 1));
	num1[0] = 0;
	num2[0] = 0;
    for (int i = 0, j = len3 - len1 + 1, k = len3 - len2 + 1; i < len3; ++i, ++j, ++k)
    {
        num1[j] = (buf[i] - 48) * (i < len1);
        num2[k] = (buf[i + len1 + 1] - 48) * (i < len2);
    }
    for (int i = len3; i > 0; --i)
    {
        num1[i] += num2[i];
        if (num1[i] > 9)
        {
            ++num1[i - 1];
            num1[i] -= 10;
        }
        num1[i] += 48;
    }
    num1[0] += 48;
    write(1, num1 + (num1[0] == 48), len3 + (num1[0] != 48));
    return (0);
}
