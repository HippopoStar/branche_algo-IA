/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:32:28 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/26 01:57:33 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
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
		while (*(s1 + i) == *(s2 + i) && i < n - 1
				&& *(s1 + i) != '\0' && *(s2 + i) != '\0')
		{
			i++;
		}
		return ((int)((*(cast_s1 + i) - *(cast_s2 + i))));
	}
}
