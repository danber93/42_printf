#include "ft_printf.h"

int		ft_digits(int n, int lenb)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = n * (-1);
	}
	while (n >= lenb)
	{
		n /= lenb;
		i++;
	}
	return (i);
}

char	*ft_itoa_base_neg(int n, char *base)
{
	int		lenb;
	char	*res;
	int		i;

	lenb = ft_strlen(base);
	i = ft_digits(n, lenb);
	if (!(res = ft_calloc(i + 1)))
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		i--;
	}
	n *= -1;
	while (i > 0)
	{
		if (res[i] != '-')
			res[i] = base[n % lenb];
		n = n / lenb;
		i--;
	}
	return (res);
}

char	*ft_itoa_base(int n, char *base)
{
	int		lenb;
	char	*res;
	int		i;

	if (n < 0)
		return (ft_itoa_base_neg(n, base));
	lenb = ft_strlen(base);
	i = ft_digits(n, lenb);
	if (!(res = ft_calloc(i + 1)))
		return (NULL);
	i--;
	while (i > 0)
	{
		res[i] = base[n % lenb];
		n = n / lenb;
		i--;
	}
	res[i] = base[n];
	return (res);
}

char	*ft_itoa_base_u(unsigned int n, char *base)
{
	int		lenb;
	char	*res;
	int		i;
	int		temp;

	lenb = ft_strlen(base);
	temp = n;
	i = 1;
	while (temp >= lenb)
	{
		temp /= lenb;
		i++;
	}
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	res[i] = '\0';
	i--;
	while (i > 0)
	{
		res[i] = base[n % lenb];
		n = n / lenb;
		i--;
	}
	res[i] = base[n];
	// printf("\nRes = %s\n", res);
	return (res);
}