#include <stdio.h>

#include "libft/libft.h"
#include "src/ft_printf.h"

#define TEST(name, format, ...) printf("\n\n ======= TEST : %s ==================\n\nformat:%s\n", name, format); printf("0"format, __VA_ARGS__); ft_printf("1"format, __VA_ARGS__); printf("\n");

#define TESTS

int	main(int argc, char** argv) {
#ifdef TESTS
	TEST("A", "[%#010x]\t[%#10x]\t[%#.10x]\t[%.10x]\t\n", 1142, 1142, 1142, 1142);

	TEST("B", "[%#010x]\t[%#-10x]\t[%#-.10x]\t[%-.10x]\t\n", 1142, 1142, 1142, 1142);

	TEST("C", "[%#03x]\t[%#3x]\t[%#.3x]\t[%.3x]\t\n", 1142, 1142, 1142, 1142);

	TEST("D", "[%#03x]\t[%#-3x]\t[%#-.3x]\t[%-.3x]\t\n", 1142, 1142, 1142, 1142);

	TEST("E", "[% 5d]\t[% 5d]\t[%- 5d]\t[%- 5d]\t\n", 42, -42, 42, -42);

	TEST("F", "[%+d]\t[%+d]\t[%+5d]\t[%+5d]\t\n", 10, -10, 10, -10);

	TEST("G", "[%+05d]\t[%+05d]\t[%+.5d]\t[%+.5d]\t\n", 10, -10, 10, -10);

	TEST("H", "[%-+5d]\t[%-+5d]\t\n", 10, -10);

	TEST("I", "[%01d]\t[%.1d]\t[%06x]\t[%.6x]\n", 456, 456, 142, 142);

	TEST("J", "[%04d]\t[%0 4d]\t[%0+4d]\t[%#4x]\t\n", 5, 5, 5, 5);

	TEST("K", "[%.4d]\t[% .4d]\t[%+.4d]\t[%#.4x]\t\n", 5, 5, 5, 5);

	TEST("L", "[%7.4d]\t[% 7.4d]\t[%+7.4d]\t[%#7.4x]\t\n", 5, 5, 5, 5);

	TEST("M", "[%4s]\t[%4s]\t[%.4s]\t[%.4s]\t\n", "01", "012345", "01", "012345");

	TEST("N", "[%4.4s]\t[%5.4s]\t[%-4.4s]\t[%-8.4s]\t\n", "01", "012345", "01", "012345");

#else
	ft_printf("%#-0*.*x", 4, 8, 16);
#endif
}