/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:38:29 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/08 05:37:27 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Affiche n caracteres c sur la sortie standard.
*/

#include "ft_printf.h"

void	pf_putnchar(char c, ssize_t n, size_t *r)
{
	if (n <= 0)
		return ;
	*r += n;
	while (n--)
		write(1, &c, 1);
}
