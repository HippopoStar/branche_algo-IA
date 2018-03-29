/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:43:06 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/28 01:58:03 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	aux_ft_putendl_fd(char const *s, int fd)
{
	size_t	length;

	length = ft_strlen(s);
	write(fd, s, length);
	ft_putchar_fd('\n', fd);
}

void		ft_putendl_fd(char const *s, int fd)
{
	if (s != NULL)
	{
		aux_ft_putendl_fd(s, fd);
	}
}
