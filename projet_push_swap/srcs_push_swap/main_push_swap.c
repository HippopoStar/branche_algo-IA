/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 01:24:20 by lcabanes          #+#    #+#             */
/*   Updated: 2019/01/19 04:11:25 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_ps *data, int argc, char **argv)
{
	if (ps_parse(data, argc, argv) == 0)
	{
		ps_display_error();
	}
	else
	{
		ps_sort_bis(data);
	}
}

int		main(int argc, char **argv)
{
	t_ps	data;

	data.verbose = (argc > 2 && !ft_strcmp(*(argv + 1), "-v")) ? 1 : 0;
	*(data.stacks + 0) = NULL;
	*(data.stacks + 1) = NULL;
	if (argc - data.verbose < 2)
	{
		ps_display_error();
	}
	else
	{
		ft_push_swap(&data, argc - data.verbose, argv + data.verbose);
	}
	return (0);
}
