/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debat_memoire_02.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 21:07:13 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/03 21:15:38 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(void)
{
	unsigned long long int	n;

	n = 0;
	n = n + ('a' << 24);
	n = n + ('b' << 16);
	n = n + ('c' << 8);
	n = n + 'd';
	ft_putchar((char)n);
	ft_putchar('\n');
	ft_putchar(*(((char *)(&n)) + 0));
	ft_putchar('\n');
	return (0);
}
