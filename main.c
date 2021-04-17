#include "ft_printf.h"

void	test_char()
{
	// NO PADDING/precision CON CHAR
	char	c = 'a';
	char	d = 'a';
	int		i = 0;
	int		j = 0;

	printf("Carattere con printf: ");
	i = printf("%10c", c);
	printf("\n");
	ft_printf("Carattere con ft_printf: ");
	j = ft_printf("%10c", d);
	printf("\n");
	printf("%d = %d\n", i, j);

	i = printf(" -%*c* -%-*c* ", -2, 0, 2, 0);
	j = ft_printf(" -%*c* -%-*c* ", -2, 0, 2, 0);
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
	int		n = 2147483647;
	int 	i, j;

	// Meno ++ Width > Precision > Lenght
	// Stampa a DESTRA i BLANKS (width - precision)
	// Stampa a SINISTRA 0 + numero fino ad arrivare alla precision
	i = printf("####%-25.10i#####\n", n + 1);
	j = ft_printf("####%-25.10i#####\n", n + 1);
	printf("%i = %i\n", i, j);
	//printf("n1 = %i\n", i); // = %i\n", i, j);

	i = printf("####%25i#####\n", n);
	j = ft_printf("####%25i#####\n", n);
	printf("%i = %i\n", i, j);
	//printf("n1 = %i\n", i); // = %i\n", i, j);
	
	i = printf("####%.10i#####\n", n);
	j = ft_printf("####%.10i#####\n", n);
	//printf("%i = %i\n", i, j);
	printf("n1 = %i\n", i); // = %i\n", i, j);
	printf("n1 = %i\n", j);

	i = printf("####%-25.10i#####\n", n);
	j = ft_printf("####%-25.10i#####\n", n);
	printf("%i = %i\n", i, j);
	// printf("n1 = %i\n", i); // = %i\n", i, j);

	// Width > precision =>
		// Stampa a 
	i = printf("####%25.10i#####\n", n);
	j = ft_printf("####%25.10i#####\n", n);
	printf("%i = %i\n", i, j);
	// printf("n1 = %i\n", i); // = %i\n", i, j);

	i = printf("####%20.10i#####\n", n);
	j = ft_printf("####%20.10i#####\n", n);
	//printf("%i = %i\n", i, j);
	printf("n1 = %i\n", i); // = %i\n", i, j);
	printf("n2 = %i\n", j);

	i = printf("####%-15i#####\n", n);
	j = ft_printf("####%-15i#####\n", n);
	//printf("%i = %i\n", i, j);
	printf("n1 = %i\n", i); // = %i\n", i, j);
	printf("n7 = %i\n", j);

	// Minus ++ Precision > Width ( < Lenght)
	// Se la precision è piu alta della Width
	// Stampa a SINISTRA un numero di zeri uguale a = Precision - Lenght
	i = printf("####%-25.50i#####\n", n);
	j = ft_printf("####%-25.50i#####\n", n);
	printf("n2 = %i\n", i); // = %i\n", i, j);
	printf("n2 = %i\n", j);

	i = printf("####%25.50i#####\n", n);
	j = ft_printf("####%25.50i#####\n", n);
	printf("n3 = %i\n", i); // = %i\n", i, j);
	printf("n3 = %i\n", j);

	i = printf("####%-50.25i#####\n", n);
	j = ft_printf("####%-50.25i#####\n", n);
	// printf("n2 = %i\n", i); // = %i\n", i, j);
	printf("x ..... %i = %i\n", i, j);


	i = printf("####%50.25i#####\n", n);
	j = ft_printf("####%50.25i#####\n", n);
	// printf("n3 = %i\n", i); // = %i\n", i, j);
	printf("%i = %i\n", i, j);

	// No minus
	// Width > Precision
	// Printa 25 caratteri
	// A SINISTRA mette #BLANKS = width - precision
	// A SINISTRA subito dopo i Blanks
		// Mette #0 = Width - precision - lenght
	// Poi metto il numero
	i = printf("####%25.20i#####\n", n);
	 j = ft_printf("####%25.20i#####\n", n);
	// printf("n4 = %i\n", i); // = %i\n", i, j);
	printf("%i = %i\n", i, j);


	

	// Width = 0 ;
	// Precision > lenght
		// #0 = Precision - lenght
	//i = printf("####%.20i#####\n", n);
	// j = ft_printf("####%.20i#####\n", n);
	// printf("%i = %i\n", i, j);

	// Minus si
	// Precision < legnth = ignora
	// Width presente si printano a DESTRA
		// #BLANKS = width - lenght
	i = printf("####%-10.4i#####\n", n);
	j = ft_printf("####%-10.4i#####\n", n);
	// printf("n6 = %i\n", i); // = %i\n", i, j);
	printf("%i = %i\n", i, j);
}

void	test_hex()
{
	int		x = 2147483647;
	int		i, j;

	i = printf("T###%056X#####\n", x);
	j = ft_printf("F###%056X#####\n", x);
}

void	test_ptr()
{
	int		i;
	char	*s;
	float	f[5];
	t_flags	t;

	void *g = &i;

	printf("Puntatore con printf:\n#%-55p#\n", &i);
	
	ft_printf("Puntatore con printf:\n#%-55p#\n", &i);
}

void	test_uns()
{
	unsigned int	x = 2147483648;
	int				i, j;

	i = printf("T###%-26.25u#####\n", x);
	j = ft_printf("F###%-26.25u#####\n", x);
}

int		main(void)
{
	int i;
	int j;
	//test_str();
	// test_integer();

	printf("\n\n\n-----------------start uns-----------------\n\n\n");

	// i = printf("#%-3.s#\n", NULL);
	// j = ft_printf("#%-3.s#\n", NULL);
	// printf("%d = %i\n", i, j);
	
	// i = printf("#%9.7s#\n", NULL);
	// j = ft_printf("#%9.7s#\n", NULL);
	// printf("%d = %i\n", i, j);

	i = printf("#%-7.12s#\n", NULL);
	j = ft_printf("#%-7.12s#\n", NULL);
	printf("%d = %i\n", i, j);

	// i = printf("#%-*c#\n", 10, '1');
	// j = ft_printf("#%-*c#\n", 10, '1');
	// printf("%d = %i\n", i, j);

}