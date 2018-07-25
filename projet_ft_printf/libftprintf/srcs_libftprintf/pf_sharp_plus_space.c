/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_sharp_plus_space.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 00:39:59 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/25 07:57:32 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_putstr("Appel de \"pf_apply_plus_sign\"\n");
*/

void	pf_apply_plus_sign(char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i + 1) == ' ' && *(str + i + 1) != '\0')
	{
		i++;
	}
	if (!(*(str + i) == '-'))
	{
		*(str + i) = '+';
	}
}

/*
**	ft_putstr("Appel de \"pf_anticipate_space\"\n");
*/

void	pf_anticipate_plus_space(long long int n, size_t prec, size_t *spac)
{
	size_t	nb_of_char;

	if (!(n < 0))
	{
		nb_of_char = (n > 0) ? 0 : 1;
		while (n > 0)
		{
			n = n / 10;
			nb_of_char++;
		}
		if (nb_of_char < prec)
		{
			nb_of_char = prec;
		}
		if (!(*spac > nb_of_char))
		{
			*spac = nb_of_char + 1;
		}
	}
}

/*
**	ft_putstr("Appel de \"pf_apply_sharp_mark\"\n");
*/

void	pf_apply_sharp_mark(char *nbr_base, char conv_spec)
{
	size_t	i;

	if (conv_spec == 'x' || conv_spec == 'X'
		|| conv_spec == 'b' || conv_spec == 'B'
		|| conv_spec == 'p')
	{
		i = 0;
		while (*(nbr_base + i) != '0'
			&& *(nbr_base + i + 1) != '\0')
		{
			i++;
		}
		*(nbr_base + i + 1) = (!(conv_spec == 'p')) ? conv_spec : 'x';
	}
}

/*
**	ft_putstr("Appel de \"pf_anticipate_sharp_mark\"\n");
*/

void	pf_anticipate_sharp_mark(unsigned long long int n, char conv_spec,\
																size_t *prec)
{
	size_t					nb_of_char;
	unsigned long long int	base_length;

	base_length = 0;
	if (((conv_spec == 'b' || conv_spec == 'B') && (base_length = 2))
		|| ((conv_spec == 'o' || conv_spec == 'O') && (base_length = 8))
		|| ((conv_spec == 'x' || conv_spec == 'X' || conv_spec == 'p')
			&& (base_length = 16)))
	{
		nb_of_char = 0;
		while (n > 0)
		{
			n = n / base_length;
			nb_of_char++;
		}
		if (base_length == 8 && !(*prec > nb_of_char))
			*prec = nb_of_char + 1;
		else if ((base_length == 16 || base_length == 2)
			&& !(*prec > nb_of_char + 2))
			*prec = (nb_of_char > 0) ? nb_of_char + 2 : 3;
	}
}
