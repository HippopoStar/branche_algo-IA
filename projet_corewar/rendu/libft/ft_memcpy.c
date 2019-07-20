/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:19:33 by cmiran            #+#    #+#             */
/*   Updated: 2019/06/22 12:57:15 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*tmp1;
	const char	*tmp2;

	if (dst == src)
		return (dst);
	tmp1 = (char *)dst;
	tmp2 = (const char *)src;
	while (n--)
		*tmp1++ = *tmp2++;
	return (dst);
}
