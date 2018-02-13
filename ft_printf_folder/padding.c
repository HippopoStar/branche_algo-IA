/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 05:36:17 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/13 07:11:59 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	go_to_conv_flags(char *str)
{
	size_t	i;

	i = 0;
	i = i + skip_padding(str + i);
	i = i + skip_length_modifiers_and_conversion_specifier(str + i);
	i = i - 1;
	return (i);
}

size_t	find_flag(char c, char *str)
{
	size_t	i;
	char	flags[6];
	int		size;

	flags[0] = '#';
	flags[1] = '0';
	flags[2] = '-';
	flags[3] = ' ';
	flags[4] = '+';
	flags[5] = '.';
	i = 0;
	while (i < 6 && *(flags + i) != c)
	{
		i++;
	}
	if (i < 5)
	{
		flags[i] = flags[5];
	}
	flags[5] = '\0';
	i = 0;
	while (occurs(*(str + i), flags) == 1)
	{
		i++;
	}
	if (*(str + i) == c)
	{
		return ((size = (int)((atoi(str + i + 1))) > 0) ? size : 1);
	}
	else
	{
		return (0);
	}
}

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
	while (!(occurs(*(mai->str + i), "123456789")))
		i++;
	if (*(mai->str + i) == '0')
		;
	else if (occurs(c, "oxX"))
	{
		aux_p_sharp_mark(c, i, mai);
	}
}
