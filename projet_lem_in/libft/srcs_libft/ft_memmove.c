/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:50:49 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/17 10:23:41 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*cast_dst;
	unsigned char	*cast_src;

	cast_dst = (unsigned char *)dst;
	cast_src = (unsigned char *)src;
	if (dst < src)
	{
		dst = ft_memcpy(dst, src, len);
	}
	else if (dst > src && len > 0)
	{
		i = len - 1;
		while (i > 0)
		{
			*(cast_dst + i) = *(cast_src + i);
			i--;
		}
		*(cast_dst + 0) = *(cast_src + 0);
	}
	return (dst);
}
