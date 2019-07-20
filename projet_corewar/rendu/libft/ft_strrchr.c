/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:20:41 by cmiran            #+#    #+#             */
/*   Updated: 2017/11/15 00:26:22 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	s_len = ft_strlen(s);
	while (s_len--)
		if (s[s_len] == c)
			return ((char *)s + s_len);
	return (NULL);
}
