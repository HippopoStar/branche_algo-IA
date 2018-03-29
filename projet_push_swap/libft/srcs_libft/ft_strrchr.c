/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 04:49:52 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/17 08:32:34 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	length;
	char	character;

	length = ft_strlen(s);
	character = (char)c;
	i = 0;
	while (i <= length)
	{
		if (*(s + length - i) == character)
		{
			return ((char *)(s + length - i));
		}
		i++;
	}
	return (NULL);
}
