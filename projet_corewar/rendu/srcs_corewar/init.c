/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:42:26 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/20 23:38:35 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_follow_up(t_champ *node)
{
	node->pc = 0;
	node->cycle_to_wait = 0;
	node->is_dead = 0;
	node->go = 0;
	node->op = 0;
	node->ocp = 0;
	node->src = 0;
	node->av = NULL;
	node->process = NULL;
	node->size = 0;
	node->next = NULL;
}

t_champ	*init_fork(t_champ *champ)
{
	t_champ	*node;

	if (!(node = ft_memalloc(sizeof(t_champ))) ||\
			!(node->r = ft_memalloc(REG_SIZE * REG_NUMBER)))
		kill(1, "Oh dear, something went wrong with malloc()!");
	else
	{
		ft_memcpy(node->r, champ->r, REG_SIZE * REG_NUMBER);
		node->carry = champ->carry;
		node->live = champ->live;
		node->token = champ->token;
		node->id = *g_champ->n;
		if (!(node->name = ft_strdup(champ->name)) ||\
				!(node->comment = ft_strdup(champ->comment)))
			kill(1, "Oh boy, something went wrong with malloc()!");
		node->n = g_champ->n;
		node->start = g_champ->start;
		node->last = g_champ->last;
		init_follow_up(node);
	}
	return (node);
}

void	init_champ_follow_up(t_champ *node)
{
	if (!(node->n = ft_memalloc(sizeof(int))) ||\
			!(node->start = ft_memalloc(sizeof(t_champ *))) ||\
			!(node->last = ft_memalloc(sizeof(t_champ *))))
		kill(1, "Oh lord, soemthing went wrong with malloc()!");
	else
	{
		*node->n = 0;
		*node->start = NULL;
		*node->last = NULL;
	}
}

t_champ	*init_champ(char exist)
{
	t_champ	*node;

	if (!(node = ft_memalloc(sizeof(t_champ))) ||\
			!(node->r = ft_memalloc(REG_SIZE * REG_NUMBER)))
		kill(1, "Oh dear, something went wrong with malloc()!\n");
	else
	{
		node->carry = 0;
		node->live = 0;
		node->token = 0;
		node->id = 0;
		node->name = NULL;
		node->comment = NULL;
		init_follow_up(node);
		if (!exist)
			init_champ_follow_up(node);
	}
	return (node);
}

void	init_env(void)
{
	if (!(g_env.memory = ft_memalloc(MEM_SIZE)))
		kill(1, "Oh god, something went wrong with malloc()!\n");
	g_env.option = 0;
	g_env.force_token = 0;
	g_env.cycle_to_dump = -1;
	g_env.cycle = 0;
	g_env.cycle_to_die = CYCLE_TO_DIE;
	g_env.last_alive = 0;
	g_env.total_live = 0;
	g_env.tab = NULL;
	g_champ = NULL;
}
