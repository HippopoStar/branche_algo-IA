/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncasecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 19:17:44 by cmiran            #+#    #+#             */
/*   Updated: 2017/12/04 19:20:42 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	ss1;
	unsigned char	ss2;

	ss1 = 1;
	ss2 = 1;
	while (ss1 == ss2 && ss1 && n--)
	{
		ss1 = ft_tolower(*s1++);
		ss2 = ft_tolower(*s2++);
	}
	return (ss1 - ss2);
}
