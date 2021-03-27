#include "ft_printf.h"

void	test_char()
{
	// NO PADDING/precision CON CHAR
	char	c = 'a';
	char	d = 'a';
	int		i = 0;
	int		j = 0;

	printf("Carattere con printf: ");
	i = printf("%c", c);
	printf("\n");
	ft_printf("Carattere con ft_printf: ");
	j = ft_printf("%c", d);
	printf("\n");
	printf("%d = %d\n", i, j);
}

void	test_str()
{
	// padding ok
	// precision tronca se < str.length, else ignora
	int		i, j, t;
	char	*s = "ciao";

	t = 15;
	// printf("Stringa con printf: #");
	i = printf("T###%-7.*s####%5s#\n", 5, s, "test");
	// printf("Stringa con ft_printf: #");
	j = ft_printf("F###%-7.*s####%5s#\n", 5, s, "test");
	// printf("#\n");
	printf("%d = %d\n", i, j);
}

void	test_integer()
{
	//La precision stampa di deafult a 7 caratteri
	double	i = 3985.0123456789;

	// la precision quando è un intero stampa
	// stampa un padding sinistro di zeri per arrivare al numero di precision
	int		n = 56;
	int 	l;

	printf("Questo è con printf = ");
	l = printf("%*.*i", 4, 5, n);
	printf("F\n");
	printf("l = %d\n", l);
	ft_printf("Questo è con ft_printf = %0*.*iF\n", 32, 5, i);
}

int		main(void)
{
	test_str();
}