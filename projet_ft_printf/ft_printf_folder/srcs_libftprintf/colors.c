/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:22:35 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/11 16:02:42 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_color(char *str)
{
	return ((!(strncmp(str, "{eoc}", 5))
			|| !(strncmp(str, "{black}", 7))
			|| !(strncmp(str, "{red}", 5))
			|| !(strncmp(str, "{green}", 7))
			|| !(strncmp(str, "{yellow}", 8))
			|| !(strncmp(str, "{blue}", 6))
			|| !(strncmp(str, "{magenta}", 9))
			|| !(strncmp(str, "{cyan}", 6))
			|| !(strncmp(str, "{white}", 7))) ?
			1
			: 0);
}

size_t	colors(char *str, t_pf *mai)
{
	size_t	c;

	c = 0;
	if (!(strncmp(str, "{eoc}", 5)) && (c = 5) != 0)
		add_str_mai("\033[00m", 5, mai);
	else if (!(strncmp(str, "{black}", 7)) && (c = 7) != 0)
		add_str_mai("\033[30m", 5, mai);
	else if (!(strncmp(str, "{red}", 5)) && (c = 5) != 0)
		add_str_mai("\033[31m", 5, mai);
	else if (!(strncmp(str, "{green}", 7)) && (c = 7) != 0)
		add_str_mai("\033[32m", 5, mai);
	else if (!(strncmp(str, "{yellow}", 8)) && (c = 8) != 0)
		add_str_mai("\033[33m", 5, mai);
	else if (!(strncmp(str, "{blue}", 6)) && (c = 6) != 0)
		add_str_mai("\033[34m", 5, mai);
	else if (!(strncmp(str, "{magenta}", 9)) && (c = 9) != 0)
		add_str_mai("\033[35m", 5, mai);
	else if (!(strncmp(str, "{cyan}", 6)) && (c = 6) != 0)
		add_str_mai("\033[36m", 5, mai);
	else if (!(strncmp(str, "{white}", 7)) && (c = 7) != 0)
		add_str_mai("\033[37m", 5, mai);
	mai->len = 5;
	return (c);
}
