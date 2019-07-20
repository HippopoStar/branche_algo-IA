/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 09:31:12 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/20 23:28:01 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	verbose(t_champ *champ, int token)
{
	if (g_env.option & OPT_C)
		ft_printf("P %s%4i"RESET, g_color[champ->token], champ->id);
	else
		ft_printf("P %4i", champ->id);
	ft_printf(" | live %i\n", token);
}

void		live(t_champ *champ, int *av, unsigned char ocp, unsigned short pc)
{
	int	token;

	(void)av;
	(void)ocp;
	(void)pc;
	token = -is_dir_code(&champ->pc, 0x1);
	champ->live++;
	if (token >= 1 && token <= MAX_PLAYERS)
		g_env.last_alive = token;
	if (g_env.option & OPT_V)
		verbose(champ, -token);
}

/*
**	if (champ->token == token)
**		g_env.last_alive = champ->token;
*/
