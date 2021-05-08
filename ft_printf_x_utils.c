#include "ft_printf.h"

int	ft_x_revert(char *dest, int blanks)
{
	int		i;
	int		j;
	char	*res;

	res = ft_calloc(ft_strlen(dest));
	i = 0;
	while (i < blanks)
		res[i++] = ' ';
	j = 0;
	while (i < ft_strlen(dest))
		res[i++] = dest[j++];
	free(dest);
	return (ft_result(res));
}
