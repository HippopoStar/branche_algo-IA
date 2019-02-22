/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:34:09 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/28 01:38:45 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*aux_ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	length_s1;
	size_t	length_s2;
	char	*concat;

	length_s1 = ft_strlen(s1);
	length_s2 = ft_strlen(s2);
	if (!(concat = (char *)malloc((length_s1 + length_s2 + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < length_s1)
	{
		*(concat + i) = *(s1 + i);
		i++;
	}
	i = 0;
	while (i < length_s2)
	{
		*(concat + length_s1 + i) = *(s2 + i);
		i++;
	}
	*(concat + length_s1 + length_s2) = '\0';
	return (concat);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	return ((s1 != NULL && s2 != NULL) ? aux_ft_strjoin(s1, s2) : NULL);
}
