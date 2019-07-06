/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 21:02:33 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/26 01:55:55 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cast_s1;
	unsigned char	*cast_s2;

	cast_s1 = (unsigned char *)s1;
	cast_s2 = (unsigned char *)s2;
	if (n == 0)
	{
		return (0);
	}
	else
	{
		i = 0;
		while (i < n - 1 && *(cast_s1 + i) == *(cast_s2 + i))
		{
			i++;
		}
		return ((int)((*(cast_s1 + i)) - (*(cast_s2 + i))));
	}
}
