#ifndef FT_PRINTF_H
# define FT_PRINTF_H


#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#include <stdio.h>

typedef	struct	s_flags
{
	int			minus;
	int			zero;
	int			star_width;
	int			star_precision;
	int			point;
	int			width;
	int			precision;
}				t_flags;

void	print_flags(t_flags *flags);

int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_handle_format(char f, t_flags *flags, va_list ap);
int		ft_printf_c(char c, t_flags *flags);
int		ft_printf_s(char *s, t_flags *flags);
int		ft_strlen(char *s);
char	*ft_strndup(char *s, char *d, int n);
char	*ft_s_padding(char *s, t_flags *flags);
char	*ft_s_padding_left(char *s, char *dest, t_flags *flags);
char	*ft_itoa_base(int n, char *base);
char	*ft_itoa_base_u(long int n, char *base);
int		ft_printf_i(int n, t_flags *flags, char *base);
char	*ft_calloc(int size);
int		ft_i_padding_blanks_left(char *s, t_flags *flags);
int		ft_i_padding_blanks_right(char *s, t_flags *flags);
char	*ft_cut_minus(char *s);
int		ft_is_neg(char *s);
int		ft_i_padding_left(char *s, t_flags *flags);
int		ft_printf_x(long int n, t_flags *flags, char *base);
int		ft_printf_p(unsigned long int n, t_flags *flags, char *base);
int		ft_printf_u(unsigned int n, t_flags *flags, char *base);
int		ft_result(char *s);
int		ft_c_padding_left(char c, t_flags *flags);	

#endif