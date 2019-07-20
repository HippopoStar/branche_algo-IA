/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 15:49:39 by cmiran            #+#    #+#             */
/*   Updated: 2018/09/06 15:50:34 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_isdigit_base' identifies an ascii digit 'char' based on its base.
*/

int	ft_isdigit_base(int c, int base)
{
	if (ft_isdigit(c) && (c - '0') < base)
		return (1);
	if (ft_islower(c) && (c - 'a' + 10) < base)
		return (1);
	if (ft_isupper(c) && (c - 'A' + 10) < base)
		return (1);
	return (0);
}
