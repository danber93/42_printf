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
	char	*s = "iacovelli";

	t = 15;
	i = printf("T###%66.25s#####\n", s);
	j = ft_printf("F###%66.25s#####\n", s);
	printf("%d = %d\n", i, j);
	i = printf("T###%10.4s#####\n", s);
	j = ft_printf("F###%10.4s#####\n", s);
	printf("%d = %d\n", i, j);
}

void	test_integer()
{
	//La precision stampa di deafult a 7 caratteri

	// la precision quando è un intero stampa
	// stampa un padding sinistro di zeri per arrivare al numero di precision
	int		n = 5687567;
	int 	i, j;

	i = printf("####%-25.20i#####\n", n);
	j = ft_printf("####%-25.20i#####\n", n);
	printf("%i = %i\n", i, j);
	i = printf("####%-25.50i#####\n", n);
	j = ft_printf("####%-25.50i#####\n", n);
	printf("%i = %i\n", i, j);
	i = printf("####%25.20i#####\n", n);
	j = ft_printf("####%25.20i#####\n", n);
	printf("%i = %i\n", i, j);
	i = printf("####%.20i#####\n", n);
	j = ft_printf("####%.20i#####\n", n);
	printf("%i = %i\n", i, j);
	i = printf("####%-10.4i#####\n", n);
	j = ft_printf("####%-10.4i#####\n", n);
	printf("%i = %i\n", i, j);

}

int		main(void)
{
	test_str();

	printf("\n\n\n-----------------start intenger-----------------\n\n\n");

	test_integer();

	//ft_itoa_base(16, "0123456789abcdef");
}