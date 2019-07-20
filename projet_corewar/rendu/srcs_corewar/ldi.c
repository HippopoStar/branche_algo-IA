/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 22:48:57 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/20 22:18:29 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	verbose2(int *av, unsigned char ocp, unsigned int *r,\
		unsigned short pc)
{
	ft_printf("       | -> load from ");
	if (isolate_2bit(ocp, 0) == IND_CODE)
		ft_printf("%hi + ", read_2byte(pc + (av[0] % IDX_MOD)));
	else if (ocp & 0x80)
		ft_printf("%i + ", av[0]);
	else
		ft_printf("%i + ", r[av[0]]);
	if (ocp & 0x20)
		ft_printf("%i = ", av[1]);
	else
		ft_printf("%i = ", r[av[1]]);
}

static void	verbose1(t_champ *champ, int *av, unsigned char ocp,\
		unsigned short pc)
{
	if (g_env.option & OPT_C)
		ft_printf("P %s%4i"RESET" | ldi ", g_color[champ->token], champ->id);
	else
		ft_printf("P %4i | ldi ", champ->id);
	if (isolate_2bit(ocp, 0) == IND_CODE)
		ft_printf("%hi ", read_2byte(pc + (av[0] % IDX_MOD)));
	else if (ocp & 0x80)
		ft_printf("%i ", av[0]);
	else
		ft_printf("%i ", champ->r[av[0]]);
	if (ocp & 0x20)
		ft_printf("%i ", av[1]);
	else
		ft_printf("%i ", champ->r[av[1]]);
	ft_printf("r%i\n", (av[2] + 1));
}

void		ldi(t_champ *champ, int *av, unsigned char ocp, unsigned short pc)
{
	int	i;

	if (av[2] < 0)
		return ;
	i = 0;
	if (isolate_2bit(ocp, 0) == IND_CODE)
		i = read_2byte(pc + (av[0] % IDX_MOD));
	else if (ocp & 0x80)
		i = av[0];
	else if (av[0] > -1)
		i = champ->r[av[0]];
	if (ocp & 0x20)
		i += av[1];
	else if (av[1] > -1)
		i += champ->r[av[1]];
	champ->r[av[2]] = read_4byte(pc + (i % IDX_MOD));
	if (g_env.option & OPT_V)
	{
		verbose1(champ, av, ocp, pc);
		verbose2(av, ocp, champ->r, pc);
		ft_printf("%i (with pc and mod %i)\n", i, INDEX(pc + (i % IDX_MOD)));
	}
}
