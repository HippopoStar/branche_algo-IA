/*
** Supprimer les 2 dernieres lignes de 'maps/elementary.map'
** gcc -Wall -Wextra -Werror maps/main_elementary_bachslash_zero.c
** ./a.out >> maps/elementary.map
** rm a.out
** ./lem-in -lc < maps/elementary.map
*/

#include <unistd.h>

int		main(void)
{
	write(1, "B 0 0\0A-B\n", 10);
	return (0);
}
