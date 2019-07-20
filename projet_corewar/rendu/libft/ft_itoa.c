/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:50:14 by cmiran            #+#    #+#             */
/*   Updated: 2017/11/29 17:04:20 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Alloue (avec malloc(3)) et retourne une chaine de caractères “fraiche”
** terminée par un ’\0’ représentant l’entier n passé en paramètre.
** Les nombres négatifs doivent être gérés. Si l’allocation échoue,
** la fonction renvoie NULL.
*/

#include "libft.h"

static size_t	ft_nb_len(int n)
{
	size_t	len;

	len = (n < 0) ? 2 : 1;
	while (n /= 10)
		len++;
	return (len);
}

char			*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	int		sign;

	len = ft_nb_len(n);
	if (!(str = (char *)malloc(sizeof(*str) * len + 1)))
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	sign = 1;
	if (n < 0)
	{
		str[0] = '-';
		sign -= 2;
	}
	while (n)
	{
		str[--len] = n % 10 * sign + '0';
		n /= 10;
	}
	return (str);
}
