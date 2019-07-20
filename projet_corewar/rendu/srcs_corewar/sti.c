/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:42:49 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/20 22:18:14 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	verbose2(int *av, char ocp, unsigned int *r, unsigned short pc)
{
	ft_printf("       | -> store to ");
	if (isolate_2bit(ocp, 0) == IND_CODE)
		ft_printf("%i + ", read_2byte(pc + (av[1] % IDX_MOD)));
	else if (ocp & 0x20)
		ft_printf("%i + ", av[1]);
	else
		ft_printf("%i + ", r[av[1]]);
	if (ocp & 0x8)
		ft_printf("%i = ", av[2]);
	else
		ft_printf("%i = ", r[av[2]]);
}

static void	verbose1(t_champ *champ, int *av, char ocp, unsigned short pc)
{
	if (g_env.option & OPT_C)
		ft_printf("P %s%4i"RESET" | sti r%i ",\
				g_color[champ->token], champ->id, (av[0] + 1));
	else
		ft_printf("P %4i | sti r%i ", champ->id, (av[0] + 1));
	if (isolate_2bit(ocp, 0) == IND_CODE)
		ft_printf("%i ", read_2byte(pc + (av[1] % IDX_MOD)));
	else if (ocp & 0x20)
		ft_printf("%i ", av[1]);
	else
		ft_printf("%i ", champ->r[av[1]]);
	if (ocp & 0x8)
		ft_printf("%i\n", av[2]);
	else
		ft_printf("%i\n", champ->r[av[2]]);
}

void		sti(t_champ *champ, int *av, unsigned char ocp, unsigned short pc)
{
	int	i;

	if (av[0] < 0)
		return ;
	i = 0;
	if (isolate_2bit(ocp, 1) == IND_CODE)
		i = read_2byte(pc + (av[1] % IDX_MOD));
	else if (ocp & 0x20)
		i = av[1];
	else if (av[1] > -1)
		i = champ->r[av[1]];
	if (ocp & 0x8)
		i += av[2];
	else if (av[2] > -1)
		i += champ->r[av[2]];
	write_memory(pc + (i % IDX_MOD), champ->r[av[0]]);
	if (g_env.option & OPT_V)
	{
		verbose1(champ, av, ocp, pc);
		verbose2(av, ocp, champ->r, pc);
		ft_printf("%i (with pc and mod %i)\n",\
				i, INDEX(pc + (i % IDX_MOD)));
	}
}
