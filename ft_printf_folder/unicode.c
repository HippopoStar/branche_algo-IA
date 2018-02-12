/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 05:04:42 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/12 06:15:28 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_uni_line(size_t position, char uni_line[9])
{
	size_t	i;

	i = 0;
	while (i < 8)
	{
		if (i < position - 1)
			*(uni_line + i) = '1';
		else if (i == position - 1)
			*(uni_line + i) = '0';
		else
			*(uni_line + i) = 'x';
	}
	*(uni_line + 8) = '\0';
}

void	aux_fill_mask(size_t nb_of_char, char mask[5][9])
{
	size_t	i;

	if (nb_of_char == 1)
		fill_uni_line(1, *(mask + 0));
	else if (nb_of_char == 2)
		fill_uni_line(3, *(mask + 0));
	else if (nb_of_char == 3)
		fill_uni_line(4, *(mask + 0));
	else
		fill_uni_line(5, *(mask + 0));
	i = 0;
	while (i < nb_of_char)
	{
		fill_uni_line(2, *(mask + i));
		i++;
	}
	*(mask + nb_of_char) = NULL;
}

char	**generate_mask(size_t nb_of_bits)
{
	char	**mask;

	if (nb_of_bits <= 7)
		mask = aux_generate_mask(1);
	else if (8 <= nb_of_bits && nb_of_bits <= 11)
		mask = aux_generate_mask(2);
	else if (12 <= nb_of_bits && nb_of_bits <= 16)
		mask = aux_generate_mask(3);
	else if (17 <= nb_of_bits && nb_of_bits <= 19)
		mask = aux_generate_mask(4);
	else
		error_code("Erreur dans \"ft_printf\"");
	return (mask);
}

size_t	count_bits(unsigned int nb)
{
	unsigned int	tmp;
	size_t			i;

	if (nb == 0)
	{
		i = 1;
	}
	else
	{
		i = 0;
		tmp = nb;
		while (tmp != 0)
		{
			tmp = tmp / 2;
			i++;
		}
	}
	return (i);
}

char *unicode_char(wchar_t c)
{
	char			mask[5][9]
	unsigned int	nb;

	nb = (unsigned int)c;

