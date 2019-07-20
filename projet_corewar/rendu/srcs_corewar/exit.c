/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 18:59:08 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/20 21:56:52 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	free_all(void)
{
	t_champ	*tmp;

	ft_strdel((char **)&g_env.memory);
	ft_memdel((void **)&g_env.tab);
	if (!g_champ)
		return ;
	g_champ = *g_champ->start;
	ft_memdel((void **)&g_champ->n);
	ft_memdel((void **)&g_champ->start);
	ft_memdel((void **)&g_champ->last);
	while (g_champ)
	{
		tmp = g_champ;
		ft_memdel((void **)&g_champ->r);
		ft_memdel((void **)&g_champ->av);
		ft_strdel(&g_champ->name);
		ft_strdel(&g_champ->comment);
		ft_memdel((void **)&g_champ->process);
		g_champ = g_champ->next;
		ft_memdel((void **)&tmp);
	}
}

void	winner(t_champ **tab, int token)
{
	if (g_env.option & OPT_C)
	{
		if (!token)
			ft_printf("Contestant %s%i"RESET", \"%s%s"RESET"\", has won !\n",\
					g_color[tab[0]->token], 1,\
					g_color[tab[0]->token], tab[0]->name);
		else
			ft_printf("Contestant %s%i"RESET", \"%s%s"RESET"\", has won !\n",\
					g_color[tab[token - 1]->token], token,\
					g_color[tab[token - 1]->token], tab[token - 1]->name);
	}
	else
	{
		if (!token)
			ft_printf("Contestant %i, \"%s\", has won !\n", 1, tab[0]->name);
		else
			ft_printf("Contestant %i, \"%s\", has won !\n",\
					token, tab[token - 1]->name);
	}
	free_all();
	exit(EXIT_SUCCESS);
}

void	dump(void)
{
	int	i;

	i = 0;
	while (i < 4096)
	{
		(i % 64) == 0 ? ft_printf("\n") : ft_printf(" ");
		(i % 64) == 0 ? ft_printf("0x%04x : ",\
				(unsigned short)((unsigned long long)\
					(&g_env.memory[i] - g_env.memory))) : 0;
		ft_printf("%.2x", g_env.memory[i]);
		i++;
	}
	ft_printf("\n");
	free_all();
	exit(EXIT_SUCCESS);
}

void	kill(int error, char *str)
{
	if (error)
		ft_printf("%s\n%s\n", str, strerror(errno));
	else if (str)
		ft_printf("%s\n", str);
	else
		usage();
	free_all();
	exit(EXIT_FAILURE);
}
