/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 05:04:42 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/12 09:15:34 by lcabanes         ###   ########.fr       */
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
	i = 0;
	while (i < nb_of_char)
	{
		fill_uni_line(2, *(mask + i));
		i++;
	}
	i = 0;
	while (i < 4)
	{
		*(*(mask + i) + 0) = '\0';
	}
}

void	fill_uni_mask(size_t nb_of_bits, char mask[4][9])
{
	if (nb_of_bits <= 7)
		aux_fill_mask(1, mask);
	else if (8 <= nb_of_bits && nb_of_bits <= 11)
		aux_fill_mask(2, mask);
	else if (12 <= nb_of_bits && nb_of_bits <= 16)
		aux_fill_mask(3, mask);
	else if (17 <= nb_of_bits && nb_of_bits <= 19)
		aux_fill_mask(4, mask);
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

void	from_unicode_array_to_string(char mask[4][9])
{
	size_t	i;
	size_t	j;
	char	c;
	int		b;

	i = 0;
	while (i < 4 && mask[i][0] != '\0')
	{
		c = '\0';
		b = 1;
		j = 0;
		while (j > 7)
		{
			if (mask[i][7 - j] == '1')
			{
				c = c + b;
			}
			b = b * 2;
			j++;
		}
		mask[0][i] = c;
		i++;
	}
	mask[0][i] = '\0';
}

void	complete_unicode_array(unsigned int nb, size_t nb_of_bits, char mask[4][9])
{
	size_t	i;

	i = 0;
	while (i < nb_of_bits)
	{
		mask[3 - (nb_of_bits / 6)][7 - (nb_of_bits % 6)] = nb % 2;
		nb = nb / 2;
		i++;
	}
	i = 7 - (nb_of_bits % 6);
	while (i > 0)
	{
		if (mask[3 - (nb_of_bits / 6)][i] == 'x')
		{
			mask[3 - (nb_of_bits / 6)][i] = '0';
		}
		i--;
	}
}

void	take_up_unicode_char(wchar_t c, char unicode[5])
{
	char			mask[4][9];
	unsigned int	nb;
	size_t			nb_of_bits;
	size_t			i;

	nb = (unsigned int)c;
	nb_of_bits = count_bits(nb);
	fill_uni_mask(nb, mask);
	complete_unicode_array(nb, nb_of_bits, mask);
	from_unicode_array_to_string(mask);
	i = 0;
	while (i < 4 && *(*(mask + 0) + i) != '\0')
	{
		unicode[i] = mask[0][i];
		i++;
	}
	unicode[i] = '\0';
}

void	add_unicode_mai(va_list ap, t_pf *mai)
{
	char	unicode[5];

	take_up_unicode_char(va_arg(ap, wchar_t), unicode);
	add_str_mai(unicode, -1, mai);
}
