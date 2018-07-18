/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 03:35:18 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/25 23:06:40 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	length_dst;

	length_dst = ft_strlen(dst);
	i = 0;
	if (size > 0)
	{
		while (*(src + i) != '\0' && length_dst + i < size - 1)
		{
			*(dst + length_dst + i) = *(src + i);
			i++;
		}
	}
	*(dst + length_dst + i) = '\0';
	while (*(src + i) != '\0')
	{
		i++;
	}
	return ((size < length_dst) ? size + i : length_dst + i);
}
