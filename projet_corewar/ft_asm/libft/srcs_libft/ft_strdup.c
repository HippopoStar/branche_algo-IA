/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:34:34 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/09 10:41:56 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	length;
	char	*s2;

	length = ft_strlen(s1);
	if (!(s2 = (char *)malloc((length + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i <= length)
	{
		*(s2 + i) = *(s1 + i);
		i++;
	}
	return (s2);
}
