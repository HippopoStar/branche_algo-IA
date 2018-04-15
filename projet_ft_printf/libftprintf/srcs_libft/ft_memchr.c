/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:57:46 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/15 21:10:23 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	byte;
	unsigned char	*cast_s;

	byte = (unsigned char)c;
	cast_s = (unsigned char *)s;
	i = 0;
	while (i < n && *(cast_s + i) != byte)
	{
		i++;
	}
	if (i < n)
	{
		return ((void *)(s + i));
	}
	else
	{
		return (NULL);
	}
}
