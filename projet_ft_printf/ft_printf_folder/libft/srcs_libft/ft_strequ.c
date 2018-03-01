/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:23:26 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/28 01:32:00 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	aux_ft_strequ(char const *s1, char const *s2)
{
	size_t	i;

	i = 0;
	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0' && *(s2 + i) != '\0')
	{
		i++;
	}
	if (*(s1 + i) == *(s2 + i))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int			ft_strequ(char const *s1, char const *s2)
{
	return ((s1 != NULL && s2 != NULL) ? aux_ft_strequ(s1, s2) : 0);
}
