/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widestring_to_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 03:25:22 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/18 04:49:59 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "common_functions.h"

/*
** [0000 0001 | 0000 0000 | 0000 0000 | 0000 0000] = 2^(24)	= 16 777 216
** [0000 0000 | 0000 0001 | 0000 0000 | 0000 0000] = 2^(16)	= 65 536
** [0000 0000 | 0000 0000 | 0000 0001 | 0000 0000] = 2^(8)	= 256
** [0000 0000 | 0000 0000 | 0000 0000 | 0000 0001] = 2^(0)	= 1
*/

static void	ft_unsigned_int_to_string(unsigned int widechar, char stock[5])
{
	size_t	i;
	size_t	j;

	i = 4;
	j = 0;
	while (i != 0)
	{
		i--;
		if ((stock[j] = (char)((widechar >> (8 * i)) % 256)) != '\0')
		{
			j++;
		}
	}
	stock[j] = '\0';
}

/*
** On a :
** [ 1100 0000 | 0000 0000 ] = 49 152
** [ 1110 0000 | 0000 0000 | 0000 0000 ] = 14 680 064
** [ 1111 0000 | 0000 0000 | 0000 0000 | 0000 0000 ] = 4 026 531 840
*/

static void	ft_widechar_to_string(wint_t widechar, char stock[5])
{
	unsigned int	n;
	unsigned int	i;
	unsigned int	j;

	n = 0;
	i = 1;
	j = 1;
	while ((unsigned int)widechar / i != 0)
	{
		if (j >> 6 == 1 || j >> 14 == 1 || j >> 22 == 1)
		{
			n = n + (j << 1);
			j = j << 2;
		}
		n = n + ((((unsigned int)widechar / i) % 2) * j);
		i = i << 1;
		j = j << 1;
	}
	if (n >> 24 > 0)
		n = n + 4026531840;
	else if (n >> 16 > 0)
		n = n + 14680064;
	else if (n >> 8 > 0)
		n = n + 49152;
	ft_unsigned_int_to_string(n, stock);
}

static void	aux_ft_widestring_to_string(char *str, size_t *j, wint_t widechar)
{
	char	stock[5];

	if ((((unsigned int)widechar) >> 7) == 0)
	{
		*(str + *j + 0) = (char)widechar;
		*(str + *j + 1) = '\0';
		(*j)++;
	}
	else
	{
		ft_widechar_to_string(widechar, stock);
		ft_strcpy((str + *j), stock);
		*j = *j + ft_strlen(stock);
	}
}

char		*ft_widestring_to_string(wchar_t *widestring)
{
	char			*str;
	size_t			size;
	size_t			i;
	size_t			j;

	size = 0;
	while (*(widestring + size) != L'\0')
	{
		size++;
	}
	if (!(str = (char *)malloc(((4 * size) + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		aux_ft_widestring_to_string(str, &j, (wint_t)(*(widestring + i)));
		i++;
	}
	*(str + j) = '\0';
	return (str);
}
