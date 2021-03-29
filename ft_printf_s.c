#include "ft_printf.h"

char	*ft_s_padding_left(char *s, char *dest, t_flags *flags)
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

char	*ft_s_padding(char *s, t_flags *flags)
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
			if (s[i] && i < (flags->width - ft_strlen(s)))
				dest[i] = s[i];
			else
				dest[i]  = ' ';
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (dest = ft_s_padding_left(s, dest, flags));
}

int		ft_printf_s(char *s, t_flags *flags)
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
			if (!(t = ft_s_padding(t, flags)))
				return (-1);
	return (ft_putstr(t));
}