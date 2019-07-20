/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:40:07 by cmiran            #+#    #+#             */
/*   Updated: 2019/06/11 21:02:57 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(const char *s1, char c)
{
	char	*dest;

	if (!(dest = ft_strnew(ft_strclen(s1, c))))
		return (NULL);
	return (ft_memcpy(dest, s1, ft_strclen(s1, c)));
}
