/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 02:32:14 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/20 20:47:58 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	verbose(int token, int id, unsigned char ocp, int *av)
{
	if (g_env.option & OPT_C)
		ft_printf("P %s%4i"RESET" | st r%i ", g_color[token], id, (av[0] + 1));
	else
		ft_printf("P %4i | st r%i ", id, (av[0] + 1));
	if (ocp & 0x20)
		ft_printf("%i\n", av[1]);
	else
		ft_printf("%i\n", (av[1] + 1));
}

void		st(t_champ *champ, int *av, unsigned char ocp, unsigned short pc)
{
	if (av[0] < 0)
		return ;
	if (ocp & 0x20)
		write_memory(pc + (av[1] % IDX_MOD), champ->r[av[0]]);
	else if (av[1] > -1)
		champ->r[av[1]] = champ->r[av[0]];
	if (g_env.option & OPT_V)
		verbose(champ->token, champ->id, ocp, av);
}
