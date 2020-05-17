#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("%04i.\n", -12);
	printf("%04i.\n", -12);
	ft_printf("% .4i.\n", 12);
	printf("% .4i.\n", 12);
	ft_printf("%i.\n", -12);
	printf("%i.\n", -12);
	ft_printf("%0.i.\n", -12);
	printf("%0.i.\n", -12);
}
