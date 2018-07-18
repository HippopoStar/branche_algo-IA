/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:28:51 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/28 01:36:11 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*aux_ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (!(sub = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(sub + i) = *(s + start + i);
		i++;
	}
	*(sub + i) = '\0';
	return (sub);
}

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	return ((s != NULL) ? aux_ft_strsub(s, start, len) : NULL);
}
