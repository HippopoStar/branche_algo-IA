/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_mnoz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 19:52:31 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/19 18:15:56 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	point_flag_value(char *str)
{
	size_t	i;
	size_t	retour;

	retour = 0;
	if ((retour = find_flag('.', str)) != 1)
	{
		return (retour);
	}
	else
	{
		i = 0;
		while ((occurs(*(str + i), OPTIONNAL_FLAGS)
				|| occurs(*(str + i), "123456789")) && *(str + i) != '.')
		{
			i++;
		}
		retour = (size_t)ft_atoi(str + i);
		return ((retour == 1 || (retour == 0 && *(str + i) == '0')) ?
				retour : field_width_length(str));
	}
}

size_t	zero_flag_value(char *str)
{
	size_t	i;
	size_t	retour;

	retour = 0;
	if ((retour = find_flag('0', str)) != 1)
	{
		return (retour);
	}
	else
	{
		i = 0;
		while (occurs(*(str + i), OPTIONNAL_FLAGS)
				|| occurs(*(str + i), "123456789"))
		{
			if ((i > 0 && occurs(*(str + i - 1), ".0123456789"))
				|| (i == 0 && *(str + 0) != '0'))
			{
				i++;
			}
			else
			{
				break;
			}
		}
		return ((ft_atoi(str + i) == 1) ? 1 : field_width_length(str));
	}
}

ssize_t	detect_mnoz(char *str)
{
	ssize_t	retour;

	if ((retour = (ssize_t)find_flag('.', str)) > 0)
	{
		return (retour);
	}
	else if (!(find_flag('-', str)))
	{
		return ((ssize_t)zero_flag_value(str));
	}
	else
	{
		return (0);
	}
}
