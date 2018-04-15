/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:22:35 by lcabanes          #+#    #+#             */
/*   Updated: 2018/04/15 14:25:25 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_is_color(char *str)
{
	return ((!(ft_strncmp(str, "{eoc}", 5))
			|| !(ft_strncmp(str, "{black}", 7))
			|| !(ft_strncmp(str, "{red}", 5))
			|| !(ft_strncmp(str, "{green}", 7))
			|| !(ft_strncmp(str, "{yellow}", 8))
			|| !(ft_strncmp(str, "{blue}", 6))
			|| !(ft_strncmp(str, "{magenta}", 9))
			|| !(ft_strncmp(str, "{cyan}", 6))
			|| !(ft_strncmp(str, "{white}", 7))) ?
			1
			: 0);
}

size_t	pf_colors(char *str, t_pf *mai)
{
	size_t	c;

	c = 0;
	if (!(ft_strncmp(str, "{eoc}", 5)) && (c = 5) != 0)
		pf_add_str_mai("\033[00m", 5, mai);
	else if (!(ft_strncmp(str, "{black}", 7)) && (c = 7) != 0)
		pf_add_str_mai("\033[30m", 5, mai);
	else if (!(ft_strncmp(str, "{red}", 5)) && (c = 5) != 0)
		pf_add_str_mai("\033[31m", 5, mai);
	else if (!(ft_strncmp(str, "{green}", 7)) && (c = 7) != 0)
		pf_add_str_mai("\033[32m", 5, mai);
	else if (!(ft_strncmp(str, "{yellow}", 8)) && (c = 8) != 0)
		pf_add_str_mai("\033[33m", 5, mai);
	else if (!(ft_strncmp(str, "{blue}", 6)) && (c = 6) != 0)
		pf_add_str_mai("\033[34m", 5, mai);
	else if (!(ft_strncmp(str, "{magenta}", 9)) && (c = 9) != 0)
		pf_add_str_mai("\033[35m", 5, mai);
	else if (!(ft_strncmp(str, "{cyan}", 6)) && (c = 6) != 0)
		pf_add_str_mai("\033[36m", 5, mai);
	else if (!(ft_strncmp(str, "{white}", 7)) && (c = 7) != 0)
		pf_add_str_mai("\033[37m", 5, mai);
	mai->len = 5;
	return (c);
}
