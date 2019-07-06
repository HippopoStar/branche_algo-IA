/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 07:53:33 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/18 08:02:32 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	size_t	i;
	size_t	length;
	char	*copy;

	if (str == NULL)
	{
		return (NULL);
	}
	length = 0;
	while (*(str + length) != '\0' && length < n)
	{
		length++;
	}
	if (!(copy = (char *)malloc((length + 1) * sizeof(char))))
	{
		return (NULL);
	}
	i = 0;
	while (i < length)
	{
		*(copy + i) = *(str + i);
		i++;
	}
	*(copy + length) = '\0';
	return (copy);
}
