
#include <stdio.h>

int	ft_printf(char *c, ...);

int main()
{
	ft_printf("[%c][%s][%p][%d][%i][%u][%x][%X][%%]\n", 'a', "salut", "'\12'", 14, 16, -16, 489, 1256);
	   printf("[%c][%s][%p][%d][%i][%u][%x][%X][%%]\n", 'a', "salut", "'\12'", 14, 16, -16, 489, 1256);
}