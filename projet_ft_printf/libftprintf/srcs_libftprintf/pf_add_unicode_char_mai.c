/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_unicode_char_mai.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 01:30:15 by lcabanes          #+#    #+#             */
/*   Updated: 2018/04/15 14:20:47 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_from_unicode_array_to_string(char mask[4][9])
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
		while (j < 8)
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

void	pf_print_uni_mask(char mask[4][9])
{
	size_t	i;

	i = 0;
	while (i < 4 && *(*(mask + i) + 0) != '\0')
	{
		ft_putstr(*(mask + i));
		if (*(*(mask + i + 1) + 0) != '\0')
		{
			ft_putchar(' ');
		}
		i++;
	}
	ft_putchar('\n');
}

void	pf_take_up_unicode_char(wint_t c, char unicode[5])
{
	char			mask[4][9];
	unsigned int	nb;
	size_t			nb_of_bits;
	size_t			nb_of_char;
	size_t			i;

	nb = (unsigned int)c;
	nb_of_bits = pf_count_bits(nb);
	pf_fill_uni_mask(nb_of_bits, mask, &nb_of_char);
	pf_cua(nb, nb_of_bits, nb_of_char, mask);
	pf_from_unicode_array_to_string(mask);
	i = 0;
	while (i < 4 && *(*(mask + 0) + i) != '\0')
	{
		unicode[i] = mask[0][i];
		i++;
	}
	unicode[i] = '\0';
}

void	pf_add_unicode_char_mai(va_list ap, t_pf *mai)
{
	char	unicode[5];

	pf_take_up_unicode_char(va_arg(ap, wint_t), unicode);
	pf_add_str_mai(unicode, -1, mai);
	mai->len = 1;
}
