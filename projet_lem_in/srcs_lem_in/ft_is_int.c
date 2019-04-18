#include "libft.h"

int		ft_is_int(char *str, size_t *i, int *n)
{
	size_t	j;
	int		wit;

	j = *i;
	if (*(str + j) == '+' || *(str + j) == '-')
	{
		j++;
	}
	if (!ft_isdigit(*(str + j)))
	{
		return (0);
	}
	wit = 0;
	while (ft_isdigit(*(str + j)))
	{
		if (*(str + j) != '0')
		{
			wit = 1;
		}
		j++;
	}
	if ((*n = ft_atoi(str + (*i))) == 0 && wit == 1)
	{
		return (0);
	}
	else
	{
		*i = j;
		return (1);
	}
}
