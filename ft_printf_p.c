/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbertill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:58:06 by dbertill          #+#    #+#             */
/*   Updated: 2021/05/08 15:58:07 by dbertill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p_blanks_right(char **s, t_flags *flags)
{
	int		i;
	char	*dest;

	if (flags->width > ft_strlen(*s))
	{
		dest = ft_calloc(flags->width + 1);
		i = 0;
		while (i < ft_strlen(*s))
		{
			dest[i] = (*s)[i];
			i++;
		}
		while (i < flags->width)
			dest[i++] = ' ';
		dest[i] = '\0';
		free(*s);
		return (ft_result(dest));
	}
	return (ft_result(*s));
}

int	ft_p_blanks_left(char **s, t_flags *flags)
{
	int		i;
	int		j;
	char	*dest;

	if (flags->width > ft_strlen(*s))
	{
		dest = ft_calloc(flags->width + 1);
		i = 0;
		while (i < flags->width - ft_strlen(*s))
		{
			dest[i] = ' ';
			i++;
		}
		j = 0;
		while (i < flags->width)
		{
			dest[i++] = (*s)[j++];
		}
		dest[i] = '\0';
		free(*s);
		return (ft_result(dest));
	}
	return (ft_result(*s));
}

int	ft_digits_lu(unsigned long int n, int lenb)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = n * (-1);
	}
	while (n >= (unsigned long int)lenb)
	{
		n /= lenb;
		i++;
	}
	return (i);
}

char	*ft_itoa_base_lu(unsigned long int n, char *base)
{
	int					lenb;
	char				*res;
	int					i;
	unsigned long int	li;

	li = n;
	lenb = ft_strlen(base);
	i = ft_digits_lu(li, lenb);
	res = ft_calloc(i + 1);
	if (!res)
		return (NULL);
	i--;
	while (i > 0)
	{
		res[i] = base[li % lenb];
		li = li / lenb;
		i--;
	}
	res[i] = base[li];
	return (res);
}

int	ft_printf_p(unsigned long int n, t_flags *flags, char *base)
{
	int		i;
	int		j;
	char	*s;
	char	*dest;

	s = ft_itoa_base_lu(n, base);
	dest = ft_calloc(ft_strlen(s) + 3);
	dest[0] = '0';
	dest[1] = 'x';
	i = 2;
	j = 0;
	if (ft_strlen(s) == 1 && flags->point)
		if (s[0] == '0')
			s[0] = '\0';
	while (s[j])
		dest[i++] = s[j++];
	free(s);
	if (flags->minus)
		return (ft_p_blanks_right(&dest, flags));
	return (ft_p_blanks_left(&dest, flags));
}
