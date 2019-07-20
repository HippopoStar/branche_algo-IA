/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 19:01:09 by cmiran            #+#    #+#             */
/*   Updated: 2017/12/04 19:05:06 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dest;

	if (!(dest = (char *)malloc(sizeof(*dest) * n + 1)))
		return (NULL);
	return (ft_memcpy(dest, s1, n));
}
