/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:37:04 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/20 20:49:23 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	aff(t_champ *champ, int *av, unsigned char ocp, unsigned short pc)
{
	(void)champ;
	(void)ocp;
	(void)pc;
	if (av[0] < 0)
		return ;
	ft_putchar(champ->r[av[0]] % 256);
}
