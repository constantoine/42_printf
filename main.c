#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

#define test(format, ...) {\
	standard = printf(format, __VA_ARGS__);\
	ret = ft_printf(format, __VA_ARGS__);\
	if (standard != ret)\
		printf("Expected: %d got %d. Formatter: \"%s\"\n", standard, ret, format);\
}

int	main(void)
{
	int		standard;
	int		ret;
	char	*ptr;
	int		a = 12;
	int		b = 18;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	test("|%-2.6s|\n", NULL);
	test("%.4s\n", NULL);
	test("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL);
	return 0;
	test("%.*d", -4, 15);
	return 0;
	test("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
	return 0;
	test("%%", "");
	return 0;
	test(" --0*%0*.0d*0 0*%0*.10d*0-- \n", -21, INT_MAX, 21, INT_MIN);
	return 0;
	ptr = ft_strdup("bite");
	test("%p\n", ptr);
	test("%15p\n", ptr);
	test("%3p\n", ptr);
	test("%-p\n", ptr);
	test("%-15p\n", ptr);
	test("%-3p\n", ptr);
	test("%p\n", NULL);
	test("%15p\n", NULL);
	test("%3p\n", NULL);
	test("%-p\n", NULL);
	test("%-15p\n", NULL);
	test("%-3p\n", NULL);
	free(ptr);
	return 0;

	test("%+ 4.0x\n", 0);
	test("%0+4.0x\n", 0);
	test("%+ .4x\n", 5165);
	test("%0+4x\n", 5165);
	test("%+x\n", 5165);
	test("%+0.x\n", 5165);
	test("%+-04x\n", 5165);
	test("%+- .4x\n", 5165);
	test("%+-x.\n", 5165);
	test("%+-0.x\n", 5165);
	test("%+04x.8\n", 5165);
	test("%+ .4x\n", 5165);
	test("%+x.8\n", 5165);
	test("%+0.8x\n", 5165);
	test("%+-04x\n", 5165);
	test("%+- .4x\n", 5165);
	test("%+-x\n", 5165);
	test("%+-0.8x\n", 5165);

	test("%+ 4.0u\n", 0);
	test("%0+4.0u\n", 0);
	test("%+ .4u\n", 15);
	test("%0+4u\n", 15);
	test("%+u\n", 15);
	test("%+0.u\n", 15);
	test("%+-04u\n", 15);
	test("%+- .4u\n", 15);
	test("%+-u.\n", 15);
	test("%+-0.u\n", 15);
	test("%+04u.8\n", 15);
	test("%+ .4u\n", 15);
	test("%+u.8\n", 15);
	test("%+0.8u\n", 15);
	test("%+-04u\n", 15);
	test("%+- .4u\n", 15);
	test("%+-u\n", 15);
	test("%+-0.8u\n", 15);

	test("%+ 4.0i\n", 0);
	test("%0+4.0i\n", 0);
	test("%+ .4i\n", 12);
	test("%0+4i\n", -12);
	test("%+i\n", -12);
	test("%+0.i\n", -12);
	test("%+-04i\n", -12);
	test("%+- .4i\n", 12);
	test("%+-i.\n", -12);
	test("%+-0.i\n", -12);
	test("%+04i.8\n", -12);
	test("%+ .4i\n", 12);
	test("%+i.8\n", -12);
	test("%+0.8i\n", -12);
	test("%+-04i\n", -12);
	test("%+- .4i\n", 12);
	test("%+-i\n", -12);
	test("%+-0.8i\n", -12);
	
	test("%+ 4.0i\n", 0);
	test("%0+4.0i\n", 0);
	test("%+ .4i\n", 12);
	test("%0+4i\n", -12);
	test("%+i\n", -12);
	test("%+0.i\n", -12);
	test("%+04i\n", -12);
	test("%+ .4i\n", 12);
	test("%+i.\n", -12);
	test("%+0.i\n", -12);
	test("%+04i.8\n", -12);
	test("%+ .4i\n", 12);
	test("% +i.8\n", -12);
	test("% +0.8i\n", -12);
	test("% +04i\n", -12);
	test("%+ .4i\n", 12);
	test("%+i\n", -12);
	test("%+0.8i\n", -12);
	//c
	test("%c\n", 'b');
	test("%c\n", '\0');

	// s
	test("%s\n", "Hello?");
	test("%s\n", NULL);
	test("%.2s\n", NULL);
	test("%s\n", "abcdefghijklmnop");
	test("Je (%c) suis %s\n", 'F', "homosexuelle");
	test("p0 % .3s\n", "cccc");
	test("p1 %.4s\n", "cccc");
	test("p2 %.10s\n", "cccc");
	test("p3 %.4s\n", NULL);
	test("p4 %.5s\n", "aaaaa");
	test("st7 %*.*s\n", 1, 50, "hey");
	test("st8 %*.*s\n", 0, 0, "coucou");
	test("st9 %*.*s\n", 0, 50, "hey");
	test("st10 %*.*s\n", 10, 0, "dsa");
	test("st11 %*.*s\n", 10, 10, "hello");
	test("st7 %0.*s\n", 50, "hey");
	test("st8 %.*s\n", 0, "coucou");
	test("st9 %*s\n", 0, "hey");
	test("st10 %*s\n", 10, "dsa");
	test("st7 %*.*s\n", 1, 50, "hey");
	test("st8 %*.*s\n", 0, 0, "coucou");
	test("st9 %*.*s\n", 0, 50, "hey");
	test("st10 %*.*s\n", 10, 0, "dsa");
	test("st11 %*.*s\n", 10, 10, "hello");
	test("st7 %0.*s\n", 50, "hey");
	test("st8 %.*s\n", 0, "coucou");
	test("st9 %*s\n", 0, "hey");
	test("st10 %*s\n", 10, "dsa");
	test("st118 %*s\n", 100, "hello");
	test("st119 %*s\n", 1000, "hello");
	test("neg1 %*s\n", -9, "coucou");
	test("neg2 %*.*s\n", -9, 4, "coucou");
	test("neg3 %*s\n", -9, NULL);
	test("neg4 %*.*s\n", 0, 0, "coucou");
	test("neg5 %*s\n", -100, "coucou");
	test("neg6 %*s\n", -156, "coucou");
	test("neg7 %*.*s\n", -1586, 15, "coucou");
	test("neg9 %*.*s\n", -1856, 155, "coucou");
	test("neg9 %*.*s\n", 1856, 155, "coucou");
	
	// x-X
	return 0;
	test("ultimate4 %1.50x\n", 5000);
	test("ultimate4Maj %1.0X\n", 100);
	
	// u
	//test("ultimate5 %*.*u\n", 1, 50, 5000);
}
