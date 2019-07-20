/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 20:29:57 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/20 23:37:04 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	verbose(int token, int id, int *av)
{
	if (g_env.option & OPT_C)
		ft_printf("P %s%4i"RESET, g_color[token], id);
	else
		ft_printf("P %4i"RESET, id);
	ft_printf(" | add r%i r%i r%i\n", (av[0] + 1), (av[1] + 1), (av[2] + 1));
}

void		add(t_champ *champ, int *av, unsigned char ocp, unsigned short pc)
{
	(void)ocp;
	(void)pc;
	if (av[2] < 0)
		return ;
	champ->r[av[2]] = ((av[0] > -1 ? champ->r[av[0]] : 0)\
			+ (av[1] > -1 ? champ->r[av[1]] : 0));
	champ->carry = champ->r[av[2]] == 0 ? 1 : 0;
	if (g_env.option & OPT_V)
		verbose(champ->token, champ->id, av);
}
