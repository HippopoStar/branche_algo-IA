/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:36:01 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/19 23:35:22 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_champ	**sort_list(int token)
{
	t_champ **tab;

	if (!(tab = ft_realloc(g_env.tab, sizeof(t_champ *) * token)))
		kill(1, "Oh lord, something went wrong with realloc()!");
	else
		tab[token - 1] = g_champ;
	return (tab);
}

void	add_process_to_memory(int gap, int token)
{
	void	*start;

	start = g_env.memory;
	while (g_champ->token != token)
	{
		if (g_champ->token > *g_champ->n)
			kill(0, "Misuse of -n, the following value must be between "\
					"0 and the number of champions declared.");
		else if (!g_champ->next)
		{
			g_champ = *g_champ->start;
			add_process_to_memory(gap, (token + 1));
			break ;
		}
		g_champ = g_champ->next;
	}
	g_env.memory += (gap * token - gap);
	g_champ->pc = (gap * token - gap);
	ft_memcpy(g_env.memory, g_champ->process, g_champ->size);
	g_env.tab = sort_list(token);
	g_champ = *g_champ->start;
	g_env.memory = start;
	if (token < *g_champ->n)
		add_process_to_memory(gap, ++token);
}

void	init_process(int fd)
{
	char	c;

	if (!(g_champ->process = ft_memalloc(g_champ->size)))
		kill(1, "Oh dear, something went wrong with malloc()!");
	else if (read(fd, g_champ->process, g_champ->size) < g_champ->size)
		kill(1, "Oh dear, something went wrong with read()!");
	else if (read(fd, &c, 1) > 0)
		kill(0, "Mamamia, one of the champ' eat between meals !");
}
