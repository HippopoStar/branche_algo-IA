/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_width_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 18:59:37 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/14 18:59:40 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	field_width_length(char *str)
{
	size_t	i;
	size_t	retour;
	size_t	retour_bis;

	i = go_to_conv_flags(str);
	retour = 0;
	while (i > 0 && (retour_bis = ft_atoi(str + i - 1)) >= retour)
	{
		retour = retour_bis;
		i--;
	}
	return (retour);
}
