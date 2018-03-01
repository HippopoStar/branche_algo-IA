/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 05:18:02 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/25 23:40:11 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (*(haystack + i) != '\0' && i < len)
	{
		j = i;
		k = 0;
		while (*(haystack + j) == *(needle + k) && *(needle + k) != '\0'
				&& j < len)
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
