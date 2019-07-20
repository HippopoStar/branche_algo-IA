/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:34:24 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/18 22:59:31 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

char	*ft_itoa_base(int n, int base)
{
	int		i;
	char	*nbr;
	int		neg;

	i = 1;
	neg = 0;
	if (n < 0)
	{
		if (base == 10)
			neg = 1;
		n *= -1;
	}
	while (ft_pow(base, i) - 1 < n)
		i++;
	if (!(nbr = ft_memalloc(sizeof(char) * i)))
		return (0);
	nbr[i + neg] = '\0';
	while (i-- > 0)
	{
		nbr[i + neg] = (n % base) + (n % base > 9 ? 'A' - 10 : '0');
		n = n / base;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}
