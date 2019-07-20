/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:25:55 by cmiran            #+#    #+#             */
/*   Updated: 2017/11/15 00:30:29 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*cdst;
	const char	*csrc;

	i = 0;
	cdst = (char *)dst;
	csrc = (const char *)src;
	while (i < n)
	{
		cdst[i] = csrc[i];
		if ((csrc[i]) == (char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
