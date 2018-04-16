/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 00:54:20 by lcabanes          #+#    #+#             */
/*   Updated: 2018/04/17 01:05:32 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char	*p;

	if (!(p = (char *)malloc(sizeof(char))))
		exit(-1);
	ft_putstr("\"ft_printf\" renvoie : ");
	ft_printf("%p\n", p);
	ft_putstr("\"printf\"    renvoie : ");
	printf("%p\n", p);
	free(p);
	return (0);
}
