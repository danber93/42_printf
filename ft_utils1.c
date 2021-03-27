#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strndup(char *s, char *d, int n)
{
	int	i;

	if (!(d = (char *)malloc(n + 1)))
		return (NULL);
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_itoa_base(int n, char *base)
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