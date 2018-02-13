/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 05:36:17 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/13 07:44:33 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	aux_p_sharp_mark(char c, size_t i, t_pf *mai)
{
	size_t	j;
	char	*tmp;

	tmp = mai->str;
	j = 2;
	if (c == 'o')
		j = 1;
	if (!(mai->str = (char *)malloc((ft_strlen(tmp) + 1) + j)))
		error_code("Erreur dans \"ft_printf\"");
	strncpy(mai->str, tmp, i);
	*(mai->str + i) = '0';
	if (c != 'o')
		*(mai->str + i + 1) = c;
	strcpy((mai->str + i + j), (tmp + i));
	free(tmp);
}

void	p_sharp_mark(char c, t_pf *mai)
{
	size_t	i;

	i = 0;
	while (!(occurs(*(mai->str + i), "0123456789")))
		i++;
	if (*(mai->str + i) != '0' && occurs(c, "oxX"))
	{
		aux_p_sharp_mark(c, i, mai);
	}
}
