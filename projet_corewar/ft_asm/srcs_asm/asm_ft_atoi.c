/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_ft_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:27:33 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/08 17:56:10 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	return ((int)(!neg ? n : -n));
**	return (!neg ? (int)n : -((int)n));
*/

int		asm_ft_atoi(const char *str)
{
	unsigned int	n;
	char			neg;
	size_t			i;

	n = (char)0;
	neg = 0;
	i = 0;
	while (!(*(str + i) == '\0') && ft_strchr("\t\n\v\f\r ", (int)*(str + i)))
	{
		i++;
	}
	if (*(str + i) == '+' || *(str + i) == '-')
	{
		neg = *(str + i) == '-' ? (char)1 : neg;
		i++;
	}
	while ('0' <= *(str + i) && *(str + i) <= '9')
	{
		n = (10 * n) + (*(str + i) - '0');
		i++;
	}
	return (!neg ? (int)n : -((int)n));
}
