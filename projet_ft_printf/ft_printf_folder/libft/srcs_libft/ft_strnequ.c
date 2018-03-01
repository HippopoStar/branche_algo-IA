/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:27:34 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/28 01:34:15 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	aux_ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (*(s1 + i) == *(s2 + i) && i < n
			&& *(s1 + i) != '\0' && *(s2 + i) != '\0')
	{
		i++;
	}
	if (*(s1 + i) == *(s2 + i) || i == n)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	return ((s1 != NULL && s2 != NULL) ? aux_ft_strnequ(s1, s2, n) : 0);
}
