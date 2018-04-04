#include "libft.h"

/*
** '/t' correspont a 'tabulation horizontale'
** '/n' correspont a 'retour a la ligne'
** '/v' correspont a 'tabulation verticale'
** '/f' correspond a 'saut de page'
** '/r' correspond a 'retour chariot'
** ' '  correspond a un espace
*/

unsigned long long int	ft_atoulli(const char *str)
{
	size_t			i;
	unsigned long long int	n;

	i = 0;
	while (*(str + i) == '\t' || *(str + i) == '\n' || *(str + i) == '\v'
			|| *(str + i) == '\f' || *(str + i) == '\r' || *(str + i) == ' ')
	{
		i++;
	}
	if (*(str + i) == '+')
	{
		i++;
	}
	n = 0;
	while ('0' <= *(str + i) && *(str + i) <= '9')
	{
		n = (n * 10) + (*(str + i) - '0');
		i++;
	}
	return (n);
}
