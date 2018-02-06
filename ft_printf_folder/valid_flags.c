/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 18:53:12 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/06 19:15:35 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		occurs(char c, char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i) != '\0' && *(str + i) != c)
	{
		i++;
	}
	return (*(str + i) != '\0' ? 1 : 0);
}

size_t	valid_flags(char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i) != '\0' && !(occurs(*(str + i), "sSpdDioOuUxXcC")))
	{
		if (!(occurs(*(str + i), "#0-+ 123456789.hljz")))
		{
			return (0);
		}
		i++;
	}
	return (i);
}
