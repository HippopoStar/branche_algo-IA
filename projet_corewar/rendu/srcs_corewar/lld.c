/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 23:14:46 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/20 22:18:47 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	verbose(t_champ *champ, int *av, unsigned char ocp,\
		unsigned short pc)
{
	if (g_env.option & OPT_C)
		ft_printf("P %s%4i"RESET, g_color[champ->token], champ->id);
	else
		ft_printf("P %4i", champ->id);
	if (ocp & 0x40)
		ft_printf(" | lld %i r%i\n", read_2byte(pc + av[0]), (av[1] + 1));
	else
		ft_printf(" | lld %i r%i\n", av[0], (av[1] + 1));
}

void		lld(t_champ *champ, int *av, unsigned char ocp, unsigned short pc)
{
	if (av[1] < 0)
		return ;
	if (ocp & 0x40)
		champ->r[av[1]] = read_4byte(pc + av[0]);
	else
		champ->r[av[1]] = av[0];
	champ->carry = champ->r[av[1]] == 0 ? 1 : 0;
	if (g_env.option & OPT_V)
		verbose(champ, av, ocp, pc);
}
