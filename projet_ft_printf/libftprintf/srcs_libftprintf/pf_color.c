/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 10:23:22 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/18 10:31:50 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pf_color(const char *format, t_list *mai)
{
	return ((!ft_strncmp(format, "{eoc}", 5)
					&& !(mai->content = (void *)ft_strdup(END_OF_COLOR)))
		|| (!ft_strncmp(format, "{black}", 5)
			&& !(mai->content = (void *)ft_strdup(BLACK)))
		|| (!ft_strncmp(format, "{red}", 5)
			&& !(mai->content = (void *)ft_strdup(RED)))
		|| (!ft_strncmp(format, "{green}", 5)
			&& !(mai->content = (void *)ft_strdup(GREEN)))
		|| (!ft_strncmp(format, "{yellow}", 5)
			&& !(mai->content = (void *)ft_strdup(YELLOW)))
		|| (!ft_strncmp(format, "{blue}", 5)
			&& !(mai->content = (void *)ft_strdup(BLUE)))
		|| (!ft_strncmp(format, "{magenta}", 5)
			&& !(mai->content = (void *)ft_strdup(MAGENTA)))
		|| (!ft_strncmp(format, "{cyan}", 5)
			&& !(mai->content = (void *)ft_strdup(CYAN)))
		|| (!ft_strncmp(format, "{white}", 5)
			&& !(mai->content = (void *)ft_strdup(WHITE))) ?
		-1 : 0);
}
