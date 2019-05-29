/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lem_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:02:14 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/29 21:29:16 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	(void)argv;
	data.rooms = NULL;
	data.map = NULL;
	data.max_paths = 0;
	data.paths = NULL;
	data.path_nb = 0;
	data.input = NULL;
	data.read = NULL;
	(data.output).index = 0;
	data.ant_tab = NULL;
	data.color = 1;
	if (!li_get_input(&data, &(data.input)))
	{
		li_error();
	}
	ft_putstr("\"li_get_input\" OK !\n");
	/*else*/ if (!li_parse_input(&data))
	{
		li_error();
	}
	ft_putstr("\"li_parse_input\" OK !\n");
	/*else*/
//	{
//		li_print_map(&data);
//	}
	if (li_bhandari(&data))
	{
		li_print_paths(&data);
		ft_putstr("\"data->path_nb\" vaut ");
		ft_putnbr((int)data.path_nb);
		ft_putchar('\n');
	}
	if (li_build_routes(&data))
	{
		li_print_routes(&data);
	}
	li_eval_routes(&data);
	li_move_ants(&data);
	li_print_output(&data);
	ft_putstr("data.ants : ");
	ft_putnbr((int)data.ants);
	ft_putchar('\n');
	ft_putstr("data.best_route : ");
	ft_putnbr((int)data.best_route);
	ft_putchar('\n');
	ft_putstr("data.best_steps : ");
	ft_putnbr((int)data.best_steps);
	ft_putchar('\n');
	return (0);
}
