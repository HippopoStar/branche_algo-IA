/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 01:24:20 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/23 23:10:16 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_ps *data, int argc, char **argv)
{
	if (ps_parse(data, argc, argv) == 0)
		ps_display_error();
	else
	{
		if (!(ps_are_sorted(data)))
		{
			if (data->length == 2)
			{
				ps_print_ando(data, "sa");
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
	ps_shorten(&(data->input));
}

/*
** Nul besoin de proceder a l'initialisation
** " data.current_input = NULL "
** (voir la fonction "ps_print_ando" du fichier "ps_apply_moves")
*/

int		main(int argc, char **argv)
{
	t_ps	data;

	data.verbose = 0;
	*(data.stacks + 0) = NULL;
	*(data.stacks + 1) = NULL;
	data.input = NULL;
	if (argc > 1)
	{
		ft_push_swap(&data, argc, argv);
	}
	ps_liberate_stacks(data.stacks);
	return (0);
}
