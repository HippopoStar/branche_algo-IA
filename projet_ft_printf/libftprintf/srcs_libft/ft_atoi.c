/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:42:05 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/25 23:45:25 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** '/t' correspont a 'tabulation horizontale'
** '/n' correspont a 'retour a la ligne'
** '/v' correspont a 'tabulation verticale'
** '/f' correspond a 'saut de page'
** '/r' correspond a 'retour chariot'
** ' '  correspond a un espace
**
** 'p_o_n' correspond a 'positive_or_negative' dans la fonction 'aux_ft_atoi'
*/

static long long int	aux_ft_atoi(const char *str)
{
	size_t		i;
	long long int	n;
	int		p_o_n;

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
	n = 0;
	while ('0' <= *(str + i) && *(str + i) <= '9')
	{
		n = (n * 10) + (*(str + i) - '0');
		i++;
	}
	return ((long long int)p_o_n * n);
}

int			ft_atoi(const char *str)
{
	long long int	n;

	n = aux_ft_atoi(str);
	return ((-2147483648 <= n && n <= 2147483647) ? (int)n : 0);
}
