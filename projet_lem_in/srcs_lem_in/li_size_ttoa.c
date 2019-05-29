/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 18:31:04 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/29 21:20:14 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Un 'int' positif ecrit en base 10
** comporte au maximum le nombre de caracteres compris dans '2147483647'
** soit 10 caracteres
** Ajoutons a cela un caratere pour un ' ' (sauf 1ere fourmi de sa ligne),
** un autre pour un 'L',
** et enfin un autre pour un '-' (qui viendra en fin de chaine de la fourmi,
** pour venir se placer devant l'identifiant de la salle correspondante)
** et cela nous fait '10 + 3 + 1 = 14' caracteres necessaires
**
** Par ailleurs, on sait que l'identifiant de la fourmi est un nombre
** strictement positif
*/

void	li_color_ants(size_t ant, char to_print[24], size_t gap)
{
	*(to_print + 2) = '\033';
	*(to_print + 3) = '[';
	*(to_print + 4) = '3';
	*(to_print + 5) = '1' + (ant % 7);
	*(to_print + 6) = 'm';
	*(to_print + 7 + gap) = '\033';
	*(to_print + 8 + gap) = '[';
	*(to_print + 9 + gap) = '0';
	*(to_print + 10 + gap) = '0';
	*(to_print + 11 + gap) = 'm';
}

void	li_size_ttoa(size_t ant, char to_print[24], int color)
{
	size_t	tmp_ant;
	size_t	last_digit_pos;
	size_t	gap;

	*(to_print + 0) = ' ';
	*(to_print + 1) = 'L';
	tmp_ant = ant;
	last_digit_pos = color ? 7 : 2;
	while ((tmp_ant = tmp_ant / 10) > 0)
	{
		last_digit_pos++;
	}
	gap = last_digit_pos - 6;
	*(to_print + last_digit_pos + (color ? 6 : 1)) = '-';
	*(to_print + last_digit_pos + (color ? 7 : 2)) = '\0';
	tmp_ant = ant;
	while (tmp_ant > 0)
	{
		*(to_print + last_digit_pos) = '0' + (tmp_ant % 10);
		tmp_ant = tmp_ant / 10;
		last_digit_pos--;
	}
	if (color)
		li_color_ants(ant, to_print, gap);
}
