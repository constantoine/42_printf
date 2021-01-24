#include "ft_printf.h"
#include <stdio.h>

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

	test("%04i.\n", -12);
	test("% .4i.\n", 12);
	test("%i.\n", -12);
	test("%0.i.\n", -12);
	test("%s\n", "Hello?");
	test("%s\n", NULL);
	test("%.2s\n", NULL);
	test("%s\n", "abcdefghijklmnop");
	test("%c\n", 'b');
	test("%c\n", '\0');
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
}
