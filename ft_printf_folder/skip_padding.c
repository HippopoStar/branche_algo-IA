/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_padding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 05:48:06 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/13 05:48:11 by lcabanes         ###   ########.fr       */
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

ssize_t	skip_padding(char *str)
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
