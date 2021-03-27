#include "ft_printf.h"

int		ft_print_s(char *s, t_flags *flags)
{
	// se s.length <= precision, allora ignora precision => s2
	// se s.length > precision, allora tronca s => s2
	// se padding <= s2.length, allora ignora => s3
	// se padding > s2.length, allora =>
	//									se flag.minus c'è, padda a dx => s3
	//									altrimenti padda a sx => s3
	//	NOTE 	il flag zero, non accettabile sulle stringhe
	int		len;
	char	*t;

	if (!(flags->point) && !(flags->width))
		return (ft_putstr(s));
	len = ft_strlen(s);
	if (flags->point == 1)
	{
		if (flags->precision < len)
		{
			if (!(t = ft_strndup(s, t, flags->precision)))
				return (-1);
		}
		else
			if (!(t = ft_strndup(s, t, len)))
				return (-1);
	}
	else
		t = ft_strndup(s, t, ft_strlen(s));
	if (flags->width != 0)
		if (flags->width > ft_strlen(t))
			if (!(t = ft_padding(t, flags)))
				return (-1);
	return (ft_putstr(t));
}