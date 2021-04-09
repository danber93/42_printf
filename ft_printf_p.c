#include "ft_printf.h"

int		ft_p_blanks_right(char *s, t_flags *flags)
{
	int		i;
	char	*dest;
	
	if (flags->width > ft_strlen(s))
		{
			dest = ft_calloc(flags->width + 1);
			i = 0;
			while (i < ft_strlen(s))
			{
				dest[i] = s[i];
				i++;
			}
			while (i < flags->width)
				dest[i++] = ' ';
			dest[i] = '\0';
			return (ft_putstr(dest));
		}
	return (ft_putstr(s));
}

int		ft_p_blanks_left(char *s, t_flags *flags)
{
	int		i;

	
}

int		ft_printf_p(unsigned long int n, t_flags *flags, char *base)
{
	int		i;
	char	*s;

	// s = ft_itoa_base_lu(n, base);
	// aggiungere 0x
	if (flags->minus)
		return (ft_p_blanks_right(s, flags));
	return (ft_p_blanks_left(s, flags));
}