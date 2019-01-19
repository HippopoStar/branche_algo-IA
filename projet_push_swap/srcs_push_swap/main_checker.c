/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 01:21:46 by lcabanes          #+#    #+#             */
/*   Updated: 2019/01/19 02:10:48 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checker(t_ps *data, int argc, char **argv)
{
	t_input		*input;

	input = NULL;
	if (ps_parse(data, argc, argv) == 0 || ps_get_input(&input) == 0)
	{
		ps_display_error();
	}
	else
	{
		ps_display_stacks(data->stacks);
		ft_putstr(input->inst);
	}
}

int		main(int argc, char **argv)
{
	t_ps	data;

	data.verbose = (argc > 2 && !ft_strcmp(*(argv + 1), "-v")) ? 1 : 0;
	*(data->stacks + 0) = NULL;
	*(data->stacks + 1) = NULL;
	if (argc - data.verbose < 2)
	{
		ps_display_error();
	}
	else
	{
		ft_checker(&data, argc - data.verbose, argv + data.verbose);
	}
	return (0);
}
