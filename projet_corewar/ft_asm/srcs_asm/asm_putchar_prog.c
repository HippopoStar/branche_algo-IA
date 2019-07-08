/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_putchar_prog.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:31:07 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/08 17:31:09 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

/*
** #include <stdio.h>
**	printf("c : %hhx\n", c);
**	printf("s : %hx\n", s);
**	printf("u : %x\n", u);
*/

int		asm_putchar_prog(char *prog, size_t *pos, char c)
{
	if ((*pos) < CHAMP_MAX_SIZE)
	{
		*(prog + (*pos)) = c;
		(*pos)++;
		return (1);
	}
	else
	{
		return (0);
	}
}

int		asm_putusint_prog(char *prog, size_t *pos, unsigned short int s)
{
	if (asm_putchar_prog(prog, pos, (char)(s >> 8))
			&& asm_putchar_prog(prog, pos, (char)s))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int		asm_putuint_prog(char *prog, size_t *pos, unsigned int u)
{
	if (asm_putchar_prog(prog, pos, (char)(u >> 24))
			&& asm_putchar_prog(prog, pos, (char)(u >> 16))
			&& asm_putchar_prog(prog, pos, (char)(u >> 8))
			&& asm_putchar_prog(prog, pos, (char)u))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
