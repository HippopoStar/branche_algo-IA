/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 01:21:46 by lcabanes          #+#    #+#             */
/*   Updated: 2019/01/19 03:37:17 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_aux_checker(t_ps *data, t_input **input)
{
	t_input	*tmp;

	while ((*input))
	{
		if (data->verbose == 1)
		{
			ps_display_stacks(data->stacks);
			ft_putstr((*input)->inst);
			ft_putchar('\n');
		}
		ps_apply_moves(data->stacks, (*input)->inst);
		tmp = (*input);
		(*input) = (*input)->next;
		free(tmp);
	}
	if (data->verbose == 1)
	{
		ps_display_stacks(data->stacks);
	}
}

void	ft_checker(t_ps *data, t_input **input, int argc, char **argv)
{
	if (ps_parse(data, argc, argv) == 0 || ps_get_input(input) == 0)
	{
		ps_display_error();
	}
	else
	{
		ft_aux_checker(data, input);
		ft_putstr((ps_is_ready_to_go(data)) ? "OK\n" : "KO\n");
	}
}

int		main(int argc, char **argv)
{
	t_ps	data;
	t_input	*input;

	data.verbose = (argc > 2 && !ft_strcmp(*(argv + 1), "-v")) ? 1 : 0;
	*(data.stacks + 0) = NULL;
	*(data.stacks + 1) = NULL;
	input = NULL;
	if (argc - data.verbose < 2)
	{
		ps_display_error();
	}
	else
	{
		ft_checker(&data, &input, argc - data.verbose, argv + data.verbose);
	}
	return (0);
}
