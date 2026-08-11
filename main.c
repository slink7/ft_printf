#include <stdio.h>

#include "libft/libft.h"
#include "src/ft_printf.h"

int cnt = 0;
char *res[] = {"\e[1;31mKO\e[0m", "\e[1;32mOK\e[0m"};
int oks = 0;
int kos = 0;

#define TEST(name, format, ...) {\
	dprintf(1, "\n ======= TEST %d : %s : format:%s\n\t   printf: '", cnt++, name, format);\
	int a = dprintf(1, format, __VA_ARGS__);\
	dprintf(1, "'\n\tft_printf: '");\
	int b = ft_printf(format, __VA_ARGS__);\
	dprintf(1, "'\nreturn [%s]: %d | %d\n", res[a == b], a, b);\
	if (a == b) oks++; else kos++;\
}

#define TESTS

void	tests_cs() {
	TEST("S0", "[%4s] [%4s] [%.4s] [%.4s] ", "01", "012345", "01", "012345");
	TEST("S1", "[%4.4s] [%5.4s] [%-4.4s] [%-8.4s] [%.6s] [%.5s] ", "01", "012345", "01", "012345", 0, 0);
	TEST("S2", "[%c] [%c] [%4c] [%-4c] ", '\0', 'F', 'F', 'F');
	TEST("S3", "[%%] [%4%] [%.4%] [%#0-4.4%] [ %%%% %%%%%%%%%% ] ", 0);
	TEST("S4", "[%c] [%c] [%c] [%c] [%c]", '0', '0' - 256, 0, '1', '2');
	TEST("S5", "[%c] [%c] [%c]", '0', 0, '1');
	TEST("S6", "[%c] [%c] [%c]", '2', '1', 0);
	TEST("S7", "[%c] [%c] [%c]", 0, '1', '2');
}

void	tests_d() {
	TEST("D00", "[% 5d] [% 5d] [%- 5d] [%- 5d] ", 42, -42, 42, -42);
	TEST("D01", "[%+d] [%+d] [%+5d] [%+5d] ", 10, -10, 10, -10);
	TEST("D02", "[%+05d] [%+05d] [%+.5d] [%+.5d] ", 10, -10, 10, -10);
	TEST("D03", "[%-+5d] [%-+5d] ", 10, -10);
	TEST("D04", "[%04d] [%0 4d] [%0+4d] [%#4d] ", 5, 5, 5, 5);
	TEST("D05", "[%.4d] [% .4d] [%+.4d] [%#.4d] ", 5, 5, 5, 5);
	TEST("D06", "[%7.4d] [% 7.4d] [%+7.4d] [%#7.4d] ", 5, 5, 5, 5);
	TEST("D07", "[%d] [%d] [%d] [%d] [%d]", 0, 42, -42, 0x7FFFFFFF, 0x80000000);
	TEST("D08", "[%d] [%d] [%d] [%d] [%d] [%d]", -1, -12, -23, -89, -90, -101);
	TEST("D09", "[%d] [%d] [%d] [%d]", -0, -4, -9, -7);
	TEST("D10", "[%.5d] [%.6d]", -4, -666);
	TEST("D11", "[%6.4d] [%06d]", -42, -42);
	TEST("D12", "[%1d] [%-1d] [%1.1d] [%-1.1d]", 0, 0, 0, 0);
	TEST("D13", "[%.0d] [%.d]", 0, 0);
	TEST("D13", "[%.4d] [%.0d]", 69420, 69420);
	TEST("D13", "[%-10.d] [%0-10.d] [%01.0d] [%1.0d]", 0, 0, 0, 0);
}

void	tests_u() {
	TEST("U0", "[%#010x] [%#10x] [%#.10x] [%.10x] ", 1142, 1142, 1142, 1142);
	TEST("U1", "[%#010x] [%#-10x] [%#-.10x] [%-.10x] ", 1142, 1142, 1142, 1142);
	TEST("U2", "[%#03x] [%#3x] [%#.3x] [%.3x] ", 1142, 1142, 1142, 1142);
	TEST("U3", "[%#03x] [%#-3x] [%#-.3x] [%-.3x] ", 1142, 1142, 1142, 1142);
	TEST("U4", "[%01x] [%.1x] [%06x] [%.6x]", 456, 456, 142, 142);
	TEST("U5", "[%u] [%u] [%5u] [%.5u] [%8.4u] [%-5u] [%-8.4u]", 0, 0xFFFFFFFF, 42, 42, 42, 42, 42);
	TEST("U6", "[%u] [%05u] [%+4u] [% 4u] [% u] [%#.4u]", 12, 3, 8, 24, 42, 99)
	TEST("U7", "[%#8.4x] [%#-8.4x] [%#0-8.0x]", 17, 18, 19);
	TEST("U8", "[%1u] [%1u]", 6, 0);

}

void	test_p() {
	char *p = "";
	TEST("P0", "[%p] [%p]", 0, p);
	TEST("P0", "[%1.1p] [%1.1p]", 0, p);
	TEST("P1", "[%20p] [%.20p]", p, p);
	TEST("P2", "[%-20p] [%-.20p]", p, p);
	TEST("P2", "[%-20p] [%-.20p]", 0, 0);
	TEST("P2", "[%20p] [%.20p]", 0, 0);
	TEST("P2", "[%020p] [%.20p]", 0, 0);
}

void	test_null() {
	TEST("NULL0", " 01234\00056789", 0);
	TEST("NULL1", "", 0);
	TEST("NULL2", "%d", 0);
	TEST("NULL3", "%c salut %c", 0, 0);
	TEST("NULL4", "%5c now you see", '\0')
}

void	test_unhandled() {
	TEST("UH0", "%f %g %o", 16.0f, 156, 80);
	TEST("UH1", "%156% %-% %+- .5%", 16.0f, 156, 80);
}

#include <stdio.h>

int	main(int argc, char** argv) {
	tests_cs();
	tests_d();
	tests_u();
	test_p();
	test_null();
	test_unhandled();
	dprintf(1, "\n\n\tTotal [%s]: % 3d / % 3d\n\tTotal [%s]: % 3d / % 3d\n", res[0], kos, cnt, res[1], oks, cnt);
}
