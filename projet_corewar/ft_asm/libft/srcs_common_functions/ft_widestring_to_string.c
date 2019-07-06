/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widestring_to_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 03:25:22 by lcabanes          #+#    #+#             */
/*   Updated: 2019/02/09 17:47:06 by lcabanes         ###   ########.fr       */
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
** [ 1100 0000 | 1000 0000 ]
**	= 49 152 + 128
**	= 49 280
** [ 1110 0000 | 0000 0000 | 0000 0000 ] = 14 680 064
** [ 1110 0000 | 1000 0000 | 1000 0000 ]
**	= 14 680 064 + 32 768 + 128
**	= 14 712 960
** [ 1111 0000 | 0000 0000 | 0000 0000 | 0000 0000 ] = 4 026 531 840
** [ 1111 0000 | 1000 0000 | 1000 0000 | 1000 0000 ]
**	= 4 026 531 840 + 8 388 608 + 32 768 + 128
**	= 4 034 953 344
*/

static void	ft_widechar_to_string(wint_t widechar, char stock[5])
{
	unsigned int	n;
	size_t			i;

	n = 0;
	i = 0;
	while (widechar != L'\0')
	{
		if (i == 6 || i == 14 || i == 22)
		{
			i = i + 2;
		}
		n = n + (((unsigned int)widechar % 2) << i);
		i++;
		widechar = widechar >> 1;
	}
	if (n >> 20 > 0)
		n = n + 4034953344;
	else if (n >> 13 > 0)
		n = n + 14712960;
	else
		n = n + 49280;
	ft_unsigned_int_to_string(n, stock);
}

static void	aux1_ft_widestring_to_string(char stock[5], wint_t widechar)
{
	if ((((unsigned int)widechar) >> 7) == 0)
	{
		*(stock + 0) = (char)widechar;
		*(stock + 1) = '\0';
	}
	else
	{
		ft_widechar_to_string(widechar, stock);
	}
}

static void	aux0_ft_widestring_to_string(char **str, wchar_t *widestring,\
												size_t cur_len, size_t *spac)
{
	char	stock[5];
	size_t	stock_len;

	if (*widestring == L'\0')
	{
		*spac = (*spac < cur_len) ? cur_len : *spac;
		if ((*str = (char *)malloc((*spac + 1) * sizeof(char))) != NULL)
		{
			*((*str) + *spac) = '\0';
			*spac = *spac - cur_len;
		}
	}
	else
	{
		aux1_ft_widestring_to_string(stock, (wint_t)*widestring);
		stock_len = ft_strlen(stock);
		aux0_ft_widestring_to_string(str, widestring + 1,\
													cur_len + stock_len, spac);
		if ((*str) != NULL)
		{
			ft_strncpy((*str) + (*spac + cur_len), stock, stock_len);
		}
	}
}

char		*ft_widestring_to_string(wchar_t *widestring, size_t spac)
{
	char			*str;
	size_t			i;

	str = NULL;
	aux0_ft_widestring_to_string(&str, widestring, 0, &spac);
	i = 0;
	while (i < spac)
	{
		*(str + i) = ' ';
		i++;
	}
	return (str);
}
