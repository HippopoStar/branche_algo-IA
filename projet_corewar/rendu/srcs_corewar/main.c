/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:50:08 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/20 23:10:03 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			main(int ac, char **av)
{
	int		i;

	init_env();
	i = 0;
	if (ac == 1)
		kill(0, 0);
	while (ac > 1 && i++ < ac - 1)
		check_input(av[i], (i <= ac &&\
					i == ac ? 0 : ft_str_is_numeric(av[i + 1])));
	if (g_champ && *g_champ->n >= 1 && *g_champ->n <= MAX_PLAYERS)
		g_champ = *g_champ->start;
	else
		kill(0, "You are a pacifist or a warmonger. "\
				"Either way it doesn't work.");
	add_process_to_memory(MEM_SIZE / *g_champ->n, 1);
	introduce(g_env.tab);
	play(*g_champ->n, g_env.cycle_to_die);
	free_all();
	return (0);
}
