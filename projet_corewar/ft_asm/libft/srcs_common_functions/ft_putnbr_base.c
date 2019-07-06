/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 02:46:32 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/08 05:08:10 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	is_base_valid(char *base)
{
	long int	i;
	long int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] < 33 || base[i] == 127 || base[i] == '-' || base[i] == '+')
			return (0);
		j = 1;
		while (base[i + j] != '\0')
		{
			if (base[i + j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	else
		return (i);
}

static void		print_nbr_base(long int long_nbr,\
											char *base, long int length_base)
{
	if (long_nbr == 0)
		;
	else
	{
		print_nbr_base(long_nbr / length_base, base, length_base);
		ft_putchar(base[long_nbr % length_base]);
	}
}

void			ft_putnbr_base(int nbr, char *base)
{
	long int	length_base;
	long int	long_nbr;

	long_nbr = nbr;
	length_base = is_base_valid(base);
	if (length_base == 0)
		;
	else if (long_nbr == 0)
		ft_putchar(base[0]);
	else
	{
		if (long_nbr < 0)
		{
			ft_putchar('-');
			print_nbr_base(-long_nbr, base, length_base);
		}
		else
			print_nbr_base(long_nbr, base, length_base);
	}
}
