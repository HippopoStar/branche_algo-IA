/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:08:39 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/20 21:51:39 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	verbose(int token, int id, short i, unsigned short pc)
{
	if (g_env.option & OPT_C)
		ft_printf("P %s%4i"RESET, g_color[token], id);
	else
		ft_printf("P %4i", id);
	ft_printf(" | fork %hi (%hu)\n", i, INDEX(pc + (i % IDX_MOD)));
}

void		fork_(t_champ *champ, int *av, unsigned char ocp, unsigned short pc)
{
	short i;

	(void)av;
	(void)ocp;
	g_champ = *g_champ->last;
	(*g_champ->n)++;
	g_champ->next = init_fork(champ);
	g_champ = g_champ->next;
	*g_champ->last = g_champ;
	i = is_dir_code(&champ->pc, 0xc);
	g_champ->pc = pc + (i % IDX_MOD);
	if (!(g_env.tab =\
				ft_realloc(g_env.tab, sizeof(t_champ *) * (*g_champ->n))))
		kill(1, "Oh lord, something went wrong with realloc()!");
	g_env.tab[*g_champ->n - 1] = g_champ;
	g_champ = *g_champ->start;
	if (g_env.option & OPT_V)
		verbose(champ->token, champ->id, i, pc);
}

/*
**	t_champ	**tmp;
**	tmp = g_env.tab;
**	if (!(g_env.tab = ft_memalloc(sizeof(t_champ *) * (*g_champ->n))))
**		kill();
**	*g_env.tab = g_champ;
**	ft_memcpy((g_env.tab + 1), tmp,\
**			sizeof(t_champ *) * (*g_champ->n - 1));
**	ft_memdel(tmp);
*/
