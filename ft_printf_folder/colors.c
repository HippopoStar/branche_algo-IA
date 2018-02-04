/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:22:35 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/04 05:18:02 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	colors(char *str, t_pf *mai)
{
	size_t	c;

	c = 0;
	if (!(strncmp(str, "{eoc}", 5)) && (c = 5) != 0)
		add_str_mai("\033[00m", mai);
	else if (!(strncmp(str, "{black}", 7)) && (c = 7) != 0)
		add_str_mai("\033[30m", mai);
	else if (!(strncmp(str, "{red}", 5)) && (c = 5) != 0)
		add_str_mai("\033[31m", mai);
	else if (!(strncmp(str, "{green}", 7)) && (c = 7) != 0)
		add_str_mai("\033[32m", mai);
	else if (!(strncmp(str, "{yellow}", 8)) && (c = 8) != 0)
		add_str_mai("\033[33m", mai);
	else if (!(strncmp(str, "{blue}", 6)) && (c = 6) != 0)
		add_str_mai("\033[34m", mai);
	else if (!(strncmp(str, "{magenta}", 9)) && (c = 9) != 0)
		add_str_mai("\033[35m", mai);
	else if (!(strncmp(str, "{cyan}", 6)) && (c = 6) != 0)
		add_str_mai("\033[36m", mai);
	else if (!(strncmp(str, "{white}", 7)) && (c = 7) != 0)
		add_str_mai("\033[37m", mai);
	mai->len = 5;
	return (c);
}
