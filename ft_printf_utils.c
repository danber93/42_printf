#include "ft_printf.h"

int		ft_handle_format(char f, t_flags *flags, va_list ap)
{

	if (f == 'c')
		return (ft_print_c(va_arg(ap, int)));
	//if (f == 'd' || f == 'i')
	//	return (ft_print_i(va_arg(ap, int)));
	if (f == 's')
		return (ft_print_s(va_arg(ap, char *), flags));
	return (0);
}


char	*ft_padding_left(char *s, char *dest, t_flags *flags)
{
	int		i;
	int		j;
	int		padding;

	i = 0;
	padding = flags->width - ft_strlen(s);
	while (i < padding)
	{
		if (flags->zero)
			dest[i] = '0';
		else
			dest[i] = ' ';
		i++;
	}
	j = 0;
	while (i < flags->width)
		dest[i++] = s[j++];
	dest[i] = '\0';
	return (dest);
}

char	*ft_padding(char *s, t_flags *flags)
{
	int		i;
	char	*dest = "dest";

	if (!(dest = (char *)malloc(flags->width + 1)))
		return (NULL);
	i = 0;
	if (flags->minus)
	{
		while (i < flags->width)
		{
			if (s[i])
				dest[i] = s[i];
			else
				dest[i]  = ' ';
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (dest = ft_padding_left(s, dest, flags));
}