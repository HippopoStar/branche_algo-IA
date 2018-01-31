/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:49:14 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/25 20:57:31 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	aux_ft_putnbr_fd(int n, int fd)
{
	if (n != 0)
	{
		aux_ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd('0' + (n % 10), fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
	}
	else if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		aux_ft_putnbr_fd(-n, fd);
	}
	else
	{
		aux_ft_putnbr_fd(n, fd);
	}
}
