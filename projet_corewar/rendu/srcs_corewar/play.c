/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:28:35 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/20 23:28:12 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	manage(int *cycle_to_die, t_champ **tab, int i)
{
	static int	check_count = 0;
	size_t		total_live;

	check_count++;
	total_live = 0;
	while (i--)
	{
		if (!tab[i]->live && !tab[i]->is_dead)
		{
			tab[i]->is_dead = 1;
			ft_memdel((void **)&tab[i]->av);
		}
		else
			total_live += tab[i]->live;
		tab[i]->live = 0;
	}
	if (total_live >= NBR_LIVE || check_count == MAX_CHECKS)
	{
		*cycle_to_die -= CYCLE_DELTA;
		check_count = 0;
	}
	if (!total_live || *cycle_to_die < 0)
		winner(g_env.tab, g_env.last_alive);
}

void	exec(t_champ *champ, unsigned char op)
{
	static void		(*f[17])(t_champ *, int *, unsigned char, unsigned short) =\
	{NULL, live, ld, st, add, sub,\
		and_, or_, xor_, zjmp, ldi, sti, fork_, lld, lldi, lfork, aff};

	if (champ->go != 1 || champ->is_dead == 1 || champ->cycle_to_wait > 0)
		return ;
	f[op](champ, champ->av, champ->ocp, champ->src);
	ft_memdel((void **)&champ->av);
	champ->go = 0;
}

void	read_instruction(t_champ *champ, unsigned short pc, unsigned char op,\
		unsigned char ocp)
{
	static int	need_ocp[17] = {11, 0, 1, 1, 1, 1,\
		1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1};
	static int	cycle_to_wait[17] = {0, 10, 5, 5, 10, 10,\
		6, 6, 6, 20, 25, 25, 800, 10, 50, 1000, 2};
	static int	ac[17] = {33, 1, 2, 2, 3, 3, 3, 3, 3, 1, 3, 3, 1, 2, 3, 1, 1};

	champ->pc++;
	if (!IS_VALID_OP_CODE(op) || champ->is_dead)
		return ;
	else if (need_ocp[op])
		champ->pc++;
	champ->cycle_to_wait = cycle_to_wait[op] - 1;
	if (need_ocp[op] && (!checksum(ocp, op, ac[op]) ||\
				!(champ->av = disassemble(ocp, op, ac[op], &champ->pc))))
		return ;
	else
	{
		champ->go = 1;
		champ->src = pc;
		champ->op = op;
		champ->ocp = need_ocp[op] ? g_env.memory[INDEX(pc + 1)] : 0;
	}
}

void	play(int i, int cycle_to_check)
{
	while ("There can only be one.." && i--)
	{
		if (!cycle_to_check)
		{
			manage(&g_env.cycle_to_die, g_env.tab, *g_champ->n);
			cycle_to_check = g_env.cycle_to_die;
		}
		if (!g_env.tab[i]->cycle_to_wait)
			read_instruction(g_env.tab[i], g_env.tab[i]->pc,\
					g_env.memory[INDEX(g_env.tab[i]->pc)],\
					g_env.memory[INDEX(g_env.tab[i]->pc + 1)]);
		else
			g_env.tab[i]->cycle_to_wait--;
		exec(g_env.tab[i], g_env.tab[i]->op);
		if (!i)
		{
			if (g_env.option | OPT_DUMP && g_env.cycle == g_env.cycle_to_dump)
				dump();
			i = *g_champ->n;
			cycle_to_check--;
			g_env.cycle++;
		}
	}
}

/*
**	if (!i)
**	{
**		cycle_to_check--;
**		g_env.cycle++;
**		i = *g_champ->n;
**		if (!cycle_to_check)
**		{
**			manage(&g_env.cycle_to_die, g_env.tab, *g_champ->n);
**			cycle_to_check = g_env.cycle_to_die;
**		}
**		ft_printf("it is now cycle %i\n", g_env.cycle);
**	}
*/
