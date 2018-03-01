/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:15:23 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/28 01:27:05 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*aux_ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	length;
	char	*mapi;

	length = ft_strlen(s);
	if (!(mapi = (char *)malloc((length + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < length)
	{
		*(mapi + i) = f((unsigned int)i, *(s + i));
		i++;
	}
	*(mapi + length) = '\0';
	return (mapi);
}

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	return ((s != NULL) ? aux_ft_strmapi(s, f) : NULL);
}
