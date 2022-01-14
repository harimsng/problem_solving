#include <unistd.h>
#include <stdio.h>
#include <time.h>

typedef long long unsigned int uint64;

int    convert(char **buf);
void   itoa(uint64 num);
void   recursion(int depth, int red, int green, int blue, uint64 comb);
uint64 combination(uint64 set, uint64 item);

static uint64        g_count;
static int           *g_max;

int    main(void)
{
    char    buf[15] = {0, };
    char    *ptr;
    int     red = 0, green = 0, blue = 0;
    int     max = 0;

	clock_t	start, end;
	double	time_taken;

    ptr = buf;
    read(0, buf, 14);
    max = convert(&ptr);
    red = convert(&ptr);
    green = convert(&ptr);
    blue = convert(&ptr);

    g_max = &max;
	start = clock();
    if (max > 0)
		recursion(0, red, green, blue, 1);
	end = clock();
	time_taken = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%f\n", time_taken);
    itoa(g_count);
    return (0);
}

void    recursion(int depth, int red, int green, int blue, uint64 comb)
{
    uint64    temp_comb = 0;

    if (red < 0 || green < 0 || blue < 0)
        return ;
    if (depth == *g_max)
    {
        g_count += comb;
        return ;
    }
    ++depth;
    recursion(depth, red - depth, green, blue, comb);
    recursion(depth, red, green - depth, blue, comb);
    recursion(depth, red, green, blue - depth, comb);
    if (depth % 2 == 0)
    {
        temp_comb = combination(depth, depth / 2) * comb;
        recursion(depth, red - depth / 2, green - depth / 2, blue, temp_comb);
        recursion(depth, red - depth / 2, green, blue - depth / 2, temp_comb);
        recursion(depth, red, green - depth / 2, blue - depth / 2, temp_comb);
    }
    if (depth % 3 == 0)
    {
        temp_comb = combination(depth, depth / 3)
                * combination(2 * depth / 3, depth / 3) * comb;
        recursion(depth, red - depth / 3, green - depth / 3,
                 blue - depth / 3, temp_comb);
    }
}

uint64    combination(uint64 set, uint64 item)
{
    uint64      ret = 1;
    uint64      i = 0;

    while (i < item)
    {
        ret *= set;
        ret /= i + 1;
        --set;
        ++i;
    }
    return (ret);
}

int    convert(char **buf)
{
    int    ret = 0;

    while (**buf >= '0' && **buf <= '9')
    {
        ret = 10 * ret + **buf - '0';
        *buf += 1;
    }
    *buf += 1;
    return (ret);
}

void    itoa(uint64 num)
{
    char    buf[20] = {0, };
    uint64  den = 10000000000000000000ULL;
    int     len = 0;
    
    while (den && !(num / den))
        den /= 10;
    while (den)
    {
        buf[len] = num / den + 48;
        num %= den;
        den /= 10;
        ++len;
    }
    if (!buf[0])
    {
        buf[0] = '0';
        len = 1;
    }
    write(1, buf, len);
}
