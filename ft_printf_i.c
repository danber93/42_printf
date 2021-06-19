/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbertill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:57:50 by dbertill          #+#    #+#             */
/*   Updated: 2021/05/08 15:59:33 by dbertill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// #include <stdio.h>
int	ft_i_padding_blanks_left(char *s, t_flags *flags)
{
	int		zeros;
	int		blanks;

	zeros = 0;
	if (flags->precision > ft_strlen(s) - ft_is_neg(s))
	{
		zeros = flags->precision - ft_strlen(s) + ft_is_neg(s);
		blanks = flags->width - zeros - ft_strlen(s);
	}
	else
	{
		blanks = flags->width - ft_strlen(s);
		// printf("\n blanks = %i", blanks);
		if (flags->zero && (!flags->point || flags->precision < 0))
		{
			zeros = blanks;
			blanks = 0;
		}
	}
	// printf("\n zeros = %i\n", zeros);
	return (ft_i_padding_blanks_left_2(s, flags, blanks, zeros));
}

int	ft_i_padding_blanks_right_2(char *s, t_flags *flags, int i, char *dest)
{
	int	zeros;

	zeros = flags->precision - ft_strlen(s) + ft_is_neg(s);
	if (zeros < 0)
		zeros = 0;
	while (i < zeros + ft_is_neg(s))
		dest[i++] = '0';
	while (i < zeros + ft_strlen(s))
	{
		dest[i] = s[i - zeros];
		i++;
	}
	while (i < flags->width)
		dest[i++] = ' ';
	free(s);
	return (ft_result(dest));
}

int	ft_i_padding_blanks_right(char *s, t_flags *flags)
{
	int		i;
	char	*dest;

	dest = ft_calloc(flags->width);
	if (!dest)
		return (-1);
	i = 0;
	if (s[0] == '-')
		dest[i++] = '-';
	// if (ft_strlen(s) == 1 && s[0] == '0' && flags->point == 1
	// 	&& flags->precision <= 0)
	// 	s[0] = '0';
	if (ft_strlen(s) == 1 && s[0] == '0' && flags->precision == 0
		&& flags->width > flags->precision && flags->minus)
		s[0] = ' ';
	if (ft_strlen(s) == 1 && s[0] == '0' && flags->point == 1 && flags->precision == -1 && flags->star_precision == 0)
		s[0] = ' ';
	return (ft_i_padding_blanks_right_2(s, flags, i, dest));
}

int	ft_printf_i_utils(t_flags *flags, char **s)
{
	if (flags->width > flags->precision)
	{
		if (flags->width == 0 && flags->precision == -1 && (*s)[0] == '0')
		{
			free(*s);
			return (0);
		}
		if (flags->width <= ft_strlen(*s))
		{
			if (ft_strlen(*s) == 1)
				if ((*s)[0] == '0' && !(flags->star_precision == 1 && flags->precision != 0))
					(*s)[0] = ' ';
			return (ft_result(*s));
		}
		if (!flags->minus)
			return (ft_i_padding_blanks_left(*s, flags));
		return (ft_i_padding_blanks_right(*s, flags));
	}
	return (0);
}

int	ft_printf_i(int n, t_flags *flags, char *base)
{
	char	*s;

	s = ft_itoa_base(n, base);
	if (flags->width == 1 && flags->point == 0)
		return (ft_result(s));
	if (flags->width == 0 && flags-> point == 1 && flags->star_precision == 1 && flags->precision < 0)
		return (ft_result(s));
	if (!(flags->point) && !(flags->width))
		return (ft_result(s));
	if (flags->precision >= flags->width)
	{
		if (flags->precision <= ft_strlen(s) - ft_is_neg(s))
		{
			if (flags->precision <= 0 && s[0] == '0')
			{
				free(s);
				return (0);
			}
			else
				return (ft_result(s));
		}
		return (ft_i_padding_left(s, flags));
	}
	return (ft_printf_i_utils(flags, &s));
}
