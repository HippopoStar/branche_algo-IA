/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_width_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 18:59:37 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/14 21:39:59 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	fwl_bis(char *str)
{
	size_t	i;

	i = 0;
	while (occurs(*(str + i), "#- +"))
	{
		if (occurs(*(str + i), "0."))
		{
			while (occurs(*(str + i), "0123456789"))
			{
				i++;
			}
		}
		else
		{
			i++;
		}
	}
	return ((size_t)ft_atoi(str + i));
}

size_t	field_width_length(char *str)
{
	size_t	i;
	size_t	retour;
	size_t	retour_bis;

	i = go_to_conv_flags(str);
	ft_putchar(*(str + i)); //TEST
	ft_putchar('\n');//TEST
	while (i > 0)
	{
		retour = 0;
		while ((retour_bis = (size_t)ft_atoi(str + i - 1)) >= retour)
		{
			retour = retour_bis;
			i--;
		}
		if (*(str + i - 1) != '.' && *(str + i - 1) != '0' && *(str + i) != '0')
		{
			return (retour);
		}
		else
		{
			i--;
		}
	}
	return (0);
}
