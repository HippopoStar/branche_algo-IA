/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 01:24:20 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/24 17:21:03 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Retrait de l'appel 'ps_shorten(&(data->input));' du fichier 'ps_shorten.c'
** en derniere instruction de la fonction 'ft_push_swap'
** (pour les raisons specifiees dans 'ps_shorten.c' et 'ps_apply_moves.c')
*/

int		ft_push_swap(t_ps *data, int argc, char **argv)
{
	if (ps_parse(data, argc, argv) == 0)
		return (0);
	else
	{
		if (!(ps_are_sorted(data)))
		{
			if (data->length == 2)
			{
				ps_print_and_do(data, "sa");
			}
			else if (data->length == 3)
			{
				ps_sort_three(data);
			}
			else if (data->length < 6)
			{
				ps_sort_five(data);
			}
			else
			{
				ps_sort_power_two(data);
			}
		}
	}
	return (1);
}

/*
** Nul besoin de proceder a l'initialisation
** " data.current_input = NULL "
** (voir la fonction "ps_mem_and_do" du fichier "ps_apply_moves")
**
** Le seul cas dans lequel la valeur de retour de 'ft_push_swap' vaut '0'
** est lorsque 'ps_parse' dans cette derniere renvoie '0'
*/

int		main(int argc, char **argv)
{
	t_ps	data;
	int		ret_val;

	data.verbose = 0;
	*(data.stacks + 0) = NULL;
	*(data.stacks + 1) = NULL;
	data.sorted = NULL;
	data.input = NULL;
	if (argc > 1)
	{
		ret_val = ft_push_swap(&data, argc, argv);
		if (ret_val == 0)
		{
			ps_display_error();
		}
	}
	ps_liberate_stacks_and_sorted(&data);
	return (0);
}
