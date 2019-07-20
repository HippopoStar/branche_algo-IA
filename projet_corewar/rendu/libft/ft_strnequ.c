/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 18:21:34 by cmiran            #+#    #+#             */
/*   Updated: 2017/11/29 16:37:00 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Compare lexicographiquement s1 et s2 jusqu’à n caractères maximum ou bien
** qu’un ’\0’ ait été rencontré. Si les deux chaines sont égales, la
** fonction retourne 1, ou 0 sinon.
*/

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
