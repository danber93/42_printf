#include "ft_printf.h"

char	*ft_calloc(char *p, int size)
{
	int		i;

	if (!(p = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
		p[i++] = '\0';
	p[i] = '\0';
	return (p);
}