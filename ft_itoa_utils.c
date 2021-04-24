#include "ft_printf.h"

char	*ft_gear(char *s)
{
	int		i;
	char	*str;

	str = ft_calloc(11);
	if (!str)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

int	ft_digits(int n, int lenb)
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
