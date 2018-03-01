/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 04:44:21 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/17 06:03:35 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	character;

	character = (char)c;
	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == character)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if (*(s + i) == character)
	{
		return ((char *)(s + i));
	}
	else
	{
		return (NULL);
	}
}
