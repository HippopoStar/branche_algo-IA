/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 21:11:39 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/20 20:47:47 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	verbose(t_champ *champ, int *av, unsigned char ocp,\
		unsigned short pc)
{
	if (g_env.option & OPT_C)
		ft_printf("P %s%4i"RESET" | or ", g_color[champ->token], champ->id);
	else
		ft_printf("P %4i | or ", champ->id);
	if (isolate_2bit(ocp, 0) == IND_CODE)
		ft_printf("%i ", read_4byte(pc + (av[0] % IDX_MOD)));
	else if (ocp & 0x80)
		ft_printf("%i ", av[0]);
	else
		ft_printf("%i ", (av[0] > -1 ? champ->r[av[0]] : 0));
	if (isolate_2bit(ocp, 1) == IND_CODE)
		ft_printf("%i ", read_4byte(pc + (av[1] % IDX_MOD)));
	else if (ocp & 0x20)
		ft_printf("%i ", av[1]);
	else
		ft_printf("%i ", (av[1] > -1 ? champ->r[av[1]] : 0));
	ft_printf("r%i\n", (av[2] + 1));
}

void		or_(t_champ *champ, int *av, unsigned char ocp, unsigned short pc)
{
	if (av[2] < 0)
		return ;
	else if (g_env.option & OPT_V)
		verbose(champ, av, ocp, pc);
	if (isolate_2bit(ocp, 0) == IND_CODE)
		champ->r[av[2]] = read_4byte(pc + (av[0] % IDX_MOD));
	else if (ocp & 0x80)
		champ->r[av[2]] = av[0];
	else if (av[0] > -1)
		champ->r[av[2]] = champ->r[av[0]];
	if (isolate_2bit(ocp, 1) == IND_CODE)
		champ->r[av[2]] |= read_4byte(pc + (av[1] % IDX_MOD));
	else if (ocp & 0x20)
		champ->r[av[2]] |= av[1];
	else if (av[1] > -1)
		champ->r[av[2]] |= champ->r[av[1]];
	champ->carry = champ->r[av[2]] == 0 ? 1 : 0;
}
