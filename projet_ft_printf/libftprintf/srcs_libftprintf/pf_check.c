/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 09:20:30 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/25 03:51:16 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_putstr("Appel de \"pf_check_convers\"\n");
*/

size_t	pf_check_convers(const char *format)
{
	size_t	step;

	if (!(*(format + 0) == '%'))
	{
		return (0);
	}
	else
	{
		step = 1;
		while (!ft_strchr(PF_CONVERSION_SPECIFIERS, (int)*(format + step))
				&& *(format + step) != '\0')
		{
			step++;
		}
		return (*(format + step) == '\0' ? step : step + 1);
	}
}

/*
**	ft_putstr("Appel de \"pf_check_color\"\n");
*/

size_t	pf_check_color(const char *format)
{
	if (!ft_strncmp(format, "{eoc}", 5))
		return (5);
	else if (!ft_strncmp(format, "{black}", 7))
		return (7);
	else if (!ft_strncmp(format, "{red}", 5))
		return (5);
	else if (!ft_strncmp(format, "{green}", 7))
		return (7);
	else if (!ft_strncmp(format, "{yellow}", 8))
		return (8);
	else if (!ft_strncmp(format, "{blue}", 6))
		return (6);
	else if (!ft_strncmp(format, "{magenta}", 9))
		return (9);
	else if (!ft_strncmp(format, "{cyan}", 6))
		return (6);
	else if (!ft_strncmp(format, "{white}", 7))
		return (7);
	else
		return (0);
}
