/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:31:20 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/15 18:40:07 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cast_dst;
	unsigned char	*cast_src;

	cast_dst = (unsigned char *)dst;
	cast_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*(cast_dst + i) = *(cast_src + i);
		i++;
	}
	return (dst);
}
