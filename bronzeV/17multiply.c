#include <unistd.h>

int main(void)
{
    char        bin[1006] = {'0', '0', '0', '0', '0', };
    char        bin2[1001] = {0, };
    int         size;

    size = read(0, bin + 5, 1000);
    for (int i = 0; i < size; ++i)
    {
        bin2[i] = bin[i + 5];
        bin[i + 1] = bin[i + 5];
        bin[i + 5] = '0';
    }
    for (int i = size + 4; i > 0; --i)
    {
        if (i > 4)
            bin[i] += bin2[i - 5] - '0';
        if (bin[i] > '1')
        {
            ++bin[i - 1];
            bin[i] -= 2;
        }
    }
    write(1, bin + (bin[0] == '0'), size + 5 - (bin[0] == '0'));
    return (0);
}
//0000010
//10
//0100000
//0100010
