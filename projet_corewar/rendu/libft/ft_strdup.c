/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 10:54:57 by cmiran            #+#    #+#             */
/*   Updated: 2019/06/11 20:45:03 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;

	if (!(dest = ft_strnew(ft_strlen(s1))))
		return (NULL);
	return (ft_memcpy(dest, s1, ft_strlen(s1)));
}
