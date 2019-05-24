/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 01:21:46 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/24 17:19:57 by lcabanes         ###   ########.fr       */
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
		ps_reg_m(data->stacks, (*input)->inst, &(data->reg));
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
			ps_print_register(&(data->reg));
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
	int		option_wit;

	option_wit = ps_get_options(argc, argv, &data);
	(data.reg).sa = 0;
	(data.reg).sb = 0;
	(data.reg).ss = 0;
	(data.reg).pa = 0;
	(data.reg).pb = 0;
	(data.reg).ra = 0;
	(data.reg).rb = 0;
	(data.reg).rr = 0;
	(data.reg).rra = 0;
	(data.reg).rrb = 0;
	(data.reg).rrr = 0;
	*(data.stacks + 0) = NULL;
	*(data.stacks + 1) = NULL;
	data.sorted = NULL;
	data.input = NULL;
	if (argc - option_wit > 1)
	{
		ft_checker(&data, &(data.input), argc - option_wit, argv + option_wit);
	}
	ps_liberate_stacks_and_sorted(&data);
	return (0);
}
