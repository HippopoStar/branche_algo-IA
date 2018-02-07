/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 18:53:12 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/07 01:31:15 by lcabanes         ###   ########.fr       */
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

ssize_t		go_to_convert_flags(char *str)
{
	ssize_t	i;

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
