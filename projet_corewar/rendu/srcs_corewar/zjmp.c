/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:51:00 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/20 21:10:31 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	verbose(int token, int id, short i, int carry)
{
	if (g_env.option & OPT_C)
		ft_printf("P %s%4i"RESET, g_color[token], id);
	else
		ft_printf("P %4i", id);
	if (carry)
		ft_printf(" | zjmp %hi OK\n", i);
	else
		ft_printf(" | zjmp %hi FAILED\n", i);
}

void		zjmp(t_champ *champ, int *av, unsigned char ocp, unsigned short pc)
{
	short	i;

	(void)av;
	(void)ocp;
	(void)pc;
	i = is_dir_code(&champ->pc, 0x9);
	if (g_env.option & OPT_V)
		verbose(champ->token, champ->id, i, champ->carry);
	if (!champ->carry)
		return ;
	champ->pc = pc + (i % IDX_MOD);
}

/*
**	ft_printf("I'm in zjmp, at new pc : %02x\n",\
**			g_env.memory[INDEX(champ->pc)]);
**	ft_printf("I'm in zjmp, at cycle : %i\n", g_env.cycle);
*/
