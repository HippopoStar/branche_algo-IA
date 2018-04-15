/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_mnoz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 19:52:31 by lcabanes          #+#    #+#             */
/*   Updated: 2018/04/15 15:03:28 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Note a moi-meme :
** En effet, si la precision est expressement de zero,
** le retour de 'point_flag_value' le sera egalement,
** et cela ne sera par consequent pas detecte par la fonction antecedente
*/

ssize_t	pf_point_flag_value(char *str)
{
	size_t	i;
	ssize_t	retour;

	retour = 0;
	if ((retour = pf_find_flag('.', str)) != 0)
	{
		return (retour);
	}
	else
	{
		i = 0;
		while ((pf_occurs(*(str + i), OPTIONNAL_FLAGS)
				|| pf_occurs(*(str + i), "123456789")) && *(str + i) != '.')
		{
			i++;
		}
		return (ft_atoi(str + i + 1) == 0 && *(str + i + 1) == '0' ?
				0 : (ssize_t)pf_field_width_length(str));
	}
}

ssize_t	pf_zero_flag_value(char *str)
{
	size_t	i;
	ssize_t	retour;

	retour = 0;
	if ((retour = pf_find_flag('0', str)) != 0)
	{
		return (retour);
	}
	else
	{
		i = 0;
		while (pf_occurs(*(str + i), OPTIONNAL_FLAGS)
				|| pf_occurs(*(str + i), "123456789"))
		{
			if ((i > 0 && pf_occurs(*(str + i - 1), ".0123456789"))
				|| (i == 0 && *(str + 0) != '0'))
			{
				i++;
			}
			else
			{
				break ;
			}
		}
		return ((ft_atoi(str + i + 1) == 0 && *(str + i + 1) == '0') ?
				0 : (ssize_t)pf_field_width_length(str));
	}
}

ssize_t	pf_detect_mnoz(char *str)
{
	ssize_t	retour;

	if ((retour = pf_find_flag('.', str)) >= 0)
	{
		return (retour);
	}
	else if (!(pf_find_flag('-', str) >= 0))
	{
		return (pf_zero_flag_value(str));
	}
	else
	{
		return (-1);
	}
}
