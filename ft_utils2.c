#include "ft_printf.h"

char	*ft_calloc(int size)
{
	int		i;
	char	*dest;

	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < size)
		dest[i++] = '\0';
	dest[i] = '\0';
	return (dest);
}