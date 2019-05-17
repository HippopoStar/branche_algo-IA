/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_power_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 13:54:02 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/17 16:52:23 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** L'execution de 'ps_position' se passe en partant du postulat de depart
** que la pile 'A' n'est pas vide, et que le nombre recherche se trouve bel
** et bien dans la liste triee elaboree plus tot dans le programme
*/

size_t	ps_get_next_power_of_two(t_ps *data)
{
	size_t	i;

	i = 1;
	while (i < data->length)
	{
		i = 2 * i;
	}
	return (i);
}

void	ps_aux_aux_sort_power_two(t_ps *data, size_t power_two, size_t i)
{
	while (i > 0)
	{
		if ((2 * power_two) < data->length)
		{
			ps_print_ando(data, "rra");
			i--;
		}
		while (i > 0 && (i % power_two != data->length % power_two))
		{
			ps_print_ando(data, "rra");
			i--;
		}
		if (power_two == 2)
			ps_swap_instructions(data);
		if (i > 0)
		{
			ps_print_ando(data, "pa");
			i--;
		}
		while (i > 0 && (i % power_two != data->length % power_two))
		{
			ps_print_ando(data, "pa");
			i--;
		}
	}
}

/*
** La variable 'to_add' vaut la difference entre la valeur de la puissance
** de 2 superieure ou egale au nombre d'elements de la pile,
** et le nombre d'elements de la pile
**
** A l'appel de la fonction 'ps_aux_aux_sort_power_two',
** la variable 'i' vaut la difference entre le nombre d'elements de la pile,
** et la valeur de la plus grande puissance de 2 strictement inferieure
** au nombre d'elements de la pile
** Elle vaut le nombre d'elements de la pile lors des appels suivants
** Elle permet d'eviter d'effectuer une rotation complete (avec des 'rra')
** de la pile de gauche lors de la premiere iteration de l'algorithme
*/

void	ps_aux_sort_power_two(t_ps *data, size_t to_add, size_t power_two)
{
	size_t	i;

	while (power_two > 4)
	{
		i = 0;
		while (i < data->length)
		{
			if (*(data->stacks + 0) != NULL && ((ps_position(data) + to_add) \
						% (power_two)) < (power_two / 2))
			{
				ps_print_ando(data, "pb");
			}
			else
			{
				ps_print_ando(data, "ra");
			}
			i++;
		}
		power_two = power_two / 2;
		i = ((2 * power_two) < data->length) ? i : (i - power_two);
		(power_two > 4) ? ps_aux_aux_sort_power_two(data, power_two, i) : ps_sort_power_two_alamano(data);
	}
}

void	ps_sort_power_two(t_ps *data)
{
	size_t	power_two;
	size_t	to_add;

	power_two = ps_get_next_power_of_two(data);
	to_add = power_two - data->length;
	ps_aux_sort_power_two(data, to_add, power_two);
}
