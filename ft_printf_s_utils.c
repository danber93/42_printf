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

	dest = (char *)malloc(flags->width + 1);
	if (!dest)
		return (NULL);
	i = 0;
	if (flags->minus)
	{
		while (i < flags->width)
		{
			if (s[i] && i < ft_strlen(s))
				dest[i] = s[i];
			else
				dest[i] = ' ';
			i++;
		}
		dest[i] = '\0';
		free(s);
		return (dest);
	}
	return (dest = ft_s_padding_left(s, dest, flags));
}

int	ft_s_null_pright(t_flags *flags)
{
	int		i;
	int		j;
	char	*n;
	char	*s;

	n = "(null)";
	i = 0;
	j = 0;
	if (flags->width < ft_strlen(n))
		flags->width = ft_strlen(n);
	s = ft_calloc(flags->width);
	if (!s)
		return (-1);
	while (i < ft_strlen(n))
		s[i++] = n[j++];
	while (i < flags->width)
		s[i++] = ' ';
	return (ft_result(s));
}

int	ft_revert(char *s)
{
	int		i;
	int		j;
	char	*res;

	res = ft_calloc(ft_strlen(s));
	if (!res)
		return (-1);
	i = 0;
	while (s[i] == ' ')
		i++;
	j = 0;
	while (s[i])
		res[j++] = s[i++];
	while (j < ft_strlen(s))
		res[j++] = ' ';
	free(s);
	return (ft_result(res));
}

int	ft_s_null_fpoint_2(t_flags *flags, char *s, char *n)
{
	int	i;
	int	j;

	if (flags->precision <= -1)
		flags->precision = 0;
	i = 0;
	while (i < flags->width - flags->precision)
		s[i++] = ' ';
	j = 0;
	while (i < flags->width && n[j])
		s[i++] = n[j++];
	if (flags->minus)
		return (ft_revert(s));
	return (ft_result(s));
}
