/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:42:05 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/12 06:37:24 by lcabanes         ###   ########.fr       */
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
** 'a % b' donne le reste de la division euclidienne de 'a' par 'b'
** | par consequent, dans le cas ou 'a' est negatif, cela ne donne pas	|
** | l'element de la classe d'equivalence de 'a' pour la congruence	|
** | modulo 'b' compris entre 0 et b-1					|
**
** Aux yeux de l'ordinateur, on a :
** INT_MIN 	= -INT_MIN
**		= -1 * INT_MIN
**
** [0111 1111 | 1111 1111 | 1111 1111 | 1111 1111]	= 2147483647	(INT_MAX)
** [1111 1111 | 1111 1111 | 1111 1111 | 1111 1111]	= -2147483647	(-INT_MAX)
** [1000 0000 | 0000 0000 | 0000 0000 | 0000 0000]	= -2147483648	(INT_MIN)
*/

static void	ft_atoi_initialize(int *n, int neg, int *a, int *b)
{
	*n = 0;
	*a = !neg ? (FT_INT_MAX / 10) : (-(FT_INT_MIN / 10));
	*b = !neg ? (FT_INT_MAX % 10) : (-(FT_INT_MIN % 10));
}

static int	ft_atoi_add(int *n, char c, int a, int b)
{
	int	to_add;

	if ('0' <= c && c <= '9')
	{
		to_add = c - '0';
		if (*n < a || (*n == a && to_add <= b))
		{
			*n = (*n * 10) + to_add;
			return (1);
		}
		else
		{
			*n = 0;
			return (0);
		}
	}
	else
	{
		return (0);
	}
}

int			ft_atoi(const char *str)
{
	size_t	i;
	int		n;
	int		neg;
	int		a;
	int		b;

	i = 0;
	while (*(str + i) == '\t' || *(str + i) == '\n' || *(str + i) == '\v'
			|| *(str + i) == '\f' || *(str + i) == '\r' || *(str + i) == ' ')
	{
		i++;
	}
	neg = 0;
	if (*(str + i) == '+' || *(str + i) == '-')
	{
		if (*(str + i) == '-')
			neg = 1;
		i++;
	}
	ft_atoi_initialize(&n, neg, &a, &b);
	while (ft_atoi_add(&n, *(str + i), a, b))
	{
		i++;
	}
	return (!neg ? n : -n);
}
