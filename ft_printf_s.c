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
	free(s);
	return (dest);
}

char	*ft_s_padding(char *s, t_flags *flags)
{
	int		i;
	char	*dest;

	if (!(dest = (char *)malloc(flags->width + 1)))
		return (NULL);
	i = 0;
	if (flags->minus)
	{
		while (i < flags->width)
		{
			if (s[i] && i < ft_strlen(s))
				dest[i] = s[i];
			else
				dest[i]  = ' ';
			i++;
		}
		dest[i] = '\0';
		free(s);
		return (dest);
	}
	return (dest = ft_s_padding_left(s, dest, flags));
}

int		ft_s_null_pright(char *s, t_flags *flags)
{
	int		i;
	int		j;
	char	*n;

	n = "(null)";
	i = 0;
	j = 0;
	while (i < flags->precision && i < flags->width)
		s[i++] = n[j++];
	while (i < flags->width)
		s[i++] = ' ';
	return (ft_result(s));
}


int		ft_s_null_pleft(t_flags *flags)
{
	int		i;
	int		j;
	char	*s;
	char	*n;

	n = "(null)";
	if (flags->width > flags->precision)
		s = ft_calloc(flags->width + 1);
	else
		s = ft_calloc(flags->precision + 1);
	if (!s)
		return (-1);
	if (flags->minus)
		return (ft_s_null_pright(s, flags));
	i = 0;
	while (i < flags->width - flags->precision)
		s[i++] = ' ';
	j = 0;
	while (i < flags->width)
		s[i++] = n[j++];
	return(ft_result(s));
}

int		ft_printf_s(char *s, t_flags *flags)
{
	int		len;
	char	*t;

	if (!s)
		return (ft_s_null_pleft(flags));
	if (!(flags->point) && !(flags->width))
		return (ft_putstr(s));
	len = ft_strlen(s);
	t = ft_calloc(1);
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
	return (ft_result(t));
}