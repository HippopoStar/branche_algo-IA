/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:49:14 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/20 22:34:43 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

short	read_2byte(unsigned short i)
{
	short	val;

	val = g_env.memory[INDEX(i)] << 8;
	val |= g_env.memory[INDEX(i + 1)];
	return (val);
}

int		read_4byte(unsigned short i)
{
	int	val;

	val = g_env.memory[INDEX(i)] << 24;
	val |= g_env.memory[INDEX(i + 1)] << 16;
	val |= g_env.memory[INDEX(i + 2)] << 8;
	val |= g_env.memory[INDEX(i + 3)];
	return (val);
}

void	write_memory(unsigned short i, int val)
{
	g_env.memory[INDEX(i)] = val >> 24;
	g_env.memory[INDEX(i + 1)] = val >> 16;
	g_env.memory[INDEX(i + 2)] = val >> 8;
	g_env.memory[INDEX(i + 3)] = val;
}

int		isolate_2bit(unsigned char ocp, int i)
{
	static char		mask[3] = {0xc0, 0x30, 0xc};
	static int		padding[3] = {6, 4, 2};
	int				type;

	return (type = (ocp & mask[i]) >> padding[i]);
}

int		checksum(unsigned char ocp, unsigned char op, int ac)
{
	static unsigned char	mask[17][3][3] =\
	{{{0}, {0}, {0}}, LIVE, LD, ST, ADD, SUB,\
		AND, OR, XOR, ZJMP, LDI, STI, FORK, LLD, LLDI, LFORK, AFF};
	static unsigned char	detach[3] = {0xc0, 0x30, 0x0c};
	int						i;
	int						j;

	i = 0;
	while (i < ac)
	{
		if ((ocp & detach[i]) == 0)
			return (0);
		j = 0;
		while (j < 3)
		{
			if ((ocp & detach[i]) == mask[op][i][j])
			{
				ocp &= ~detach[i];
				break ;
			}
			j++;
		}
		i++;
	}
	return (ocp == 0);
}

/*
**	printf("i'm in read_4byte, this is (int)memory[%i] %.2x %.2x %.2x %.2x\n",\
**			INDEX(i), g_env.memory[INDEX(i)], g_env.memory[INDEX(i + 1)],\
**			g_env.memory[INDEX(i + 2)], g_env.memory[INDEX(i + 3)]);
*/

/*
**	printf("i'm in read_2byte, this is (short)memory[%i] %.2x %.2x\n",\
**			INDEX(i), g_env.memory[INDEX(i)], g_env.memory[INDEX(i + 1)]);
*/
