/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 05:06:19 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/25 23:39:54 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (*(haystack + i) != '\0')
	{
		j = i;
		k = 0;
		while (*(haystack + j) == *(needle + k) && *(needle + k) != '\0')
		{
			j++;
			k++;
		}
		if (*(needle + k) == '\0')
		{
			return ((char *)(haystack + i));
		}
		i++;
	}
	return ((*(needle + 0) == '\0') ? (char *)(haystack + 0) : NULL);
}
