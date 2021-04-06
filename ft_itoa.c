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

int		ft_digits_u(long int n, int lenb)
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
	long int		li;

	if (n == -2147483648)
		return ("-2147483648");
	if ((ft_strlen(base) > 10) && n < 0)
		li = n + 4294967296;
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

char	*ft_itoa_base_u(long int n, char *base)
{
	int				lenb;
	char			*res;
	int				i;
	long int		li;

	if ((ft_strlen(base) > 10) && n < 0)
	 	li = 4294967295 - n;
	else
		li = n;
	lenb = ft_strlen(base);
	i = ft_digits_u(li, lenb);
	if (!(res = ft_calloc(i + 1)))
		return (NULL);
	i--;
	while (i > 0)
	{
		res[i] = base[li % lenb];
		li = li / lenb;
		i--;
	}
	res[i] = base[li ];
	return (res);
}