/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_set_bits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 11:15:03 by cmiran            #+#    #+#             */
/*   Updated: 2019/06/26 00:29:12 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_set_bits(size_t nbr)
{
	size_t	count;

	count = 0;
	while (nbr)
	{
		nbr &= (nbr - 1);
		count++;
	}
	return (count);
}
