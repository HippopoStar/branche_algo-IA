/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 01:21:46 by lcabanes          #+#    #+#             */
/*   Updated: 2019/02/09 15:46:55 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_aux_checker(t_ps *data, t_input **input, int *count)
{
	t_input	*tmp;

	*count = 0;
	while ((*input))
	{
		(*count)++;
		if (data->verbose == 3)
		{
			ps_display_stacks(data->stacks);
			ft_putendl((*input)->inst);
		}
		ps_apply_moves(data->stacks, (*input)->inst);
		tmp = (*input);
		(*input) = (*input)->next;
		free(tmp);
	}
	if (data->verbose > 1)
	{
		ps_display_stacks(data->stacks);
		ft_putchar('\n');
	}
}

void	ft_checker(t_ps *data, t_input **input, int argc, char **argv)
{
	int		count;

	if (ps_parse(data, argc, argv) == 0 || ps_get_input(input) == 0)
	{
		ps_display_error();
	}
	else
	{
		ft_aux_checker(data, input, &count);
		if (data->verbose > 0)
		{
			ft_putstr("Nombre total de coups : ");
			ft_putnbr(count);
			ft_putchar('\n');
		}
		ft_putstr((ps_is_ready_to_go(data)) ? "OK\n" : "KO\n");
	}
}

int		main(int argc, char **argv)
{
	t_ps	data;
	t_input	*input;
	int		option_wit;

	option_wit = ps_get_options(argc, argv, &data);
	*(data.stacks + 0) = NULL;
	*(data.stacks + 1) = NULL;
	input = NULL;
	if (argc - option_wit > 1)
	{
		ft_checker(&data, &input, argc - option_wit, argv + option_wit);
	}
	return (0);
}
