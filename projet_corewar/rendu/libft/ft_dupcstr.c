/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dupcstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 18:57:28 by cmiran            #+#    #+#             */
/*   Updated: 2018/10/22 17:32:44 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dupcstr(const char *s1, char c)
{
	char	*dest;
	size_t	i;
	int		j;

	if (!(dest = ft_strnew(ft_strlen(s1)
			- (i = (ft_strclen(s1, c) + 1)))))
		return (NULL);
	j = 0;
	while (s1[i])
		dest[j++] = s1[i++];
	return (dest);
}
