/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_conv_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 01:25:07 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/09 04:11:06 by lcabanes         ###   ########.fr       */
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

ssize_t	go_to_conv_flags(char *str)
{
	ssize_t	i;

	i = 0;
	while (*(str + i) != '\0' && !(occurs(*(str + i), "hljzsSpdDioOuUxXcC")))
	{
		if (!(occurs(*(str + i), "#0-+ 123456789.")))
		{
			return (0);
		}
		i++;
	}
	return (i);
}
