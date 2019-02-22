/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:35:14 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/28 01:23:20 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*aux_ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	length;
	char	*map;

	length = ft_strlen(s);
	if (!(map = (char *)malloc((length + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < length)
	{
		*(map + i) = f(*(s + i));
		i++;
	}
	*(map + length) = '\0';
	return (map);
}

char		*ft_strmap(char const *s, char (*f)(char))
{
	return ((s != NULL) ? aux_ft_strmap(s, f) : NULL);
}
