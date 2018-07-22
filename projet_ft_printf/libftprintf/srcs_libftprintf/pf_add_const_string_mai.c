/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_add_const_string_mai.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 19:58:50 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/22 20:17:50 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pf_add_const_string_mai(const char *str, t_list *mai)
{
	size_t	length;
	size_t	i;

	length = ft_strlen(str);
	if (!(mai->content = (void *)malloc((length + 1) * sizeof(char))))
		return (-1);
	i = 0;
	while (i < length)
	{
		*((char *)((mai->content) + i)) = *(str + i);
		i++;
	}
	*((char *)((mai->content) + length)) = '\0';
	return (0);
}
