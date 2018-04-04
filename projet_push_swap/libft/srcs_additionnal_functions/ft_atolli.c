#include "libft.h"

/*
** '/t' correspont a 'tabulation horizontale'
** '/n' correspont a 'retour a la ligne'
** '/v' correspont a 'tabulation verticale'
** '/f' correspond a 'saut de page'
** '/r' correspond a 'retour chariot'
** ' '  correspond a un espace
**
** 'p_o_n' correspond a 'positive_or_negative' dans la fonction 'ft_atolli'
*/

long long int	ft_atolli(const char *str)
{
	size_t			i;
	unsigned long long int	n;
	unsigned long long int	lli_max;
	int			p_o_n;

	lli_max = 9223372036854775807;
	i = 0;
	while (*(str + i) == '\t' || *(str + i) == '\n' || *(str + i) == '\v'
			|| *(str + i) == '\f' || *(str + i) == '\r' || *(str + i) == ' ')
	{
		i++;
	}
	p_o_n = 1;
	if (*(str + i) == '+' || *(str + i) == '-')
	{
		if (*(str + i) == '-')
			p_o_n = -1;
		i++;
	}
	n = ft_atoulli((const char *)(str + i));
	return (((p_o_n == -1 && n > (lli_max + 1)) || (p_o_n == 1 && n > lli_max)) ?
			0 : (long long int)p_o_n * (long long int)n);
}
