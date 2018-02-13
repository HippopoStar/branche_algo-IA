/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 05:04:42 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/13 02:20:54 by lcabanes         ###   ########.fr       */
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
		i++;
	}
	*(uni_line + 8) = '\0';
}

void	aux_fill_mask(size_t nb_of_char, char mask[4][9])
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
	i = 1;
	while (i < nb_of_char)
	{
		fill_uni_line(2, *(mask + i));
		i++;
	}
	while (i < 4)
	{
		*(*(mask + i) + 0) = '\0';
		i++;
	}
	print_uni_mask(mask); //TEST
}

void	fill_uni_mask(size_t nb_of_bits, char mask[4][9], size_t *nb_of_char)
{
	if (nb_of_bits <= 7)
	{
		*nb_of_char = 1;
		aux_fill_mask(1, mask);
	}
	else if (8 <= nb_of_bits && nb_of_bits <= 11)
	{
		*nb_of_char = 2;
		aux_fill_mask(2, mask);
	}
	else if (12 <= nb_of_bits && nb_of_bits <= 16)
	{
		*nb_of_char = 3;
		aux_fill_mask(3, mask);
	}
	else if (17 <= nb_of_bits && nb_of_bits <= 19)
	{
		*nb_of_char = 4;
		aux_fill_mask(4, mask);
	}
	else
		error_code("Erreur dans \"ft_printf\"");
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

void	complete_uni_array(unsigned int nb, size_t nb_of_bits, size_t nb_of_char, char mask[4][9])
{
	size_t	i;

	i = 0;
	while (i < nb_of_bits && (i / 6) < nb_of_char)
	{
		mask[(nb_of_char - 1) - (i / 6)][7 - (i % 6)] = '0' + (nb % 2);
		nb = nb / 2;
		i++;
	}
	if (nb_of_char == 1 && i == 6)
		mask[0][1] = '0' + (nb % 2);
	i = 0;
	while (i < 7)
	{
		if (mask[0][i] == 'x')
		{
			mask[0][i] = '0';
		}
		i++;
	}
	print_uni_mask(mask); //TEST
}
