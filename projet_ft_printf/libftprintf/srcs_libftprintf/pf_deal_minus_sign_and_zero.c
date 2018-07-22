#include "libftprintf.h"

/*
**	ft_putstr("Appel de \"pf_malloc_and_left_spaces\"\n");
*/

char	*pf_malloc_and_left_spaces(size_t spac, size_t length)
{
	char	*str;
	size_t	i;

	if (!(str = (char *)malloc((spac + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < spac - length)
	{
		*(str + i) = ' ';
		i++;
	}
	*(str + spac) = '\0';
	return (str);
}

/*
**	ft_putstr("Appel de \"pf_deal_minus_sign_and_zero\"\n");
** La variable 'keep' vaut :
** - 1 si la conversion est un nombre signe
** et que le flag '+' ou le flag ' ' est present,
** - 0 sinon
*/

void	pf_deal_minus_sign_and_zero(const char *format, char *str, size_t keep)
{
	size_t	i;
	size_t	decal;

	if (pf_is_flag_present(format, '-'))
	{
		decal = 0;
		while (*(str + decal + keep) == ' '
			&& *(str + decal + keep) != '\0')
		{
			decal++;
		}
		i = 0;
		if (decal > 0)
		{
			while (*(str + decal + i) != '\0')
			{
				*(str + i) = *(str + decal + i);
				*(str + decal + i) = ' ';
				i++;
			}
		}
	}
	else if (pf_is_flag_present(format, '0'))
	{
		i = 0;
		while (*(str + i) == ' ' && *(str + i) != '\0')
		{
			*(str + i) = '0';
			i++;
		}
	}
}
