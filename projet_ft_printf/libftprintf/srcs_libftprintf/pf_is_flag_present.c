/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_is_flag_present.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 14:55:12 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/18 15:09:14 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_putstr("Appel de \"pf_is_flag_present\"\n");
*/

int	pf_is_flag_present(const char *format, char flag_char)
{
	size_t	i;

	i = 0;
	while (!(ft_strchr(PF_FORMAT_SPECIFIERS, (int)*(format + i))
			|| ft_strchr(PF_CONVERSION_SPECIFIERS, (int)*(format + i))
			|| *(format + i) == flag_char
			|| *(format + i) == '\0'))
	{
		if (flag_char == '0' && ft_strchr("123456789", (int)*(format + i)))
		{
			while (ft_strchr("0123456789", (int)*(format + i)))
			{
				i++;
			}
		}
		else
		{
			i++;
		}
	}
	return (*(format + i) == flag_char ? 1 : 0);
}
