/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:39:40 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/28 01:53:44 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	aux_ft_putstr_fd(char const *s, int fd)
{
	size_t	length;

	length = ft_strlen(s);
	write(fd, s, length);
}

void		ft_putstr_fd(char const *s, int fd)
{
	if (s != NULL)
	{
		aux_ft_putstr_fd(s, fd);
	}
}
