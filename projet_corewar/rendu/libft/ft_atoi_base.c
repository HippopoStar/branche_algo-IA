/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 15:07:39 by cmiran            #+#    #+#             */
/*   Updated: 2018/10/22 17:34:04 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	value_of(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	else if (ft_islower(c))
		return (c - 'a' + 10);
	else if (ft_isupper(c))
		return (c - 'A' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, int base)
{
	long	nb;
	int		sign;

	if (!str || base < 2 || base > 36)
		return (0);
	nb = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit_base(*str, base))
	{
		nb = nb * base + value_of(*str);
		str++;
	}
	return ((int)nb * sign);
}
