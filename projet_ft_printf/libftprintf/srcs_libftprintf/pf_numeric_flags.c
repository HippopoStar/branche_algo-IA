/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_numeric_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 00:52:27 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/25 03:34:51 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	pf_deal_zero(const char *format, char *str, size_t keep)
{
	size_t	i;

	if (pf_is_flag_present(format, '0')
		&& !(pf_is_flag_present(format, '-')
			|| pf_is_flag_present(format, '.')))
	{
		i = keep;
		while (*(str + i) == ' ' && *(str + i) != '\0')
		{
			*(str + i) = '0';
			i++;
		}
		if (*(str + i) == '-')
		{
			*(str + i) = '0';
			*(str + 0) = '-';
		}
	}
}

/*
**	ft_putstr("Appel de \"pf_deal_minus_sign\"\n");
** La variable 'keep' vaut :
** - 1 si la conversion est un nombre signe
** et que le flag '+' ou le flag ' ' est present,
** - 0 sinon
*/

void	pf_deal_minus_sign(const char *format, char *str, size_t keep)
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
}
