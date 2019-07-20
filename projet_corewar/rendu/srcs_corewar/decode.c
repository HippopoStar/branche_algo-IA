/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 18:16:05 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/20 22:34:41 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

short	is_ind_code(unsigned short *pc)
{
	short	ind;

	ind = read_2byte(*pc);
	(*pc) += 2;
	return (ind);
}

int		is_dir_code(unsigned short *pc, unsigned char op)
{
	static int	size[17] = {42, 4, 4, 0, 0, 0, 4, 4, 4, 2, 2, 2, 2, 4, 2, 2, 0};
	int			dir;

	if (size[op] > 2)
		dir = read_4byte(*pc);
	else
		dir = read_2byte(*pc);
	(*pc) += size[op];
	return (dir);
}

char	is_reg_code(unsigned short *pc)
{
	char	reg;

	reg = g_env.memory[INDEX(*pc)];
	(*pc)++;
	return (!IS_VALID_OP_CODE(reg) ? -1 : --reg);
}

int		*disassemble(unsigned char ocp, unsigned char op, int ac,\
		unsigned short *pc)
{
	int				*tab;
	int				i;
	char			av;
	unsigned short	tmp;

	i = 0;
	tmp = *pc;
	if (!(tab = ft_memalloc(sizeof(int) * ac)))
		kill(1, "Oh god, something went wrong with malloc()!");
	else
		while (i < ac)
		{
			av = isolate_2bit(ocp, i);
			if (av == REG_CODE && (tab[i] = is_reg_code(&tmp)) == -1)
			{
				ft_memdel((void **)&tab);
				return (NULL);
			}
			av == DIR_CODE ? tab[i] = is_dir_code(&tmp, op) : 0;
			av == IND_CODE ? tab[i] = is_ind_code(&tmp) : 0;
			i++;
		}
	*pc = tmp;
	return (tab);
}

/*
**	int		checksum(unsigned char ocp, unsigned char op, int i)
**	{
**		static char mask[17][3] = {{0, 0, 0}, LIVE, LD, ST, ADD, SUB,\
**			AND, OR, XOR, ZJMP, LDI, STI, FORK, LLD, LLDI, LFORK, AFF};
**
**		return (ocp & mask[op][i]);
**	}
*/
