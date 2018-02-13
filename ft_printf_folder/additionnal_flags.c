/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additionnal_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 06:03:16 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/13 07:32:20 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	detect_mnoz(char *str)
{
	(void)str;

	return (0);
}

void	additionnal_flags(char *str, size_t length, t_pf *mai)
{
	size_t	c_v;
	size_t	retour;

	(void)mai;
	(void)length;

	c_v = go_to_conv_flags(str);
	if (find_flag('#', str) > 0)
	{
		p_sharp_mark(*(str + c_v), mai);
	}
	if (find_flag('-', str) > 0)
	{

	}
	else if (find_flag('0', str) > 0)
	{

	}
	if ((retour = find_flag(' ', str)) > 0)
	{

	}
}
