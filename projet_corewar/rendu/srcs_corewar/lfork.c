/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:32:50 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/20 21:10:35 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	verbose(int token, int id, short i, unsigned short pc)
{
	if (g_env.option & OPT_C)
		ft_printf("P %s%4i"RESET, g_color[token], id);
	else
		ft_printf("P %4i", id);
	ft_printf(" | lfork %hi (%hu)\n", i, INDEX(pc + i));
}

void		lfork(t_champ *champ, int *av, unsigned char ocp, unsigned short pc)
{
	unsigned short i;

	(void)av;
	(void)ocp;
	g_champ = *g_champ->last;
	(*g_champ->n)++;
	g_champ->next = init_fork(champ);
	g_champ = g_champ->next;
	*g_champ->last = g_champ;
	i = is_dir_code(&champ->pc, 0xf);
	g_champ->pc = pc + i;
	if (!(g_env.tab =\
				ft_realloc(g_env.tab, sizeof(t_champ *) * (*g_champ->n))))
		kill(1, "Oh god, soemthing went wrong with realloc()!");
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
