/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 03:18:50 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/17 03:27:05 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	length_s1;

	length_s1 = ft_strlen(s1);
	i = 0;
	while (*(s2 + i) != '\0')
	{
		*(s1 + length_s1 + i) = *(s2 + i);
		i++;
	}
	*(s1 + length_s1 + i) = '\0';
	return (s1);
}
