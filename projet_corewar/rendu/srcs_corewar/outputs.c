/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 01:34:09 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/20 21:54:49 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	usage_follow_up(void)
{
	ft_printf(BOLD"\t-c"RESET", "BOLD"--g_colors\n"RESET);
	ft_printf("\t\tAttribute a color for each champion declared.\n\n");
	ft_printf(BOLD"\t-h"RESET", "BOLD"--help\n"RESET);
	ft_printf("\t\tTrigger this output.\n");
}

void	usage(void)
{
	ft_printf(BOLD"NAME\n\tcorewar"RESET" -- kind like a coliseum\n\n");
	ft_printf(BOLD"SYNOPSIS\n"RESET);
	ft_printf("\t./"BOLD"corewar"RESET" ["BOLD"-n "RESET\
			UNDERLINE"num"RESET" "UNDERLINE"champion"RESET"]"\
			" ["BOLD"-dump"RESET" "UNDERLINE"num"RESET"]"\
			" ["BOLD"-v"RESET"] ["BOLD"-c"RESET"] ["BOLD"-h"RESET"]\n\n");
	ft_printf(BOLD"DESCRIPTION\n"RESET);
	ft_printf("\tYou must put between "UNDERLINE"1"RESET" and "\
			UNDERLINE"MAX PLAYERS"RESET" champions. They will battle\n\ttill"\
			" death, the last one alive win.\n");
	ft_printf("\tIf a system call fail, and friendly fuck off and errno will"\
			" be\n\toutput.\n\n");
	ft_printf("\tThe following options are available:\n\n");
	ft_printf(BOLD"\t-n "RESET UNDERLINE"num"RESET" "\
			UNDERLINE"champion\n"RESET);
	ft_printf("\t\tAlter the champions's position in memory, as well as his\n");
	ft_printf("\t\texecution order, "UNDERLINE"num"RESET" must be a value "\
			"between 1 and\n\t\tthe number of champions declared.\n\n");
	ft_printf(BOLD"\t-dump "RESET UNDERLINE"num\n"RESET);
	ft_printf("\t\tOutput the state of the arena at num cycle(s), "\
			UNDERLINE"num"RESET" must be\n\t\tpositive.\n\n");
	ft_printf(BOLD"\t-v"RESET", "BOLD"--verbose\n"RESET);
	ft_printf("\t\tOutput a log of each instructions executed.\n\n");
	usage_follow_up();
}

void	introduce(t_champ **tab)
{
	int	i;

	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < *g_champ->n)
	{
		if (g_env.option & OPT_C)
			ft_printf("* Player %s%i"RESET\
					", weighing %i bytes, \"%s%s"RESET"\" (\"%s\") !\n",\
					g_color[tab[i]->token], tab[i]->token, tab[i]->size,\
					g_color[tab[i]->token], tab[i]->name, tab[i]->comment);
		else
			ft_printf("* Player %i"\
					", weighing %i bytes, \"%s\" (\"%s\") !\n",\
					tab[i]->token, tab[i]->size, tab[i]->name, tab[i]->comment);
		i++;
	}
}
