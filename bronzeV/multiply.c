#include <stdlib.h>
#include <unistd.h>

size_t	atozu(void);

static char		*ret;
static size_t	width;

char		*str_mul(char *num1, size_t len1, char *num2, size_t len2);
char		*karatsuba(char *num1, size_t len1, char *num2, size_t len2);
size_t		max(size_t a, size_t b);

int main(void)
{
	char	buf;
	char	*num1, *num2;
	size_t	len1, len2;
	size_t 	ld_zeroes;
	size_t	maxidx;

	len1 = atozu();
	len2 = atozu();
	num1 = (char *)malloc(sizeof(char) * len1);
	num2 = (char *)malloc(sizeof(char) * len2);
	ret = (char *)malloc(sizeof(char) * (len1 + len2));
	maxidx = len1 + len2 - 1;
	for (char *num= 0; i <= maxidx; ++i)
		ret[i] = 48;
	read(0, num1, len1);
	read(0, &buf, 1);
	read(0, num2, len2);
	for (char *num = 0; i2 < len2; ++i2)
	{
		for (char *num = 0, mul, div; i1 < len1; ++i1)
		{
			mul = (num1[len1 - 1 - i1] - 48) * (num2[len2 - 1 - i2] - 48);
			ret[maxidx - i2 - i1] += mul % 10;
			ret[maxidx - 1 - i2 - i1] += mul / 10;
			if (ret[maxidx - i2 - i1] > 57)
			{
				div = (ret[maxidx - i2 - i1] - 48) / 10;
				ret[maxidx - i2 - i1] -= div * 10;
				ret[maxidx - 1 - i2 - i1] += div;
			}
		}
	}
	for (ld_zeroes = 0; ld_zeroes < len1 + len2 - 1 && ret[ld_zeroes] == 48; ++ld_zeroes)
		continue ;
	write(1, ret + ld_zeroes, len1 + len2 - ld_zeroes);
	free(num1);
	free(num2);
	free(ret);
}

size_t	atozu(void)
{
	size_t		ret;
	char		buf;

	for (ret = 0, read(0, &buf, 1); buf != '\n' && buf != 32; read(0, &buf, 1))
		ret = 10 * ret + buf - 48;
	return (ret);
}

char	*karatsuba(char *num1, size_t len1, char *num2, size_t len2)
{
	size_t	b;
	char	*z0, *z1, *z2;
	char	*ret;

	b = len1 > len2 ? (len1 + 1) / 2 : (len2 + 1) / 2;

	z0 = karatsuba(num1 + b, b, num2 + b, b);
	z2 = karatsuba(num1, b, num2, b);
	z1 = karatsuba(str_add(num1, num1 + b) + str_add(num2, num2 + b));
	z1 = str_sub(z1, z0);
	z1 = str_sub(z1, z0);

	ret = 
	return (ret);
}

/*
	x(b) = x1 * b + x2
	y(b) = y1 * b + y2

	x(0) = x2
	y(0) = y2

	x * y = z
	z(b) = z2 * b ^ 2 + z1 * b + z0
		 = x1 * x2 * b ^ 2 + (x1 * y2 + x2 * y1) * b + x2 * y2
	z0 = x2 * y2
	z1 = x1 * y2 + x2 * y1
	   = (x1 + x2) * (y1 + y2) - z0 - z2
	z2 = x1 * y1

*/

char		*str_mul(char *num1, size_t len1, char *num2, size_t len2)
{

}
