/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:08:49 by cmiran            #+#    #+#             */
/*   Updated: 2017/11/29 20:01:56 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (ft_strlen(dst) > size)
		return (ft_strlen(src) + size);
	i = 0;
	while (dst[i])
		i++;
	while (*src && i < size - 1)
		dst[i++] = *src++;
	dst[i] = '\0';
	return (i + ft_strlen(src));
}
